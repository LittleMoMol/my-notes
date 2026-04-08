姓名：赵默涵
班级：24级信计一班
学号：202405755504
所有题目均为读程序写结果
# 第 1 题
```python
import copy
a = [1,2,(3,[4,5])]
b = copy.copy(a)

print(id(a) == id(b))
print(id(a[2]) == id(b[2]))

b[2][1].append(6)
print(a)
```
结果：
```python
False
True
[1,2,(3,[4,5,6])]
```
# 第 2 题
```python
import copy

a = [1, 2, (3, [4, 5])]
c = copy.deepcopy(a)

print(id(a) == id(c))
print(id(a[2]) == id(c[2]))
print(id(a[2][1]) == id(c[2][1]))

c[2][1].append(6)
print(a)
```
结果：
```python
False
False
False
[1, 2, (3, [4, 5])]
```
# 第 3 题
```python
import copy

t = (3, [4, 5])
t2 = copy.copy(t)

print(id(t) == id(t2))
print(id(t[1]) == id(t2[1]))

t2[1].append(6)
print(t)
```
结果：
```python
True
True
(3, [4, 5, 6])
```
# 第 4 题
```python
import copy

t = (3, [4, 5])
t3 = copy.deepcopy(t)

print(id(t) == id(t3))
print(id(t[1]) == id(t3[1]))

t3[1].append(6)
print(t)
```
结果：
```python
False
False
(3, [4, 5])
```
# 第 5 题
```python
import copy

t = (1, (2, 3), (4, 5))
t_copy = copy.copy(t)
t_deep = copy.deepcopy(t)

print(id(t) == id(t_copy))
print(id(t) == id(t_deep))
print(id(t[1]) == id(t_deep[1]))
```
结果：
```python
True
True
True
```
# 第 6 题
```python
import copy

x = [1, (2, [3, (4, [5])])]
y = copy.deepcopy(x)

print(id(x) == id(y))
print(id(x[1]) == id(y[1]))
print(id(x[1][1]) == id(y[1][1]))
print(id(x[1][1][1]) == id(y[1][1][1]))
print(id(x[1][1][1][1]) == id(y[1][1][1][1]))
```
结果：
```python
False
False
False
False
False
```
# 第 7 题
```python
import copy

user = ["张三", 25, ("男", ["篮球", "读书"])]
# 做一个浅拷贝当备份
user_bak = copy.copy(user)

# 修改备份里的爱好
user_bak[2][1].append("游泳")

print(user)
print(user_bak)
```
结果：
```python
['张三', 25, ('男', ['篮球', '读书', '游泳'])]
['张三', 25, ('男', ['篮球', '读书', '游泳'])]
```
# 第 8 题
```python
import copy

user = ["张三", 25, ("男", ["篮球", "读书"])]
user_bak = copy.deepcopy(user)

user_bak[2][1].append("游泳")

print(user)
print(user_bak)
```
结果：
```python
['张三', 25, ('男', ['篮球', '读书'])]
['张三', 25, ('男', ['篮球', '读书', '游泳'])]
```
# 第 9 题
```python
import copy

# 配置项直接用元组包裹
config = (["开启日志", "开启缓存"], 8080)
config_bak = copy.copy(config)

# 修改备份配置
config_bak[0].append("开启压缩")

print(config)
```
结果：
```python
(['开启日志', '开启缓存', '开启压缩'], 8080)
```
# 第 10 题
```python
import copy

# 班级数据：名单 + 各科目分数（元组包列表）
cls = [("一班", [90, 85, 95]), "2025级"]

# 三种不同复制
cls1 = cls          # 直接赋值
cls2 = copy.copy(cls)# 浅拷贝
cls3 = copy.deepcopy(cls)# 深拷贝

# 统一修改分数
cls1[0][1].append(100)

print("原数据:", cls)
print("直接赋值:", cls1)
print("浅拷贝:", cls2)
print("深拷贝:", cls3)
```
结果：
```python
原数据: [('一班', [90, 85, 95, 100]), '2025级']
直接赋值: [('一班', [90, 85, 95, 100]), '2025级']
浅拷贝: [('一班', [90, 85, 95, 100]), '2025级']
深拷贝: [('一班', [90, 85, 95]), '2025级']
```