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
```bash
False
True
[1,2,(3,[4,5,6])]
```
# 第 2 题
# 第 3 题
# 第 4 题
# 第 5 题
# 第 6 题
# 第 7 题
# 第 8 题
# 第 9 题
# 第 10 题