# 1 为什么要告别 for 循环

在接触计算数学初期，我们肯定写过这样的 Python 程序：功能正确，但运行速度慢得让人怀疑人生。检查代码，发现满屏都是 for 循环——这正是性能瓶颈的元凶。

Python 的 for 循环慢，是因为 Python 是动态类型语言，循环中每次迭代都要进行类型检查和对象操作，开销巨大，当我们写 `for i in range(1000000)` 时，可怜的 Python 解释器要重复执行一百万次循环体的解释工作。而 C 语言这样的编译型语言，循环体已经被提前编译成机器码，执行时只是简单的跳转指令。后面介绍的 NumPy 就是将运算下放到预编译的 C 层，一次性处理整个数组。

**向量化编程** (**Vectorized Programming**) 的核心思想是：把循环操作转化为对整个数据集的批量运算。这就像从“逐个搬运砖块”升级为“使用传送带批量运输”。虽然传送带的建设需要投入，但一旦建成，效率提升是显著的。接下来我们就来看一看，这个“传送带”究竟是怎样建成和使用的。

（注：本文着重探讨向量化编程，而对于更广泛的张量编程，`einsum` 是高级但强大的工具，但本文限于篇幅并未涉及，未来希望有机会可以详细写一篇张量编程笔记）

# 2 NumPy 基础——向量化编程的基石

## 2-1 什么是 NumPy

NumPy (Numerical Python) 是 Python 科学计算的基础库，它引入了 ndarray (N 维数组) 这一核心数据结构。

与 Python 原生的 list 不同，ndarray 在内存中连续存储，且所有元素类型相同，这使得它可以调用底层 C 语言实现的函数进行高速运算。

```python
import numpy as np

# Python 原生列表
py_list = [1, 2, 3, 4, 5]

# NumPy 数组
np_array = np.array([1, 2, 3, 4, 5])

print(py_list * 2)      # 输出: [1, 2, 3, 4, 5, 1, 2, 3, 4, 5]（重复，不是乘法）
print(np_array * 2)     # 输出: [ 2  4  6  8 10]（真正的逐元素乘法）
```

## 2-2 创建数组的多种方式

```python
# 从列表创建
a = np.array([[1, 2, 3], [4, 5, 6]])

# 全零数组
zeros = np.zeros((3, 4)) # shape 为 (3,4)

# 全一数组
ones = np.ones((2, 3)) # shape 为 (2,3)

# 等差数列
arange = np.arange(0, 10, 2)  # [0, 2, 4, 6, 8]

# 线性空间
linspace = np.linspace(0, 1, 5)  # [0.  , 0.25, 0.5 , 0.75, 1.  ]

# 随机数组
random_arr = np.random.randn(3, 3)  # 标准正态分布
```

## 2-3 获取数组的维度与形状

如下面代码：

```python
arr = np.array([[1, 2, 3],
                [4, 5, 6]])

print(arr.shape)    # (2, 3): 2行3列
print(arr.ndim)     # 2: 二维数组
print(arr.size)     # 6: 元素总数
print(arr.dtype)    # int64: 数据类型
```

数组的维度、形状在向量化编程中是十分重要的指标！

# 3 向量化运算

## 3-1 逐元素运算 (Element-wise Operations)

这是向量化最基础的形式：对数组中的每个元素执行相同的操作。

```python
# 传统写法
def normalize_forloop(data):
    result = []
    for x in data:
        result.append((x - 10) / 5)
    return result

# 向量化写法
def normalize_vectorized(data):
    return (data - 10) / 5

data = np.random.randn(1000000)
result1 = normalize_forloop(data)
result2 = normalize_vectorized(data)
```

在作者的测试环境中：使用 for 循环方法约 200ms，而使用向量化方法约 5ms，快 40 倍！

## 3-2 聚合运算 (Reduction Operations)

```python
data = np.random.randn(1000, 100)

# 求和
total = np.sum(data)           # 所有元素之和
row_sums = np.sum(data, axis=1)  # 每行之和
col_sums = np.sum(data, axis=0)  # 每列之和

# 其他聚合函数
mean_val = np.mean(data)
max_val = np.max(data)
min_val = np.min(data)

# 累积操作
cumsum = np.cumsum(data)  # 累积和
```

通过上面的聚合运算，也避免了 for 循环的滥用。

## 3-3 条件运算与掩码

```python
data = np.array([1, -2, 3, -4, 5, -6])

# 传统写法
positive_forloop = []
for x in data:
    if x > 0:
        positive_forloop.append(x)

# 向量化写法
positive_vec = data[data > 0]

# 条件替换
# 传统写法
clipped = []
for x in data:
    if x < 0:
        clipped.append(0)
    else:
        clipped.append(x)

# 向量化写法
clipped_vec = np.where(data < 0, 0, data)

# 逻辑运算
a = np.array([1, 2, 3, 4])
b = np.array([4, 3, 2, 1])

print(a > 2)       # [False False  True  True]
print(a == b)      # [False False False False]
```

# 4 广播机制——让不同形状的数组“对得上”

起初学习编程总会认为：两个数组要做运算，形状必须一模一样。

其实不是。NumPy 里有一套形状对齐规则，叫做**广播**。它的本质只有一句话：

> 在不真正复制数据的前提下，把“小数组”虚拟地拉长 / 铺平，使其能和“大数组”做逐元素运算。

## 4-1 三条规则

假设要对 `A` 和 `B` 做逐元素运算，那么有三条规则如下：
1. 维数不够，左边补 1：如果 `A.ndim != B.ndim`，在维度少的那一边前面补 1。例如：`(3,)` → `(1, 3)` 
2. 从右往左比：先比最后一个维度，再比倒数第二个，依此类推。
3. 某一维是 1，就能拉长。即两维相容，当且仅当维度大小相等或其中一个是 1。结果是取较大值。如果既不相等、又都不是 1，则报错。

> 注意：广播不是“复制数组”，而是通过 stride (步长) 让同一份数据在逻辑上重复出现，所以又快又省内存。

## 4-2 最基础的两个例子

### 例 1：标量广播

```python
import numpy as np

a = np.array([1, 2, 3])
b = 10

print(a + b)   # [11 12 13]
```

本质就是标量被广播成 `[10, 10, 10]` 

### 例 2：行向量广播到矩阵

```python
M = np.array([[1, 2, 3],
              [4, 5, 6]])
row = np.array([10, 20, 30])   # shape (3,)

M + row
```

对齐过程如下：

```python
M: (2, 3)
row: (3,) → (1, 3) → (2, 3)
```

结果如下：

```python
[[11 22 33]
 [14 25 36]]
```

注意：如果 `row` 是 `[10,20,30,40]`，则尾部维度分别为 3 和 4，既不等也不是 1，就会报错。

## 4-3 计算数学里的广播
### 例 3：一阶差商 (divided difference)

一阶差商定义：$f[x_i, x_j] = \dfrac{f(x_j) - f(x_i)}{x_j - x_i}$ 

给定节点：

```python
x = np.array([0.0, 1.0, 2.0, 4.0])
y = np.array([1.0, 3.0, 7.0, 15.0])
```

我们要算所有两两组合的差商，就可以用广播构造“外矩阵”：

```python
num = y[:, None] - y[None, :]
den = x[:, None] - x[None, :]

first_order = num / den
```

结果 `first_order` 是 `4×4` 矩阵，其中：
- 对角线上是 `0/0` (需要后面 mask 掉)
- `(i,j)` 位置就是 `f[x_i, x_j]` 

这个代码很妙，首先我们来讲一下 `None` 的用法。

在普通 Python 中：`None` 是“空”，而在 NumPy 索引中：`None` 是 `np.newaxis` 的“快捷方式”，用于**增加一个新维度**。

比如说，对于 `y = np.array([2, 4, 6, 8])`：
- 当执行 `print(y[None, :])` 时，输出 `[[2, 4, 6, 8]]`，形状为 `(1,4)` 
- 当执行 `print(y[:, None])` 时，输出 `[[2] [4] [6] [8]]`，形状为 `(4,1)` 
- 当执行 `print(y[None, None, :])` 时，输出 `[[[2 4 6 8]]]`，形状为 `(1,1,4)` 
- 当执行 `print(y[None, :, None])` 时，输出 `[[[2] [4] [6] [8]]]`，形状为 `(1,4,1)` 
- 当执行 `print(y[:, None, None])` 时，输出 `[[[2]] [[4]] [[6]] [[8]]]`，形状为 `(4,1,1)` 

所以 `None` 就在对应的轴上新增了一个维度。于是我们就可以分析整体的过程了：

刚开始 `x = np.array([0.0, 1.0, 2.0, 4.0])`，`y = np.array([1.0, 3.0, 7.0, 15.0])` 为差商节点。

`num = y[:, None] - y[None, :]`，这一句话中 `y[:, None]` 的形状为 `(4,1)`，`y[None, :]` 的形状为 `(1,4)`，通过广播机制，`num` 的形状为 `(4,4)`，且 `num[i,j]` 的值为 `y[i] - y[j]` 

同理 `den = x[:, None] - x[None, :]` 中 `den` 的形状亦为 `(4,4)`，且 `den[i,j]` 的值为 `x[i] - x[j]` 

这样 `first_order = num / den` 得到的 `first_order` 的形状为 `(4,4)`，且 `first_order[i,j]` 的值为 $f[x_i, x_j] = \dfrac{f(x_j) - f(x_i)}{x_j - x_i}$，这样我们就计算出来了任意两点的一阶差商。

短短三行代码，却用到了广播机制、逐元素操作、`None` 的知识，并高效地求出了一阶差商，或许这就是 Python 的魅力之一吧！

像这种 `(n,1)` 和 `(1,n)` 最后得到 `(n,n)` 的模式，在数值计算里极其常见。

### 例 4：前向差分与中心差分

对等距节点：

```python
x = np.linspace(0, 1, 1000)
y = np.sin(x)
h = x[1] - x[0]
```

前向差分：

```python
dy_forward = (y[1:] - y[:-1]) / h
```

中心差分：

```python
dy_center = (y[2:] - y[:-2]) / (2 * h)
```

仅一行代码就可以高效实现，注意这里没有广播，但思想一致：切片相减，就相当于隐式对齐。

### 例 5：拉格朗日基函数 (极致的广播！)

拉格朗日基：$l_j(x) = \prod\limits_{k\not= j} \dfrac{x-x_k}{x_j-x_k}​$ ​

向量化写法：

```python
import numpy as np
x_nodes = np.array([0.0, 1.0, 2.0, 3.0])
x_query = np.array([0.5, 1.5, 2.5])

XQ = x_query[:, None]        # 查询点 shape:(3,1)
XN = x_nodes[None, :]        # 节点 shape:(1,4)

numer = XQ - XN              # shape:(3,4)
denom = x_nodes[None, :] - x_nodes[:, None]   # shape:(4,4)

# 对角位置分母为 0, 先填 1 避免除零 (巧妙地通过 bool 数组与 np.where 三目运算符实现)
denom = np.where(np.eye(4, dtype=bool), 1.0, denom) # shape:(4,4)

# 每个基函数要"跳过自己", 构造 bool 数组
mask = ~np.eye(4, dtype=bool)

numer_masked = np.where(mask, numer[:, None, :], 1.0)  # (3,4,4), 对角线放 1 就是为了跳过自己
denom_masked = np.where(mask, denom[None, :, :], 1.0)  # (1,4,4), 对角线放 1 就是为了跳过自己

# print(numer_masked)
# print(denom_masked)

ell = (numer_masked / denom_masked).prod(axis=2)       # (3,4)
print(ell)
```

这里解释一下最后三行，即为什么要新插入一个维度？

因为我们要构造一个三维数组，三个维度的含义分别是：
1. 第 0 维：查询点索引 (3个)
2. 第 1 维：当前基函数对应的节点 j (4 个)
3. 第 2 维：参与乘法的其他节点 k (4 个)

`numer` 原本只有查询点和节点两个维度，现在中间插入一个维度，就是为了给 j 留位置。

接下来 `np.where(mask, numer[:, None, :], 1.0)`，这里有一个**广播**的巧妙之处：
- `mask` 的形状是 `(4, 4)` 
- `numer[:, None, :]` 的形状是 `(3, 1, 4)` 

NumPy 广播规则：从右往左对齐维度，缺失的维度自动扩展。所以广播后：

```python
mask:              (3, 4, 4)
numer[:, None, :]: (3, 4, 4)
```

所以 `np.where` 逐元素判断：
- 如果 `mask[j, k]` 为 `True` (即 `j != k`)，取 `numer[i, j, k]` 的值 (即 `x_query[i] - x_nodes[k]`)
- 如果为 `False` (即 `j == k`)，取 `1.0` 

同理 `denom_masked = np.where(mask, denom[None, :, :], 1.0)`：
- 如果 `j != k`，取 `x_nodes[j] - x_nodes[k]` 
- 如果 `j == k`，取 `1.0` 

最后一步 `ell = (numer_masked / denom_masked).prod(axis=2)` 是两个 `(3, 4, 4)` 数组逐元素相除，得到 `(3, 4, 4)` 数组。

而 `.prod(axis=2)` 表示沿着第 2 个维度 (即 k 维度) 做乘积。即：

```python
ell[i, j] = numer_masked[i, j, 0] / denom_masked[i, j, 0]
          * numer_masked[i, j, 1] / denom_masked[i, j, 1]
          * numer_masked[i, j, 2] / denom_masked[i, j, 2]
          * numer_masked[i, j, 3] / denom_masked[i, j, 3]
```

因为 `j == k` 的位置都被替换成了 1，所以乘积中自动跳过了自己。

从这个例子我们可以看出，向量化编程的核心思维就是：把循环“拍平”成数组维度。

这个例子中，普通写法是三重循环：
- 外层：查询点 `i` 
- 中层：节点 `j` 
- 内层：其他节点 `k` 

而向量化的核心思路是：把每一层循环都变成一个维度，然后用数组运算一次性完成所有组合，这也就是为什么我们中间需要三维数组。

最后提一句，上面这种方式**可读性极其之差**，实际中也并不常用，但它可以极致锻炼我们向量化编程的思想，所以我认为还是有必要学习的。而对于本例，更常用的是“半向量化”的方式，兼顾可读性与性能：

```python
ell = np.ones((3, 4))
for j in range(4):
    mask = np.arange(4) != j
    ell[:, j] = ((x_query[:, None] - x_nodes[mask]) / 
                 (x_nodes[j] - x_nodes[mask])).prod(axis=1)
```

这样做不止可读性更强，也有一个很重要的原因是：全向量化会创建 `(3,4,4)` 的中间数组，但试想一下，如果查询点很多，节点也很多，中间数组就会爆炸到非常多个元素，内存直接爆掉 (广播导致内存溢出)。所以工程上更常用的是“分块向量化”或“半向量化”，而不是追求极致的一行代码。

本质上讲，“向量化编程思维”是在“空间换时间”——用内存中的冗余数据 (中间维度) 换取计算上的并行化。这在 GPU 上尤其重要，因为 GPU 的并行架构天然适合这种“批量运算”。

# 5 性能优化技巧

## 5-1 性能对比基准

我们可以用 `timeit` 做一组基准测试，对比 Python 列表推导式与 NumPy 向量化运算在相同数据规模下的性能差异。代码如下：

```python
import timeit
import numpy as np

def benchmark(func, *args):
    start = timeit.default_timer()
    result = func(*args)
    end = timeit.default_timer()
    return result, end - start

# 测试不同规模的数据
sizes = [100, 1000, 10000, 100000]
for size in sizes:
    data = np.random.randn(size)
    
    # 循环版本
    _, time_loop = benchmark(lambda: [x * 2 + 1 for x in data])
    
    # 向量化版本
    _, time_vec = benchmark(lambda: data * 2 + 1)
    
    print(f"Size {size:6d}: Loop {time_loop:.6f}s, Vectorized {time_vec:.6f}s, Speedup {time_loop/time_vec:.1f}x")
```

从结果可以清晰看到，随着数据量从 100 增长到 100000，向量化的优势显著扩大，在作者的测试环境中：
- 小数据量 (100)：向量化仅快 2.9 倍，此时 Python 循环的开销尚不明显。
- 中等数据量 (1000)：差距拉开至 13.4 倍，NumPy 的 C 语言底层优势开始显现。
- 大数据量 (10000~100000)：速度提升稳定在 17~21 倍，且趋势仍在上升。

原因很简单：Python 循环逐元素执行，每次迭代都有解释器开销；而 NumPy 将操作下放到预编译的 C/Fortran 层，一次性处理整个数组。

## 5-2 两个优化小技巧

**技巧1：预分配数组而非动态扩展** 

```python
# 不好的做法
result = []
for x in data:
    result.append(compute(x))

# 好的做法
result = np.empty_like(data)
for i, x in enumerate(data):
    result[i] = compute(x)

# 最好的做法 (如果可以向量化)
result = vectorized_compute(data)
```

**技巧2：使用 in-place 操作减少内存分配** 

**In-place operation** (**原地操作**) 指的是：在原有数据的内存地址上直接修改数据，而不创建新的内存空间来存放结果。它保证了：
1. 内存地址不变：操作前后，对象的内存地址保持不变
2. 无新对象产生：不分配新的内存块，直接在原内存上读写
3. 副作用：但操作会修改原始对象本身

所以，对于一个数组 `arr`，`arr = arr + 1` 是在创建新数组，`arr` 指向新内存，而 `arr += 1` 却在使用 in-place 操作进行原地修改，内存不变，这两种操作是有区别的。如下例：

```python
# 不好的写法：每次迭代都创建新数组
result = np.zeros(1000)
for i in range(1000):
    result = result + data[i]   # 每次迭代都创建新数组 (1000次)

# 好的写法：原地累加
result = np.zeros(1000)
for i in range(1000):
    result += data[i]           # 原地修改，不创建新数组
```

当然这个例子有些不恰当，因为最好的写法 `result = np.sum(data, axis=0)` 就搞定了，这里使用循环只是为了展示 in-place 的优势。

其实 in-place 操作减少的是结果数组的分配，而不是临时数组的分配。所以在实际使用中，它真正的价值是体现在内存而不是速度上的。具体来说：

假设你有一个超级大的 `(10000, 10000)` 的浮点数组 `arr`，占内存约 800 MB。如果你写 `arr = arr + 1`，那么就会创建新数组，内存峰值为 1.6 GB；而写成 `arr += 1` 使用 in-place 操作原地修改，则内存峰值仍为 800 MB。在内存紧张的机器上，前者可能直接 MemoryError，而后者则安然无恙。这时候 in-place 操作便是救命稻草。

## 5-3 避免常见的性能陷阱

**陷阱 1：在循环中调用 NumPy 函数** 

```python
# 不好
for i in range(100):
    result[i] = np.sin(data[i])

# 好
result = np.sin(data)
```

**陷阱 2：不必要的数组复制** 

```python
a = np.random.randn(1000)
b = a.copy()  # 如果需要独立副本, 则复制
c = a.view()  # 如果只是需要视图, 则不复制（共享内存）
```

**陷阱 3：使用 Python 原生操作处理 NumPy 数组** 

```python
# 不好
total = sum(a)  # Python原生sum，很慢
# 好
total = np.sum(a)  # NumPy的sum，很快
```

# 6 向量化编程的思维转变

从 for 循环到向量化运算，不仅是语法的改变，更是思维方式的转变：我们不再关心每个元素的处理细节，而是描述整个数据集的变换，并利用现代 CPU 的 SIMD 指令和底层 C/Fortran 优化库来实现从“逐个处理”到“批量处理”的蜕变。

所以以后我们在写 for 循环前，应该先思考是否能向量化。并合理利用 NumPy 的官方文档，积累常用操作的向量化版本。

最后再提一点，其实向量化编程并不是要完全抛弃循环，而是要在需要高性能时，知道如何用向量化来替代循环。在调试复杂逻辑时，小规模的 for 循环反而更清晰。毕竟工具没有优劣，关键是在合适的场景使用合适的方法。