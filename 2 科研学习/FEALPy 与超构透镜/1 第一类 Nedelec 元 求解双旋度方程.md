# 第1节：为什么不能直接硬算？

## 第1页：这个方程能"手算"吗？

$$\nabla \times (\nabla \times \mathbf{E}) - k^2 \mathbf{E} = \mathbf{f}$$

- 区域形状稍微复杂一点（不是矩形、不是圆），解析解就不存在
- 即使存在，也往往是一个无穷级数，实际用起来不方便

结论：只能数值求解。即不找“精确的公式”，而是找“足够好的近似”。

## 第2页：数值求解的第一步——离散化

**把"无限个未知数"变成"有限个未知数"。**

怎么变？把区域切成小块，每一小块上假设解是简单的（比如线性的），拼起来就是整体近似解。

这就是**有限元方法**的核心思想：

> **切小块 → 每块上猜一个简单形式 → 拼起来 → 得到近似解**

## 第3页：最朴素的想法——节点元

最简单的做法：把区域切成三角形，每个顶点放一个未知数。

比如算温度分布 $u(x,y)$，在每个顶点 $V_i$ 上放一个值 $u_i$，三角形内部用线性插值：

$$u_h(x,y) = \sum_{i} u_i \, \phi_i(x,y)$$

其中 $\phi_i$ 是“只在顶点 $V_i$ 上取 1，其他顶点取 0”的线性函数。

这个方法叫**节点元**（Lagrange 元），在热传导、弹性力学里非常成功。

**所以很自然地想：电场也能这么干吧？**

## 第4页：但是——电场是矢量，不是标量

温度只有一个数 $u$，但电场有三个分量：

$$\mathbf{E} = (E_x, E_y, E_z)$$

每个点要放 **3 个未知数**。

**节点元的做法**：每个顶点放 3 个值，分别对应三个分量。

看起来没什么问题，对吧？

## 第5页：问题出在哪？

**关键观察：两个三角形共享一条棱时，电场在这条棱上应该满足什么条件？**

来自物理的答案：**切向分量必须连续，法向分量可以跳。**

也就是说，沿棱方向的分量，两个单元上必须相等；但垂直于棱的方向，两边可以不一样。

**节点元做了什么？**

节点元在顶点上固定了三个分量的值，这会导致相邻单元在公共棱上的**法向分量也被强制连续**了。

> **节点元管得太宽了——它把不该锁死的法向分量也锁死了。**

## 第6页：用一个具体例子看为什么错

考虑两个三角形拼成一个矩形，公共棱是竖直的。

**设定坐标：**

- 矩形区域：$[0, 1] \times [0, 1]$
- 公共棱 $e$：从 $A = (0.5, 0)$ 到 $B = (0.5, 1)$，即 $x = 0.5$ 这条竖直线
- 左单元 $K_1$：三角形 $(0,0), (0.5,0), (0.5,1)$
- 右单元 $K_2$：三角形 $(0.5,0), (1,0), (0.5,1)$

**公共棱 $e$ 上的单位切向量和法向量：**

$$\mathbf{t}_e = (0, 1), \quad \mathbf{n}_e = (1, 0)$$

**物理要求：**

电场 $\mathbf{E}$ 在棱 $e$ 上满足：

- 切向分量连续：$\mathbf{E}|_{K_1} \cdot \mathbf{t}_e = \mathbf{E}|_{K_2} \cdot \mathbf{t}_e$，即 $E_y|_{K_1} = E_y|_{K_2}$
- 法向分量可跳：$\mathbf{E}|_{K_1} \cdot \mathbf{n}_e \neq \mathbf{E}|_{K_2} \cdot \mathbf{n}_e$，即 $E_x|_{K_1} \neq E_x|_{K_2}$ 是允许的

节点元做了什么？

节点元在顶点 $A = (0.5, 0)$ 和 $B = (0.5, 1)$ 上分别固定了 $E_x(A), E_y(A)$ 和 $E_x(B), E_y(B)$ 的值。

由于 $E_x$ 在 $A$ 和 $B$ 上被固定，而 $E_x$ 在单元内部是线性插值的，所以在整个棱 $e$ 上，$E_x$ 被唯一确定，且 $K_1$ 和 $K_2$ 上的 $E_x$ 在棱 $e$ 上**完全相同**。

**这等于强制了 $E_x|_{K_1} = E_x|_{K_2}$ 在整个棱 $e$ 上成立，即法向分量连续。**

但物理允许 $E_x|_{K_1} \neq E_x|_{K_2}$！

**结论：** 节点元把物理上允许跳变的法向分量 $E_x$ 也强制连续了。这等于给解加了额外的、物理上不存在的约束，导致数值解偏离真实解。

## 第7页：那怎么办？

**我们需要一种离散方式，让它：**

1. 自动保证**切向分量连续**（物理要求）
2. 允许**法向分量跳变**（物理允许）
3. 未知数个数合理（不能太多）

**答案：把自由度从"顶点"搬到"棱"上。**

这正是下一节要讲的——**棱元**。

# 第2节：用最少的数学解释"为什么节点元不行"

## 第1页：先复习——电场是矢量，有三个分量

**温度是一个数，电场是三个数。**

$$u(x,y) \quad \text{vs.} \quad \mathbf{E}(x,y) = (E_x, E_y, E_z)$$

每个点都要放3个未知数，这没问题。

**但问题不在"数量"，而在"连续性要求"。**

> 温度场要求：函数值连续（温度不会突变）。
> 电场要求：**切向连续，法向可以跳**。

这一页只做一件事：让读者意识到，电场和温度在"连续性"上要求不同。

---

## 第2页：什么叫"切向连续、法向可跳"？

**拿两个三角形拼在一起看。**

公共棱 $e$ 上，取两个方向：

- 切向量 $\mathbf{t}_e$：沿着棱的方向
- 法向量 $\mathbf{n}_e$：垂直于棱的方向

**物理要求：**

| 分量 | 要求 | 原因 |
|------|------|------|
| 切向 $E_t = \mathbf{E} \cdot \mathbf{t}_e$ | 必须连续 | 电场沿界面的切向分量由 Maxwell 方程导出，不能跳 |
| 法向 $E_n = \mathbf{E} \cdot \mathbf{n}_e$ | 可以跳 | 界面上有面电荷时，法向分量本来就会跳 |

**一句话：电场在跨过单元边界时，沿棱方向"粘住"，垂直方向"可以断开"。**

---

## 第3页：一张图看懂"节点元锁死了什么"

**画两个三角形拼成一个矩形，公共棱竖直。**

- 公共棱 $e$：从 $A$ 到 $B$，竖直方向
- 切向量 $\mathbf{t}_e = (0, 1)$（沿棱向上）
- 法向量 $\mathbf{n}_e = (1, 0)$（水平向右）

**物理允许的状态：**

- $E_y$（切向）：$K_1$ 和 $K_2$ 上必须相等
- $E_x$（法向）：$K_1$ 和 $K_2$ 上**可以**不相等

**节点元的做法：**

在顶点 $A$ 和 $B$ 上固定 $E_x, E_y$ 的值。

因为 $E_x$ 在单元内部是线性插值的，而 $A$、$B$ 两点的 $E_x$ 被固定了，所以整个棱 $e$ 上的 $E_x$ 被唯一确定——**$K_1$ 和 $K_2$ 上的 $E_x$ 在棱上完全一样**。

**这等于强制了法向连续。**

---

## 第4页：结论——节点元管得太宽了

**节点元做了什么？**

它保证了"函数值连续"（每个顶点的值唯一），这对应的是**所有分量都连续**。

**但 Maxwell 方程只需要切向连续。**

节点元把法向分量也锁死了，等于给解加了**额外的、物理上不存在的约束**。

**结果：**

- 数值解被"绑得太紧"，无法表达真实的电场跳变
- 算出来的场是错的，而且网格越密，错得越有规律（收敛到错误解）

> **核心矛盾：节点元保证的是"所有分量连续"，但物理只需要"切向连续"。**

---

## 第5页：那我们需要什么？

**我们需要一种离散方式，让它：**

1. **只约束切向分量**——保证物理要求的连续
2. **不约束法向分量**——允许物理允许的跳变
3. 未知数个数合理

**关键想法：把自由度从"顶点"搬到"棱"上。**

- 顶点自由度 → 固定的是"点的值"（所有分量）
- 棱自由度 → 固定的是"沿棱的切向线积分"（只约束切向）

> **下一节：棱元——自由度从顶点搬到棱上。**

# 第3节：引出棱元——自由度从“顶点”搬到“棱”上

## 第1页：回顾——我们需要什么？

上一节的结论：节点元不行，因为它把法向分量也锁死了。

**我们需要一种离散方式：**

1. 只约束切向分量 → 保证物理要求的连续
2. 不约束法向分量 → 允许物理允许的跳变
3. 未知数个数合理

**关键想法：自由度从"顶点"搬到"棱"上。**

这一页只做一件事：让读者带着"我们要解决什么问题"进入本节。

## 第2页：核心思想——在每条棱上放一个自由度

与其在每个顶点放 3 个分量，不如在每条棱上放 1 个自由度。

这个自由度是什么？——**这条棱上的切向线积分**：

$$\ell_e(\mathbf{v}) = \int_e \mathbf{v} \cdot \mathbf{t}_e \, ds$$

人话解释：​ 把电场沿这条棱"加起来"，得到一个数。这个数就是这条棱的"自由度"。

**为什么这样设计？**

因为两个单元共享一条棱时，它们在这条棱上的切向线积分**天然相等**——积分的是同一条棱上的同一个量，不可能不一样。

> **自动保证了切向连续，不需要额外强制。**

## 第3页：一张图看懂"为什么切向线积分天然连续"

例子：两个三角形，公共棱 e 从 A 到 B。

```
B = (0.5, 1)
        ┃
  K₁    ┃    K₂
        ┃
        A = (0.5, 0)
```

关键观察：
- 棱 $e$ 是 $K_1$ 和 $K_2$ 的**同一条**棱
- 在 $K_1$ 上，$\ell_e(\mathbf{v})$ 是沿 $e$ 从 $A$ 到 $B$ 积分
- 在 $K_2$ 上，$\ell_e(\mathbf{v})$ 是沿 $e$ 从 $A$ 到 $B$ 积分
- **积分的是同一个东西，结果必然相等**

对比节点元：
- 节点元靠"顶点值唯一"来保证连续 → 锁死了所有分量
- 棱元靠"积分同一个量"来保证连续 → 只约束切向

这就是棱元的核心优势。

## 第4页：现在给出正式定义

**自由度**（**线性泛函**）：

$$\ell_e(\mathbf{v}) = \int_e \mathbf{v} \cdot \mathbf{t}_e \, ds$$

**基函数**（**棱 $e$ 对应的**）：

$$\boldsymbol{\psi}_e = \lambda_a \nabla \lambda_b - \lambda_b \nabla \lambda_a$$

其中 $\lambda_a, \lambda_b$ 是棱 $e$ 两个端点 $a, b$ 的重心坐标。

**对偶关系**（**关键性质**）：

$$\ell_{e'}(\boldsymbol{\psi}_e) = \delta_{ee'} = \begin{cases} 1 & e' = e \\ 0 & e' \neq e \end{cases}$$

**解释**：
- 每条棱 $e$ 对应一个基函数 $\boldsymbol{\psi}_e$ 
- 这个基函数在棱 $e$ 上的切向线积分是 1
- 在其他任何棱 $e'$ 上的切向线积分是 0
- 就像节点元中"顶点基函数在顶点取1，其他顶点取0"一样

## 第5页：数一数自由度

三角形网格：
- 每个三角形有 3 条棱 → 3 个自由度
- 但内部棱被两个三角形共享，只算一次

具体例子：2×2 正方形网格

```
  o────o────o
  │    │    │
  o────o────o
  │    │    │
  o────o────o
```

- 水平棱：3 行 × 2 条 = 6 条
- 竖直棱：2 行 × 3 条 = 6 条
- 内部斜棱（对角线）：4 条（每个小方格 1 条）
- 总共：16 条棱 → 16 个自由度

对比节点元：
- 顶点数：9 个
- 每个顶点 3 个分量 → 27 个自由度

棱元自由度更少，而且物理上更合理。

## 第6页：预告——下一步

**我们已经有了棱元空间，接下来：**
1. 怎么把方程变成线性方程组？→ 组装矩阵
2. 怎么处理边界条件？→ 边界棱上给定值
3. 怎么求解？→ 解线性方程组
4. 怎么判断算对了？→ 制造精确解，算误差

这就是第4节要讲的：标准流程七步走。

# 第4节：标准流程七步走

## 第1页：回顾——我们已经有什么？

前3节的成果：
1. 问题：双旋度方程 $\nabla \times (\nabla \times \mathbf{E}) - k^2 \mathbf{E} = \mathbf{f}$ 无法解析求解
2. 节点元不行：锁死了法向分量，物理上不允许
3. 棱元：自由度在棱上，自动保证切向连续，允许法向跳变

现在的问题是：有了棱元空间，怎么把它变成实际能算的线性方程组？

这一页只做一件事：让读者知道"工具已经有了，接下来是流程"。

## 第2页：七步总览——一张表看懂全局

| 步骤  | 做什么   | 输入                                     | 输出                          |
| --- | ----- | -------------------------------------- | --------------------------- |
| 1   | 切网格   | 区域                                     | 三角形网格                       |
| 2   | 建棱元空间 | 网格                                     | 自由度总数 $N$                   |
| 3   | 造精确解  | 手选 $\mathbf{E}_{\text{ex}}$​           | 源项 $\mathbf{f}$             |
| 4   | 组装矩阵  | 空间、k、f                                 | $A = C - k^2M$，$\mathbf{b}$ |
| 5   | 边界条件  | 边界棱上的精确值                               | 修改后的 $A$、$\mathbf{b}$       |
| 6   | 求解    | 线性方程组                                  | 系数向量 $\mathbf{x}$           |
| 7   | 后处理   | $\mathbf{x}$、$\mathbf{E}_{\text{ex}}$​ | 误差、收敛阶、图                    |

通俗一点：
- 步骤1-2：把连续问题变成离散问题（网格 + 自由度）
- 步骤3：自己造一个答案，用来检验程序（后面细讲）
- 步骤4-6：把离散问题变成线性方程组，然后解出来
- 步骤7：检查算得对不对

## 第3页：步骤1——切网格

做什么：把区域切成三角形。

人话解释：就像拼图，把复杂形状拆成简单小块。每块三角形上，解被假设成简单的形式。

输入：区域

输出：三角形网格（顶点坐标 + 三角形连接关系）

关键点：
- 网格越密，近似越好，但计算量越大
- 网格质量影响精度：避免太扁的三角形
- 这一步通常用现成工具

## 第4页：步骤2——建棱元空间

做什么：数一数网格里有多少条棱，每个棱对应一个自由度。

人话解释：棱元空间就是"所有可能的近似解"的集合。每个近似解由每条棱上的一个数决定。

输入：网格

输出：自由度总数 $N$ = 网格中棱的总数

具体操作：
- 数所有棱（内部棱只算一次）
- 每个棱 $e_i$ 对应一个基函数 $\boldsymbol{\psi}_{e_i}$ 
- 近似解写成：$\mathbf{E}_h = \sum\limits_{i=1}^{N} x_i \, \boldsymbol{\psi}_{e_i}$，其中 $x_i$ 是第 $i$ 条棱上的自由度（切向线积分的值）。

关键点：$N$ 就是我们要解的线性方程组的规模。

## 第5页：步骤3——造精确解（Manufactured Solution）

做什么：自己选一个光滑函数 $\mathbf{E}_{\text{ex}}$，代入方程算出源项 $\mathbf{f}$。

人话解释：我们不知道真实解是什么，但我们可以"反着来"——先选一个答案，反推题目，然后用程序解这个题目，看能不能算出我们选的答案。

**具体操作：**
1. 手选一个光滑函数，比如：$\mathbf{E}_{\text{ex}} = (\sin(\pi x)\cos(\pi y), \; \cos(\pi x)\sin(\pi y))$ 
2. 代入方程算出源项：$\mathbf{f} = \nabla \times (\nabla \times \mathbf{E}_{\text{ex}}) - k^2 \mathbf{E}_{\text{ex}}$​
3. 用程序解这个方程，得到数值解 $\mathbf{E}_h$ ​

关键点：这一步是检验程序的"金标准"。如果程序能算出我们选的答案，说明程序是对的。

## 第6页：步骤4——组装矩阵

做什么：把棱元空间代入方程，得到线性方程组 $Ax=b$。

人话解释：把"无限维的方程"变成"有限维的代数方程"。每个自由度对应一个未知数，矩阵 A 和向量 b 由网格和参数决定。

具体操作：
- 矩阵 $A = C - k^2 M$ 
- $C$ 是刚度矩阵（来自 $\nabla \times$ 项）：
	$$C_{ij} = \int_\Omega (\nabla \times \boldsymbol{\psi}_{e_i}) \cdot (\nabla \times \boldsymbol{\psi}_{e_j}) \, d\Omega$$
- $M$ 是质量矩阵（来自 $k^2$ 项）：
	$$M_{ij} = \int_\Omega \boldsymbol{\psi}_{e_i} \cdot \boldsymbol{\psi}_{e_j} \, d\Omega$$
- 右端项：
    $$b_i = \int_\Omega \boldsymbol{\psi}_{e_i} \cdot \mathbf{f} \, d\Omega$$

关键点：这些积分在网格上逐单元计算，然后"组装"成全局矩阵。这是有限元中最机械但最核心的一步。

## 第7页：步骤5——边界条件

做什么：在边界棱上施加已知值。

人话解释：方程在区域内部成立，但边界上需要额外信息才能唯一确定解。这里用 Dirichlet 边界条件：边界上的切向电场已知。

具体操作：
- 找出所有边界棱（只有一侧有三角形的棱）
- 在每条边界棱 $e$ 上，计算精确解的切向线积分：
    $$\ell_e(\mathbf{E}_{\text{ex}}) = \int_e \mathbf{E}_{\text{ex}} \cdot \mathbf{t}_e \, ds$$
- 这个值作为该棱的自由度 $x_e$，**固定住**，不参与求解

修改矩阵：
- 对固定自由度的行和列做处理（比如置为单位行/列，右端项相应调整）
- 得到修改后的 $A$ 和 $\mathbf b$ 

关键点：边界条件加在棱上，不是加在顶点上。这是棱元和节点元的又一个区别。

## 第8页：步骤6——求解线性方程组

做什么：解 $A\mathbf x= \mathbf b$，得到所有自由度的值。

人话解释：现在是一个标准的线性代数问题。$N$ 个未知数，$N$ 个方程，用现成求解器解就行。

输入：修改后的 $A$、$\mathbf b$ 

输出：​ 系数向量 $\mathbf x = (x1​,x2​,\cdots,x_N)^T$ 

求解方法：
- 小规模：直接法（如 LU 分解）
- 大规模：迭代法（如 CG、GMRES），需要预处理

关键点：​ 矩阵 A 是稀疏的（每个基函数只和相邻的基函数有非零内积），所以大规模问题也能解。

## 第9页：步骤7——后处理

做什么：用系数向量 $\textbf x$ 重建近似解，计算误差，画图。

人话解释：解出来一堆数（自由度），但这些数本身不是电场。需要把它们组合成电场函数，然后检查算得对不对。

具体操作：
1. 重建近似解：
    $$\mathbf{E}_h = \sum_{i=1}^{N} x_i \, \boldsymbol{\psi}_{e_i}$$
2. 计算误差：
    $$\| \mathbf{E}_h - \mathbf{E}_{\text{ex}} \|_{L^2} = \sqrt{\int_\Omega |\mathbf{E}_h - \mathbf{E}_{\text{ex}}|^2 \, d\Omega}$$
3. 画图：
    - 电场分布图（箭头图或云图）
    - 误差分布图
    - 收敛阶图（误差 vs 网格大小，对数坐标）

关键点：收敛阶图是检验程序正确性的核心工具——误差应该随网格加密而下降，且斜率接近理论值。

## 第10页：预告——怎么判断算对了？

步骤7提到了"误差"和"收敛阶"，但具体怎么判断？
- 误差小就一定对吗？
- 收敛阶是什么？为什么重要？
- 怎么用收敛阶图检验程序？

# 第5节：怎么判断算对了？

## 第1页：回顾——我们面对的问题

七步流程的最后一步是"后处理"，但怎么知道算得对不对？

困难：
- 真实电场我们不知道（如果能解析求解，就不用数值方法了）
- 程序跑出来一个结果，怎么知道它是对的还是错的？

一个朴素的想法：网格加密，结果变化不大 → 应该是对的吧？

但"变化不大"不等于"接近真实解"。

这一页只做一件事：让读者意识到"没有真实解，怎么检验"是个真问题。

## 第2页：核心思想——自己造一个答案

既然没有真实解，我们就自己造一个。

方法：Manufactured Solution（制造精确解）

先选一个光滑函数 $\mathbf{E}_{\text{ex}}$，代入方程反推源项 $\mathbf{f}$，然后用程序解这个"人造问题"，看能不能算出 $\mathbf{E}_{\text{ex}}$ 

为什么这样可行？
- 我们选的 $\mathbf{E}_{\text{ex}}$ 是已知的
- 代入方程算出的 $\mathbf{f}$ 是确定的
- 程序解这个方程，得到 $\mathbf{E}_h$ 
- 比较 $\mathbf{E}_h$ 和 $\mathbf{E}_{\text{ex}}$，误差一目了然

关键点：这不是"自欺欺人"——如果程序连这种"已知答案的问题"都算不对，那算真实问题肯定也不对。

## 第3页：具体操作——四步走

**第一步**：选一个光滑函数

$$\mathbf{E}_{\text{ex}} = (\sin(\pi x)\cos(\pi y), \; \cos(\pi x)\sin(\pi y))$$

要求：足够光滑（至少二阶可导），满足边界条件（在边界上值已知）。

**第二步**：代入方程算源项

$$\mathbf{f} = \nabla \times (\nabla \times \mathbf{E}_{\text{ex}}) - k^2 \mathbf{E}_{\text{ex}}$$

这一步是纯数学计算，可以用符号计算工具（如 SymPy、Mathematica）完成。

**第三步**：用程序解方程

输入：网格、$\mathbf{f}$、边界条件（$\mathbf{E}_{\text{ex}}$ 在边界上的值）

输出：数值解 $\mathbf{E}_h$ ​

**第四步**：算误差

$$\| \mathbf{E}_h - \mathbf{E}_{\text{ex}} \|_{L^2} = \sqrt{\int_\Omega |\mathbf{E}_h - \mathbf{E}_{\text{ex}}|^2 \, d\Omega}$$​

## 第4页：什么叫"算对了"？

误差小就行吗？

不够。因为误差大小取决于网格粗细——网格越粗，误差越大，这不能说明程序有问题。

正确的判断标准：收敛阶。

理论预期：最低阶棱元（我们用的这种）的 $L^2$ 误差应该满足：

$$\| \mathbf{E}_h - \mathbf{E}_{\text{ex}} \|_{L^2} \leq C h$$

其中 $h$ 是网格大小（三角形最大边长），$C$ 是与 $h$ 无关的常数。

人话解释：
- 网格加密一倍（$h \to h/2$），误差应该减半
- 在 $\log$–$\log$ 坐标下，误差 vs $h$ 应该是一条斜率为 1 的直线

## 第5页：收敛阶图——怎么画、怎么看

**画法**：
1. 1. 取一系列网格：$h_1 > h_2 > h_3 > \ldots$ 
2. 对每个网格，算出误差 $e_i = \| \mathbf{E}_h - \mathbf{E}_{\text{ex}} \|_{L^2}$ 
3. 画 $\log(e_i)$ vs $\log(h_i)$ 

**怎么看**：
- 如果点落在一条直线上，且斜率接近理论值（这里约 1）→ **程序正确**
- 如果斜率明显低于理论值 → **程序有 bug**
- 如果误差不随网格加密而下降 → **程序有严重 bug**

关键点：收敛阶图是有限元程序的"体检报告"——一眼就能看出程序有没有问题。

## 第6页：常见错误在收敛阶图上的表现

错误1：边界条件加错了
- 表现：误差不下降，或者收敛阶只有 0.5 左右
- 原因：边界棱上的值没设对，污染了整个解

错误2：矩阵组装错了
- 表现：收敛阶对，但误差常数很大
- 原因：某个积分算错了，但整体结构是对的

错误3：自由度编号搞错了
- 表现：程序直接报错，或者误差极大
- 原因：棱的编号和基函数的对应关系混乱

错误4：波数 k 太大
- 表现：收敛阶下降，甚至不收敛
- 原因：内谐振，矩阵接近奇异

人话解释：收敛阶图不仅能告诉你"对不对"，还能帮你"找 bug"。

## 第7页：预告——常见坑

七步流程 + 判断标准都有了，但实际写代码时还有很多坑。

比如：
- 自由度总数对不上？
- 边界条件加在顶点上了？
- 内部棱算了两次？
- 波数太大导致矩阵奇异？

这些都是初学者最容易踩的坑。

下一节：常见坑——帮你避开这些雷。

# 第6节：常见坑——帮你避开这些雷

## 第1页：回顾——我们已经有什么？

前5节的成果：
1. 问题：双旋度方程需要数值求解
2. 节点元不行 → 引出棱元
3. 棱元：自由度在棱上，自动保证切向连续
4. 七步流程：切网格 → 建空间 → 造解 → 组装 → 边界 → 求解 → 后处理
5. 判断标准：Manufactured Solution + 收敛阶图

现在的问题是：实际写代码时，有哪些坑？

这一页只做一件事：让读者知道"理论懂了，但实践有坑"。

## 第2页：坑1——把棱元当成"每点3个自由度的节点元"

**错误做法**：以为棱元就是"每个顶点放3个分量，但换个名字叫棱元"。

**后果**：
- 自由度总数对不上
- 矩阵组装错误
- 收敛阶不对

**正确理解**：
- 棱元的自由度在**棱**上，不在顶点上
- 每条棱只有**1个**自由度（切向线积分）
- 不是"每点3个分量"

**自检方法**：数一数你的自由度总数，应该等于网格中棱的总数。如果等于"顶点数 × 3"，说明你还在用节点元的思路。

## 第3页：坑2——边界条件加在顶点上

**错误做法**：把 Dirichlet 边界条件加在边界**顶点**上，而不是边界**棱**上。

**后果**：
- 边界棱上的自由度没有被固定
- 矩阵奇异或解不唯一
- 误差不下降

**正确做法**：
- 找出所有边界**棱**（只有一侧有三角形的棱）
- 在每条边界棱上，计算 $\displaystyle \ell_e(\mathbf{E}_{\text{ex}}) = \int_e \mathbf{E}_{\text{ex}} \cdot \mathbf{t}_e \, ds$ 
- 把这个值作为该棱的自由度，固定住

**自检方法**：检查你的边界条件代码——如果循环遍历的是顶点而不是棱，就是错的。

## 第4页：坑3——内部棱算了两次

**错误做法**：组装矩阵时，对每条内部棱，在两个相邻单元上各算了一次贡献。

**后果**：
- 矩阵不对称（或虽然对称但数值错误）
- 切向连续性被破坏
- 收敛阶下降

**正确做法**：
- 每条棱只对应**一个**自由度
- 组装时，确保每条棱的贡献只加一次
- 通常的做法是：给每条棱一个全局编号，组装时按编号累加

**自检方法**：检查矩阵 $A$ 是否对称。如果不对称，很可能就是内部棱算了两次。

## 第5页：坑4——波数 $k$ 取太大

**错误做法**：波数 $k$ 取得很大（比如 $k=100$），然后发现程序不收敛或矩阵奇异。

**后果**：
- 内谐振：矩阵 $A = C - k^2M$ 接近奇异
- 数值解振荡剧烈
- 收敛阶下降甚至不收敛

**原因**：当 $k$ 接近某个特征值时，矩阵接近奇异，求解不稳定。

**正确做法**：
- 先用小的 $k$（比如 $k=1$）测试程序
- 确认程序正确后，再逐步增大 $k$ 
- 如果 $k$ 很大，需要更细的网格（$kh$ 要足够小）

**自检方法**：检查矩阵的条件数。如果条件数很大（比如 $>1010$），说明矩阵接近奇异。

## 第6页：坑5——基函数方向搞反了

**错误做法**：基函数 $\boldsymbol{\psi}_e = \lambda_a \nabla \lambda_b - \lambda_b \nabla \lambda_a$ 中，把 $a$ 和 $b$ 搞反了。

**后果**：
- 对偶关系 $\ell_{e'}(\boldsymbol{\psi}_e) = \delta_{ee'}$ 不成立
- 矩阵组装错误
- 自由度含义混乱

**正确做法**：
- 每条棱 $e$ 有两个端点 $a, b$ 
- - 基函数定义为 $\boldsymbol{\psi}_e = \lambda_a \nabla \lambda_b - \lambda_b \nabla \lambda_a$
- 切向线积分 $\displaystyle \ell_e(\mathbf{v}) = \int_e \mathbf{v} \cdot \mathbf{t}_e \, ds$ 中，$\mathbf{t}_e$ 的方向从 $a$ 指向 $b$ 

**自检方法**：
- 检查对偶关系：$\ell_{e'}(\boldsymbol{\psi}_e)$ 在 $e' = e$ 时应该等于 1，在 $e' \neq e$ 时等于 0。

## 第7页：坑6——网格质量太差

**错误做法**：网格中有很多"扁"三角形（内角接近 0° 或 180°）。

**后果**：
- 基函数数值不稳定
- 矩阵条件数变大
- 收敛阶下降

**正确做法**：
- 使用质量好的网格（三角形尽量接近等边）
- 避免太扁的三角形
- 如果必须用复杂区域，考虑自适应网格加密

**自检方法**：检查网格的最小内角。如果最小内角太小，网格质量堪忧。

## 第8页：坑7——忘了验证程序

**错误做法**：程序写完了，跑出一个结果，看起来"合理"，就直接用了。

**后果**：
- 可能程序有 bug，但结果"看起来对"
- 换一个参数或网格，错误就暴露了

**正确做法**：
- 每次修改程序后，都跑一遍 Manufactured Solution 测试
- 检查收敛阶是否接近理论值
- 用不同的网格和参数测试

**自检方法**：如果收敛阶图不是一条斜率接近理论值的直线，说明程序有问题，别急着用。

# 末尾：所有知识点的严谨定义
## 1-1 数学基础
1. **向量场**：设 $D \subset \mathbb R^n$ 为开区域，若对每个 $\mathbf x \in D$ 都对应一个向量 $\mathbf v (\mathbf x) \in \mathbb R^n$，则称 $\mathbf v: D \to \mathbb R^n$ 为 $D$ 上的一个**向量场**。
2. **梯度**：设 $u: D\to \mathbb R$ 可微，则 $u$ 在点 $\mathbf x$ 处的梯度定义为 $\nabla u(\mathbf x) = \left( \dfrac{\partial u}{\partial x_1}, \dfrac{\partial u}{\partial x_2}, \cdots, \dfrac{\partial u}{\partial x_n} \right) \in \mathbb R^n$ 
	- 梯度指向 $\mathbf u$ 增长最快的方向，其模长等于该方向的方向导数。
3. **旋度**：设 $\mathbf E = (E_1, E_2, E_3): D \subset \mathbb R^3 \to \mathbb R^3$ 为可微向量场，则其旋度定义为 $\nabla \times \mathbf E = \left( \dfrac{\partial E_3}{\partial x_2} - \dfrac{\partial E_2}{\partial x_3}, \dfrac{\partial E_1}{\partial x_3} - \dfrac{\partial E_3}{\partial x_1}, \dfrac{\partial E_2}{\partial x_1} - \dfrac{\partial E_1}{\partial x_2} \right) \in \mathbb R^3$ 
	- 旋度刻画了 $\mathbf E$ 在每点附近的局部旋转强度与方向。
4. **散度**：设 $\mathbf E = (E_1, E_2, E_3): D \subset \mathbb R^3 \to \mathrm R^3$ 为可微向量场，则其散度定义为 $\nabla \cdot \mathbf E = \dfrac{\partial E_1}{\partial x_1} + \dfrac{\partial E_2}{\partial x_2} + \dfrac{\partial E_3}{\partial x_3} \in \mathbb R$ 
	- 散度刻画了 $\mathbf E$ 在每点附近的源强度 (向外发散的程度)
5. **$L^2$ 空间**：设 $D\subset \mathbb R^n$ 为可测集，定义 $\displaystyle L^2(D) = \left\{ u: D \to \mathbb R \left| u\text{ 可测且 }  \int_D |u(\mathbf x)|^2 \mathrm d \mathbf x < \infty \right. \right\}$，即 $D$ 上平方可积函数的全体，按内积 $\displaystyle \langle u, v \rangle = \int_D u v \, \mathrm d\mathbf{x}$ 
6. **范数**：
	设 $X$ 为线性空间，若映射 $\| \cdot \| : X \to [0,\infty)$ 满足：
	(i) $\| u \| = 0 \iff u=0$ 
	(ii) $\| \alpha u \| = |\alpha| \| u \|$ 
	(iii) $\| u + v \| \le \| u \| + \| v \|$ 
	则称 $\| \cdot \|$ 为 $X$ 上的范数
	- 在 $L^2(D)$ 上，范数定义为 $\displaystyle \| u \|_{L^2} = \left( \int_D |u|\mathrm d\mathbf x \right)^{1/2}$ 
7. **内积**：
	设 $X$ 为实线性空间，若映射 $\langle \cdot, \cdot \rangle: X \times X \to \mathbb R$ 满足：
	(i) 对称性 $\langle u, v \rangle = \langle v, u \rangle$ 
	(ii) 线性性 $\langle \alpha u + \beta v, w \rangle = \alpha \langle u, w \rangle + \beta \langle v, w \rangle$ 
	(iii) 正定性 $\langle u, u \rangle \ge 0$ 且等号成立当且仅当 $u=0$ 
	则称 $\langle \cdot, \cdot \rangle$ 为 $X$ 上的内积
	- 在 $L^2(D)$ 上，内积定义为 $\displaystyle \langle u, v\rangle = \int_D u(\mathbf x) v(\mathbf x) \mathrm d\mathbf x$ 
8. **线性泛函**：设 $X$ 为赋范线性空间，若映射 $F: X \to \mathbb R$ 满足 $F(\alpha u + \beta v) = \alpha F(u) + \beta F(v)$ 且 $\| F \| = \sup\limits_{u\not=0} \dfrac{|F(u)|}{\| u \|} < \infty$，则称 $F$ 为 $X$ 上的有界线性泛函
	- 在 $L^2(D)$ 上，典型例子是 $\displaystyle F(u) = \int_D uf\mathrm d\mathbf x\ (f\in L^2(D))$，即与固定函数 $f$ 做内积。
9. **Banach 空间**​：设 $X$ 为赋范线性空间，范数为 $\|\cdot\|: X \to [0, \infty)$，若 $X$ 中任何 Cauchy 列 $\{u_n\}_{n=1}^{\infty}$ (即对任意 $\varepsilon > 0$，存在 $N$ 使得当 $m, n > N$ 时有 $\|u_m - u_n\| < \varepsilon$) 都收敛于 $X$ 中的某个元素，则称 $X$ 为 Banach 空间 (完备的赋范线性空间)。
10. **对偶空间**：设 $X$ 为赋范线性空间，$X$ 上的所有有界线性泛函的全体 $X^* = \{ F: X \to \mathbb R \mid F \text{ 线性且有界} \}$，按范数 $\| F \|_{X^*} = \sup\limits_{u\not=0} \dfrac{|F(u)|}{\| u \|_X}$ 构成一个 Banach 空间，称为 $X$ 的对偶空间。
11. **对偶基**：设 $V$ 为 $n$ 维线性空间，$\{v_1, \cdots, v_n\}$ 为 $V$ 的一组基，$\{f_1, \cdots, f_n\}\subset V^*$ ($V^*$ 为 $V$ 的对偶空间)，若 $f_i(v_j) = \delta_{ij}$ (Kronecker delta)，则称 $\{f_1, \cdots, f_n\}$ 为 $\{v_1, \cdots, v_n\}$ 的对偶基。
	- 在有限元中，基函数 $\{\varPhi_i\}$ 的对偶基就是“自由度泛函” (如取节点值、取棱上的线积分等)，它们满足 $l_i(\varPhi_j) = \delta_{ij}$ 
12. **Hilbert 空间**：设 $H$ 为线性空间，若 $H$ 上定义了内积 $\langle \cdot, \cdot \rangle$，且由内积诱导的范数 $\|u\| = \sqrt{\langle u, u \rangle}$ 使 $H$ 成为完备的赋范线性空间 (即 $H$ 中任何 Cauchy 列都收敛于 $H$ 中的元素)，则称 $H$ 为 Hilbert 空间。
	- $L^2(D)$ 按内积 $\displaystyle \langle u, v \rangle = \int_D uv \, d\mathbf{x}$ 就是一个 Hilbert 空间。
13. **弱形式**：设 $V$ 为 Hilbert 空间，$a: V\times V \to \mathbb R$ 为连续双线性型，$F:V\to\mathbb R$ 为连续线性泛函，则原问题 $Lu=f$ 的弱形式为：求 $u\in V$，使得 $a(u,v) = F(v),\ \forall\ v\in V$，其中 $\displaystyle a(u,v) = \int_D (\nabla \times u) \cdot (\nabla \times v) \mathrm d \mathbf x$ 等具体形式由原方程经分部积分导出，测试函数 $u$ 只需属于 $V$ 而非要求更高阶可微。
14. **Galerkin 方法**：设 $V_h \subset V$ 为有限维子空间，Galerkin 方法为：求 $u_h \in V_h$ 使得 $a(u_h, v_h) = F(v_h),\ \forall\ v_h \in V_h$。若 $\{ \varPhi_1, \cdots, \varPhi_N \}$ 为 $V_h$ 的基，则 $u_h = \sum\limits_{j=1}^N c_j \varPhi_j$，系数 $\mathbf c = (c_1, \cdots, c_N)$ 满足线性方程组 $A\mathbf c = \mathbf b$，其中 $A_{ij} = a(\varPhi_j, \varPhi_i),\ b_i = F(\varPhi_i)$ 
## 1-2 有限元基础
15. **网格** (**Mesh**)：设 $\Omega \subset \mathbb{R}^n$ 为有界多边形区域 ($n=2$) 或多面体区域 ($n=3$)，网格 $\mathcal{T}_h$ 是 $\Omega$ 的一个有限剖分，满足：(i) $\overline{\Omega} = \bigcup\limits_{K \in \mathcal{T}_h} \overline{K}$；(ii) 任意两个不同单元的内部互不相交；(iii) 每个单元 $K$ 是闭的单纯形 (三角形/四面体) 或凸多边形/多面体。参数 $h = \max\limits_{K \in \mathcal{T}_h} \text{diam}(K)$ 称为网格尺寸。
16. **单元** (**Element**)：设 $\mathcal{T}_h$ 为 $\Omega$ 的网格，则 $\mathcal{T}_h$ 中的每个成员 $K$ 称为一个单元。
	- 在二维情形 $K$ 通常为三角形 ($K$ 有 3 个顶点、3 条棱)，在三维情形 $K$ 通常为四面体 ($K$ 有 4 个顶点、6 条棱)。
17. **顶点** (**Vertex** / **Node**)：设 $K$ 为一个单元，$K$ 的顶点是 $K$ 的 $0$ 维面，即构成 $K$ 的角点。全局顶点集合记为 $\mathcal{V} = \{V_1, \dots, V_N\}$，其中 $N$ 为全局顶点总数。每个顶点 $V_i$ 对应一个坐标 $\mathbf{x}_i \in \mathbb{R}^n$。
18. **棱** (**Edge**)：设 $K$ 为一个单元，$K$ 的棱是 $K$ 的 $1$ 维面，即连接两个顶点的线段。全局棱集合记为 $\mathcal{E} = \{e_1, \dots, e_M\}$，其中 $M$ 为全局棱总数 (内部棱被多个单元共享，但在全局集合中只计一次)。每条棱 $e$ 有两个端点 $a, b$，可赋予方向 (从 $a$ 到 $b$)。
19. **自由度** (**Degree of Freedom, DOF**)：设 $V_h$ 为有限元空间，$\dim V_h = N$，则 $V_h$ 上的自由度是 $N$ 个线性泛函 $\{\ell_1, \dots, \ell_N\} \subset V_h^*$，满足：对任意 $u_h \in V_h$，若 $\ell_i(u_h) = 0$ 对所有 $i = 1, \dots, N$ 成立，则 $u_h \equiv 0$ (即自由度足以区分 $V_h$ 中不同的函数)。每个自由度 $\ell_i$ 对应未知系数 $c_i$，使得 $u_h = \sum\limits_{i=1}^N c_i \phi_i$ 且 $c_i = \ell_i(u_h)$。
20. **基函数** (**Basis Function**)：设 $V_h$ 为 $N$ 维有限元空间，$\{\phi_1, \dots, \phi_N\} \subset V_h$ 称为 $V_h$ 的一组基，若它们线性无关且张成 $V_h$，即任意 $u_h \in V_h$ 可唯一表示为 $u_h = \sum\limits_{i=1}^N c_i \phi_i$。
	- 在有限元中，基函数通常具有局部支集 (只在少数相邻单元上非零)，且与自由度满足对偶关系 $\ell_i(\phi_j) = \delta_{ij}$。
21. **有限元空间** (**Finite Element Space**)：设 $\mathcal{T}_h$ 为 $\Omega$ 的网格，$V_h$ 称为 $\Omega$ 上的有限元空间，若 $V_h$ 满足：(i) $V_h$ 是 $H^1(\Omega)$ (或 $H(\text{curl})$、$H(\text{div})$ 等) 的有限维子空间；(ii) 对每个单元 $K \in \mathcal{T}_h$，$V_h|_K$ 是 $K$ 上的多项式空间 (如 $P_1(K)$ 等)；(iii) $V_h$ 中的函数在相邻单元之间满足特定的连续性条件 (如 $C^0$ 连续或切向连续)。
22. **组装** (**Assembly**)：设 $\{\phi_1, \dots, \phi_N\}$ 为 $V_h$ 的基，$a(\cdot, \cdot)$ 为双线性型，组装是指通过遍历所有单元 $K \in \mathcal{T}_h$，在每个单元上计算局部矩阵 $A^K_{ij} = a_K(\phi_j|_K, \phi_i|_K)$，再通过自由度映射 (局部编号 → 全局编号) 将局部矩阵贡献累加到全局矩阵 $A_{ij} = \sum\limits_{K} A^K_{ij}$ 的过程。右端向量 $\mathbf{b}$ 的组装类似：$b_i = \sum\limits_K F_K(\phi_i|_K)$ 
23. **刚度矩阵** (**Stiffness Matrix**)：设 $a(\cdot, \cdot)$ 为来自微分算子的双线性型，刚度矩阵定义为 $A_{ij} = a(\phi_j, \phi_i)$，其中 $i, j = 1, \dots, N$。
	- 在本算例中，刚度矩阵来自旋度项：$\displaystyle C_{ij} = \int_\Omega (\nabla \times \phi_j) \cdot (\nabla \times \phi_i) \, d\mathbf{x}$。
24. **质量矩阵** (**Mass Matrix**)：设 $a(\cdot, \cdot)$ 为来自函数自身乘积的双线性型，质量矩阵定义为 $\displaystyle M_{ij} = \int_\Omega \phi_j \cdot \phi_i \, d\mathbf{x}$，其中 $i, j = 1, \dots, N$。它对应弱形式中 $\displaystyle \int_\Omega \mathbf{E}_h \cdot \mathbf{v}_h \, d\mathbf{x}$ 这一项。
25. **边界条件** (**Boundary Condition**)：设 $\partial\Omega$ 为区域边界，边界条件是对解在 $\partial\Omega$ 上的限制。
	- 在本算例中，使用 Dirichlet 切向边界条件：在边界棱 $e \subset \partial\Omega$ 上，要求 $\displaystyle \int_e \mathbf{E}_h \cdot \mathbf{t}_e \, ds = \int_e \mathbf{E}_{\text{ex}} \cdot \mathbf{t}_e \, ds$，即数值解在边界上的切向线积分等于精确解的切向线积分。
26. **Dirichlet 边界条件**：设 $u$ 为 PDE 的解，Dirichlet 边界条件直接给定 $u$ 在 $\partial\Omega$ 上的值：$u = g$ 在 $\partial\Omega$ 上。对棱元情形，Dirichlet 条件施加在边界棱的自由度上 (切向分量的线积分)，而非顶点上。
27. **收敛阶** (**Order of Convergence**)：设 $u$ 为精确解，$u_h$ 为数值解，$h$ 为网格尺寸。若存在常数 $C > 0$ 和 $\alpha > 0$，使得 $\|u - u_h\| \le C h^\alpha$，则称数值方法具有 $\alpha$ 阶收敛。实际中通过计算相邻两层网格的误差比来估计：$\alpha \approx \dfrac{\log(\|u - u_{h_1}\| / \|u - u_{h_2}\|)}{\log(h_1 / h_2)}$。对最低阶第一类 Nédélec 元，$L^2$ 误差的理论收敛阶为 $O(h)$ (能量范数为 $O(h)$)
## 1-3 核心概念的定义
15. **H(curl) 空间**：设 $\Omega \subset \mathbb{R}^3$ 为有界 Lipschitz 区域 (2D 情形取 $\Omega \subset \mathbb{R}^2$，旋度理解为标量旋度 $\nabla \times \mathbf{v} = \dfrac{\partial v_2}{\partial x_1} - \dfrac{\partial v_1}{\partial x_2}$)，定义 $H(\text{curl}; \Omega) = \left\{ \mathbf{v} \in L^2(\Omega)^3 \;|\; \nabla \times \mathbf{v} \in L^2(\Omega)^3 \right\}$，装备内积 $\displaystyle \langle \mathbf{u}, \mathbf{v} \rangle_{H(\text{curl})} = \int_\Omega \mathbf{u} \cdot \mathbf{v} \, d\mathbf{x} + \int_\Omega (\nabla \times \mathbf{u}) \cdot (\nabla \times \mathbf{v}) \, d\mathbf{x}$，由此诱导范数 $\|\mathbf{v}\|_{H(\text{curl})} = \left( \|\mathbf{v}\|_{L^2}^2 + \|\nabla \times \mathbf{v}\|_{L^2}^2 \right)^{1/2}$，$H(\text{curl}; \Omega)$ 在此范数下构成一个 Hilbert 空间。
16. **切向连续** (**Tangential Continuity**)：设 $\mathcal{T}_h$ 为 $\Omega$ 的网格，$K_1, K_2 \in \mathcal{T}_h$ 共享公共棱 $e = \partial K_1 \cap \partial K_2$，$\mathbf{t}_e$ 为 $e$ 的单位切向向量。若 $\mathbf{v}$ 满足 $\displaystyle \int_e (\mathbf{v}|_{K_1}) \cdot \mathbf{t}_e \, ds = \int_e (\mathbf{v}|_{K_2}) \cdot \mathbf{t}_e \, ds$，则称 $\mathbf{v}$ 在棱 $e$ 上切向连续。若 $\mathbf{v}$ 在所有内部棱上都切向连续，则称 $\mathbf{v}$ 在 $\mathcal{T}_h$ 上切向连续。
	- $H(\text{curl})$ 空间中的函数恰好在分片意义下满足切向连续。
17. **第一类 Nédélec 元**（**Nédélec Element of First Kind**)：
	1设 $K$ 为三角形 (2D) 或四面体 (3D) 单元，$P_p(K)$ 为 $K$ 上次数 $\le p$ 的多项式空间，$\widetilde{P}_p(K)$ 为 $K$ 上次数 $\le p$ 的齐次多项式空间 (次数恰好等于 $p$ 的部分)。
	第一类 Nédélec 元在 2D 三角形上的局部空间定义为
	$$\mathcal{N}_p(K) = P_{p-1}(K)^2 \oplus \left\{ \mathbf{q} \in \widetilde{P}_p(K)^2 \;|\; \mathbf{q} \cdot \mathbf{x} = 0 \right\},$$
	在 3D 四面体上的局部空间定义为
	$$\mathcal{N}_p(K) = P_{p-1}(K)^3 \oplus \left\{ \mathbf{q} \in \widetilde{P}_p(K)^3 \;|\; \mathbf{q} \cdot \mathbf{x} = 0 \right\}.$$
	对最低阶 $p=1$ 情形，$\dim \mathcal{N}_1(K) = 3$ (2D 三角形，等于棱数) 或 $6$ (3D 四面体，等于棱数)，自由度取为每条棱上的切向线积分 $\displaystyle \ell_e(\mathbf{v}) = \int_e \mathbf{v} \cdot \mathbf{t}_e \, ds$ 
18. **棱元** (**Edge Element**)：棱元是自由度定义在棱上的矢量有限元的统称。最低阶第一类 Nédélec 棱元：每个单元 $K$ 上，每条棱 $e$ 对应一个基函数 $\boldsymbol{\psi}_e$，满足对偶关系 $\ell_{e'}(\boldsymbol{\psi}_e) = \delta_{ee'}$ (即 $\displaystyle \int_{e'} \boldsymbol{\psi}_e \cdot \mathbf{t}_{e'} \, ds = \delta_{ee'}$)。全局棱元空间 $V_h \subset H(\text{curl}; \Omega)$ 由所有单元上的局部基函数通过“共享棱对应同一自由度”的方式拼接而成，$\dim V_h = E$ (全局棱数)。
19. **节点元**（**Lagrange 元**)：设 $K$ 为单纯形单元，$P_p(K)$ 为 $K$ 上次数 $\le p$ 的多项式空间，节点元 (Lagrange 元) 的局部空间为 $P_p(K)$，自由度为单元上的节点值 (对 $p=1$ 即顶点值)：$\ell_{V_i}(u) = u(V_i)$。全局 Lagrange 元空间 $V_h \subset H^1(\Omega)$ 由所有单元上的局部基函数通过“共享顶点对应同一自由度”的方式拼接而成，$\dim V_h = N$ (全局顶点数)，且 $V_h$ 中的函数在 $\Omega$ 上整体连续 ($C^0$ 连续)。
20. **双旋度方程** (**Curl-Curl Equation**)：
	设 $\Omega \subset \mathbb{R}^3$ 为有界区域，$k > 0$ 为波数，$\mathbf{f} \in L^2(\Omega)^3$ 为已知源项，双旋度方程为：求 $\mathbf{E}$ 满足
	$$\nabla \times (\nabla \times \mathbf{E}) - k^2 \mathbf{E} = \mathbf{f} \quad \text{在 } \Omega \text{ 内},$$
	其变分 (弱) 形式为：求 $\mathbf{E} \in H_0(\text{curl}; \Omega)$，使得
	$$\int_\Omega (\nabla \times \mathbf{E}) \cdot (\nabla \times \mathbf{v}) \, d\mathbf{x} - k^2 \int_\Omega \mathbf{E} \cdot \mathbf{v} \, d\mathbf{x} = \int_\Omega \mathbf{f} \cdot \mathbf{v} \, d\mathbf{x}, \ \forall\ \mathbf{v} \in H_0(\text{curl}; \Omega).$$
21. **时谐 Maxwell 方程** (**Time-Harmonic Maxwell Equations**)：
	设时间因子取 $e^{-i\omega t}$ ($\omega$ 为角频率)，线性各向同性介质中无源区电场 $\mathbf{E}$ 满足
	$$\nabla \times (\mu^{-1} \nabla \times \mathbf{E}) - \omega^2 \varepsilon \mathbf{E} = i\omega \mathbf{J},$$
	其中 $\mu$ 为磁导率，$\varepsilon$ 为介电常数，$\mathbf{J}$ 为外加电流源。
	当介质均匀 (常数 $\mu, \varepsilon$) 时，令 $k = \omega\sqrt{\mu\varepsilon}$，方程化为
	$$\nabla \times (\nabla \times \mathbf{E}) - k^2 \mathbf{E} = \mathbf{f}, \quad \mathbf{f} = i\omega\mu\mathbf{J},$$
	即双旋度方程。
22. **Manufactured Solution**（**造解 / 人为构造精确解**)：设 $\mathbf{E}_{\text{ex}}$ 为人为选定的光滑矢量场 (满足所需的边界条件)，将其代入双旋度方程左端算出对应的源项 $\mathbf{f} = \nabla \times (\nabla \times \mathbf{E}_{\text{ex}}) - k^2 \mathbf{E}_{\text{ex}}$，则 $\mathbf{E}_{\text{ex}}$ 是方程 $\nabla \times (\nabla \times \mathbf{E}) - k^2 \mathbf{E} = \mathbf{f}$ 的精确解。用数值方法求解该方程得到 $\mathbf{E}_h$，通过比较 $\|\mathbf{E}_h - \mathbf{E}_{\text{ex}}\|$ 随 $h$ 的变化来验证程序的正确性，这种方法称为 manufactured solution 验证。
23. **Piola 变换** (**Piola Transformation**)：
	设 $\hat{K}$ 为参考单元，$F_K: \hat{K} \to K$ 为仿射映射 $F_K(\hat{\mathbf{x}}) = B_K \hat{\mathbf{x}} + \mathbf{b}_K$ ($B_K$ 为可逆矩阵)。对 $H(\text{curl})$ 相容的矢量基函数，Piola 变换定义为
	$$\boldsymbol{\psi}(\mathbf{x}) = B_K^{-T} \hat{\boldsymbol{\psi}}(\hat{\mathbf{x}}), \quad \mathbf{x} = F_K(\hat{\mathbf{x}}),$$
	其中 $B_K^{-T} = (B_K^{-1})^T$。
	该变换保持切向分量的线积分不变：$\int_e \boldsymbol{\psi} \cdot \mathbf{t}_e \, ds = \int_{\hat{e}} \hat{\boldsymbol{\psi}} \cdot \hat{\mathbf{t}}_{\hat{e}} \, d\hat{s}$，从而保证自由度在变换下不变。
24. **内谐振** (**Internal Resonance**)
	设 $A = C - k^2 M$ 为离散双旋度算子 ($C$ 为刚度矩阵，$M$ 为质量矩阵)，若 $k^2$ 接近 $C$ 相对于 $M$ 的某个广义特征值 $\lambda_i$ (即 $C\mathbf{x}_i = \lambda_i M \mathbf{x}_i$)，则 $A$ 接近奇异，条件数 $\kappa(A) \to \infty$，求解不稳定，数值解出现虚假振荡。这种现象称为内谐振。本算例取小波数 $k$ 和细网格，使 $k^2$ 远离最小特征值，从而避开内谐振。
## 1-4 FEALPy 相关
38. **TriangleMesh** (**三角形网格类**)：设 $\Omega \subset \mathbb{R}^2$ 为有界多边形区域，TriangleMesh 是 $\Omega$ 的一个三角形剖分 $\mathcal{T}_h$ 的数据结构，包含：顶点坐标数组 $\mathbf{P} \in \mathbb{R}^{N \times 2}$ ($N$ 为顶点数)、单元连接数组 $\text{cell} \in \mathbb{Z}^{M \times 3}$ ($M$ 为单元数，每行是构成该三角形的 3 个顶点全局编号)、以及由顶点编号推导出的棱连接数组 $\text{edge} \in \mathbb{Z}^{E \times 2}$ ($E$ 为棱数，每行是构成该棱的 2 个顶点全局编号，内部棱只记录一次)。FEALPy 中通过 `TriangleMesh.from_box(box, nx, ny)` 生成 $[0,1]^2$ 上的均匀三角形网格。
39. **NedelecFiniteElementSpace** (**第一类 Nédélec 棱元空间类**)：设 $\mathcal{T}_h$ 为 $\Omega$ 的三角形网格，$p \ge 1$ 为多项式次数，NedelecFiniteElementSpace 是定义在 $\mathcal{T}_h$ 上的第一类 Nédélec 棱元有限元空间 $V_h \subset H(\text{curl}; \Omega)$ 的数据结构，包含：局部基函数在参考单元上的表达式、自由度定义 (最低阶 $p=1$ 时为每条棱上的切向线积分 $\displaystyle \ell_e(\mathbf{v}) = \int_e \mathbf{v} \cdot \mathbf{t}_e \, ds$)、局部自由度到全局自由度的映射 (内部棱共享同一全局自由度)、以及全局自由度总数 $\dim V_h = E$ (全局棱数)。FEALPy 中通过 `NedelecFiniteElementSpace(mesh, p=1)` 构造，调用 `space.number_of_global_dofs()` 返回自由度总数。
40. **bform** (**双线性型组装器**)：设 $a(\cdot, \cdot): V_h \times V_h \to \mathbb{R}$ 为双线性型，bform 是 FEALPy 中用于组装双线性型对应矩阵的工具。其工作流程为：遍历所有单元 $K \in \mathcal{T}_h$，在参考单元上通过数值积分 (Gauss 求积) 计算局部矩阵 $A^K_{ij} = a_K(\phi_j|_K, \phi_i|_K)$，再通过局部-全局自由度映射将贡献累加到全局矩阵 $A_{ij} = \sum\limits_K A^K_{ij}$。在本算例中，bform 添加两项：curl-curl 项 $\displaystyle C_{ij} = \int_\Omega (\nabla \times \phi_j) \cdot (\nabla \times \phi_i) \, d\mathbf{x}$ 和 mass 项 $\displaystyle M_{ij} = \int_\Omega \phi_j \cdot \phi_i \, d\mathbf{x}$，最终组装得到 $A = C - k^2 M$。
41. **lform** (**线性型组装器**)：设 $F(\cdot): V_h \to \mathbb{R}$ 为线性泛函，lform 是 FEALPy 中用于组装线性泛函对应右端向量的工具。其工作流程为：遍历所有单元 $K \in \mathcal{T}_h$，在参考单元上通过数值积分计算局部向量 $b^K_i = F_K(\phi_i|_K)$，再通过局部-全局自由度映射将贡献累加到全局向量 $b_i = \sum\limits_K b^K_i$。在本算例中，lform 添加 source 项 $\displaystyle b_i = \int_\Omega \mathbf{f} \cdot \phi_i \, d\mathbf{x}$，其中 $\mathbf{f}$ 为 manufactured solution 算出的源项。
42. **boundary_dof** (**边界自由度接口**)：设 $\partial\Omega$ 为区域边界，$\mathcal{E}_{\partial\Omega} = \{e \in \mathcal{E} \;|\; e \subset \partial\Omega\}$ 为位于边界上的棱集合，boundary_dof 是 FEALPy 中返回边界自由度编号的接口。其输出为指标集合 $\mathcal{I}_{\partial} = \{i \in \{1, \dots, E\} \;|\; \ell_i \text{ 对应某条边界棱 } e \in \mathcal{E}_{\partial\Omega}\}$，即所有定义在边界棱上的全局自由度编号。在本算例中，用 `space.boundary_dof(boundary_edge_mark)` 获取 $\mathcal{I}_{\partial}$，然后将这些自由度赋值为精确解的切向线积分 $\displaystyle \int_e \mathbf{E}_{\text{ex}} \cdot \mathbf{t}_e \, ds$，实现 Dirichlet 切向边界条件。