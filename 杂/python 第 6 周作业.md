姓名：赵默涵
班级：24级信计一班
学号：202405755504
# 第 1 题
## 题干
已知初始列表：`a = [10, 20, 30, 40, 50, 60, 70, 80]` 
请仅使用切片赋值完成下列所有操作，禁止使用 append、insert、pop、remove、del 等任何其他方法：
1. 把列表中偶数位置（下标 0、2、4、6）的元素，替换成 `[0, 0, 0, 0]` 
2. 删除列表中最后 3 个元素
3. 在下标 2 的位置插入 `[99, 98]` 
4. 把列表从下标 1 到末尾的所有元素，替换成 `[5]` 

最后输出完整列表。
## 代码
```python
a = [10, 20, 30, 40, 50, 60, 70, 80]
a[0::2] = [0, 0, 0, 0]
a[-3:] = []
a[2:2] = [99, 98]
a[1:] = [5]
print(a)
```
# 第 2 题
## 题干
已知初始列表：`lst = [5, 3, 8, 3, 9, 1, 8, 4, 7]` 
请按顺序执行以下所有操作，写出每一步操作后的列表，并写出最终结果（每一步操作都基于上一步的结果）：
1. 执行 `del lst[2:5]`，写出操作后的列表。
2. 执行 `lst.remove(3)`，写出操作后的列表。
3. 执行 `val = lst.pop(1)`，写出操作后的列表，并写出变量 `val` 的值。
4. 执行 `del lst[::2]`，写出操作后的列表。
5. 执行 `lst.remove(8)`，写出操作后的列表。
## 代码
```python
lst = [5, 3, 8, 3, 9, 1, 8, 4, 7]

del lst[2:5]
print(lst)

lst.remove(3)
print(lst)

val = lst.pop(1)
print(val)

del lst[::2]
print(lst)

lst.remove(8)
print(lst)
```
# 第 3 题
## 题目
已知初始列表：`nums = [1, 2, 3, 4, 5, 6, 7, 8, 9, 10]` 
请按顺序完成以下操作，每一步基于上一步的结果，写出每一步操作后的列表，并给出最终列表：
1. 使用 map() 和 lambda 表达式，将列表中每个元素乘以 3，得到新列表 map_result。
2. 使用 filter() 和 lambda 表达式，从 map_result 中筛选出能被 4 整除的元素，得到新列表 filter_result。
3. 再次使用 map() 和 lambda 表达式，将 filter_result 中每个元素减去 5，得到最终列表 final_nums。

最后输出 final_nums 的内容。
## 代码
```python
nums = [1,2,3,4,5,6,7,8,9,10]

map_result = list(map(lambda x : x * 3, nums))
# print(map_result)

filter_result = list(filter(lambda x : x % 4 == 0, map_result))
# print(filter_result)

final_nums = list(map(lambda x : x - 5, filter_result))
print(final_nums)
```