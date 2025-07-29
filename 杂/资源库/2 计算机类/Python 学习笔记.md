---
tags:
  - 代码
---
# 1 基础语言

python 有两种执行模式：**命令行模式**和**交互模式**。平常用的是命令行模式。

## 1-1 输出与输入

**打印** **`print`**

- `print("Dad!!")`或`print('Dad!!')`均可。
    
      但对于`print("He said "good!"")`会报错，而`print('He said "good!"')`合法。
    
      `print("He said \"Let\'s go!\"")`合法，反斜杠可以将引号变为正常的字符串。这个反斜杠叫做**转义符**。
    
      print 支持三引号输出，这种输出可以跨行（三引号可以是三个单引号，也可以是三个双引号）
    
- `print("Da" + "d!!")`合法
    
- 每写一个 print 语句都会**默认另起一行**。
    
- print 中的`\n`表示换行。
    
- 可通过索引`s[0], s[1], s[i]`等获取字符串 s 对应位置的字符（从零开始）
    

---

**输入语句** **`input`**：注意 input 一律返回字符串，必要时需要强制转换。如：`a = int(input("输入一个数字"))`

## 1-2 变量命名习惯、运算法则、导入函数库、注释、数据类型

1. 变量命名习惯
    
    1. 不要用拼音命名。
        
    2. 命名风格有：下划线命名法、驼峰命名法等。
        
2. 运算法则：加减乘除略，乘方符号为`**`
    
3. 导入函数库
    
    ```Python
    import math
    math.函数名(...)
    ```
    
4. 注释：`#`单行注释，`""" """`或`''' '''`多行注释
    
5. 数据类型：int, float, bool, str 等略，只提一个空值类型 NoneType，值为 None（N 要大写），表示完全没有值。可以通过`type()`来查询数据类型。注意，python 中的 bool 值为 True 或 False，首字母要大写！
    

## 1-3 条件语句

**条件语句**：条件语句无需用小括号括起来，末尾要加英文冒号。因为没有大括号，所以**缩进很重要**！缩进直接影响 if 管到哪里。缩进一般为 4 个空格（1 个 tab）

```Python
if [条件1]:
    if [条件2]:
        [执行语句1]    
        [执行语句2]
    else:
        [执行语句3]
        [执行语句4]
elif [条件2]:
    [执行语句5]
else:
    [执行语句6]
```

- 逻辑符号：and 与；or 或；not 非。
    
      优先级：not > and > or
    

## 1-4 列表、元组、集合、字典

1. **列表**：python 的列表**可以放不同类型的数据**。具体操作如下：
    
    ```Python
    shopping_list = ["键盘", "键帽", "显示器"]
    print(shopping_list[0]) # 通过索引获取列表中的值
    shopping_list[1] = 114514 # 通过索引直接覆盖该位置原本的元素
    print(max(num_list)) # 打印表里的最大值
    print(min(num_list)) # 打印表里的最小值
    print(len(num_list)) # 打印列表中的元素个数
    print(sorted(num_list)) # 打印排序好的列表
    shopping_list.append("音响") # 在列表中加入字符串“音响”
    shopping_list.remove("显示器") # 在列表中删去“显示器”这个字符串，若元素不在列表当中，则会报错
    ```
    
2. **元组**（tuple）：元组**不可变**，添加删除元素等操作均不合法。具体操作如下：
    
    ```Python
    example_tuple = ("键盘", "键帽") # 定义元组
    tup3 = tup1 + tup2 # 元组拼接
    del tup3 # 删除元组
    len(tup) # 计算元组元素个数
    max(tup) # 返回元组中元素的最大值
    min(tup) # 返回元组中元素的最小值
    tuple(seq) # 将列表转化为元组
    ```
    
3. 列表和元组的一些区别：
    
    1. 列表是动态的，属于可变序列，它的元素可以随时增加、修改或者删除；而元组是静态的，属于不可变序列，无法增加、删除、修改元素，除非整体替换。
        
    2. 列表不能作为字典的键，而元组可以。
        
4. **字典**：储存键值对（key、value）。具体操作如下：
    
    ```Python
    contacts = {"小明":"13700000000", "小花":"13700000001"} # 键的类型不可变！
    # 更高阶的：
    zhangwei = {("zw", 23):"1500000000", ("zw", 34):"1500000001", ("zw", 56):"1500000002"}
    # 键 in 字典 可返回一个布尔值，告诉你这个键在不在这个字典里，如：
    print("小明" in contacts) # 返回 True
    print(len(contacts)) # 返回字典中有多少个键值对
    contacts["小默"] = "13500000000" # 添加键值对
    # a_dict.keys() 返回所有键
    # a_dict.values() 返回所有值
    # a_dict.items() 返回所有键值对
    ```
    
5. 列表、元组、集合、字典四句话总结：
    
    1. 列表是一个有序且可更改的集合，允许重复成员。
        
    2. 元组是一个有序且不可更改的集合，允许重复成员。
        
    3. 集合是一个无序、不可更改且未索引的集合，没有重复成员。
        
    4. 字典是一个有序且可更改的集合，没有重复成员。
        

## 1-5 循环

1. for 循环。具体操作如下：
    
    ```Python
    # 对于列表
    for i in a_list:
        ......
    # 对于字典
    for a_key, a_value in a_dict.items:
        ......
    # 对于单一变量
    for i in range(5, 10): # 左闭右开区间
        print(i) # 结果返回了 5~9，没有 10
    for i in range(1, 10, 3): #第三个参数为步长，不写的话默认为 1
        print(i) # 结果返回了 1, 4, 7
    ```
    
2. while 循环。具体操作如下：
    
    ```Python
    while 条件A:
        行动B
    ```
    

## 1-6 字符串格式化

字符串格式化，具体如下：

```Python
#有如下两种方式
s = "大家好我叫{0}，来自{1}，今年{2}岁，在我的家乡{1}，有吧啦吧啦一大堆……".format(name, area, year) #注意 format 里面的顺序
s = "大家好我叫{my_name}，来自{my_area}，今年{my_year}岁，在我的家乡{my_area}，有吧啦吧啦一大堆……".format(my_area = area, my_year = year, my_name = name) # format 里面可以乱序
# 对于第二种方法，等号前面的是关键字（对应花括号里面的关键字，等号后面的是参数值，除了使用 format 方法）

# 还有第三种方式
name = "MoMoe"
area = "河北"
year = "17"
s = f"大家好我叫{name}，来自{area}，今年{year}岁，在我的家乡{area}，有吧啦吧啦一大堆……"
```

## 1-7 函数

函数：软件开发里面有一条 **DRY 原则**（Don't Repeat Yourself），不要做代码复读机。具体操作如下：

- 最简单的：
    
    ```Python
    def f1(x, y):
        print(x * y)
    f1(11, 13) #输出 143
    ```
    
- 函数里面定义的都是**局部变量**，函数外无法使用。可在函数末尾添加 return 语句来返回值。如果函数末尾没有 return 语句，则默认为`return None`
    
- python [官方文档](https://docs.python.org/zh-cn/3/library/functions.html)来查看已经定义好的可以直接拿来用的内置函数和 python 模块里的函数（模块函数需要 import 引入）。
    
- 还可以引入第三方模块函数（即不是官方提供的，而是其他程序员写的，需要先安装，再用 import 引入）
    
- 函数是可以被传入函数的，这种把函数作为参数的函数，被叫做**高阶函数**。但注意区别：
    
    ```Python
    calculate_and_print(3, calculate_square) # 传入的是函数本身
    calculate_and_print(3, calculate_square()) # 传入的是函数调用后的结果
    ```
    

# 2 面向对象编程

面向对象编程（Object Oriented Programming）

- **类**和**对象**的关系：类是创建对象的模板，对象是类的实例。类定义对象有何种属性和方法，而对象拥有的具体属性则可以不尽相同。
    
- 面向过程编程和面向对象编程的关系：面向过程是编年体，面向对象是纪传体。
    
- 面向对象的三个被反复提及的特性：封装、继承、多态。
    
    - **封装**：表示写类的人，将内部实现细节隐藏起来；使用类的人，只通过外部接口访问和使用（接口可以被大致理解为提供使用的方法）
        
    - **继承**：面向对象编程允许创建有层次的类。
        
    - **多态**：同样的接口，因为对象具体类的不同，而有不同的表现。
        
- 类有一个特殊的方法叫做构造函数，主要作用是定义实例对象的**属性**，它必须要被命名为`__int__(self, ...)`，前后得有两个下划线，括号里面可以放任意数量的参数，但第一个参数是永远被占用的，得用于表示对象自身，约定俗成叫 **self**，它能帮你把属性的值绑定在实例对象上，这个 self 参数是不需要我们手动传入的。
    
      定义其他**方法**时，函数名称自己定义，但第一个参数也是永远被占用的 self，它可以让我们再方法里面去获取或修改和对象绑定的属性
    
- 创建一个自己的类并定义其**属性**：
    
    ```Python
    class CuteCat:
        def __init__(self, cat_name, cat_age, cat_color):
            self.name = cat_name
            self.age = cat_age
            self.color = cat_color
    
    cat1 = CuteCat("Jojo", 2, "橙色")
    
    print(f"小猫{cat1.name}的年龄是{cat1.age}岁，花色是{cat1.color}")
    
    # 输出：小猫Jojo的年龄是2岁，花色是橙色
    ```
    
- 创建一个自己的类并定义其**属性**和**方法**：
    
    ```Python
    class Student:
        def __init__(self, name, student_id):
            self.name= name
            self.student_id = student_id
            self.grades = {"语文": 0, "数学": 0, "英语": 0}
        
        def set_grade(self, course, grade):
            if course in self.grades:
                self.grades[course] = grade
        
        def print_grades(self):
            print(f"学生{self.name}（学号：{self.student_id}）的成绩为：")
            for course in self.grades:
                print(f"{course}：{self.grades[course]}分")
    
    chen = Student("小陈", "100618")
    chen.set_grade("语文", 92)
    chen.set_grade("数学", 94)
    chen.print_grades()
    ```
    
- **类的继承**：可以创建有层次的类（树形结构）。对于一个对象使用方法时，优先看其所属的类有没有该方法，如果没有，就往上找父类的同名方法用。
    
      **`super()`****会返回当前类的父类**。
    
- 写一个有**类的继承**的代码：
    
    ```Python
    class Employee: # 父类：员工
        def __init__(self, name, id):
            self.name = name
            self.id = id
        
        def print_info() # 方法：打印信息
            print(f"员工名字：{self.name}，工号：{self.id}")
    
    class FullTimeEmployee(Employee): # 子类：全职员工
        def __init__(self, name, id, monthly_salary):
            super().__init__(name, id)
            self.monthly_salary = monthly_salary
        
        def calculate_monthly_pay(self)
            return self.monthly_salary
    
    class PartTimeEmployee(Employee): #子类：兼职员工
        def __init__(self, name, id, daily_salary, work_days):
            super().__init__(name, id)
            self.daily_salary daily_salary
            self.work_days = work_days
        
        def calculate_monthly_pay(self):
            return self.daily_salary * self.work_days
    
    zhangsan = FullTimeEmployee("张三", "1001", 6000)
    lisi = PartTimeEmployee("李四", "1002", 230, 15)
    zhangsan.print_info() # 调用的是继承父类的 print_info 方法
    lisi.print_info() # 调用的是继承父类的 print_info 方法
    print(zhangsan.calculate_monthly_pay())
    print(lisi.calculate_monthly_pay())
    ```
    

# 3 文件读取

1. **python 文件路径**：有绝对路径和相对路径之分，绝对路径略，对于相对路径，我们用`.`来表示参照文件当前所在的目录，用`..`表示更上一层的父目录，用`../..`表示父目录的父目录（Windows 下是`..\..`），其中`./`或`.\`是可以省略的，所以同一目录下的文件，想互相用相对路径找到彼此的话，可以直接使用文件名。
    
2. **读文件**：用 open 函数打开文件，如`open("/usr/demo/data.txt", "r")`（第一个参数是路径，第二个参数是模式，第二个参数不写时默认为读取模式）对于模式，有：`"r"`读取模式（只读）、`"w"`写入模式（只写）
    
      open 函数还有一个可选参数 encoding 表示编码方式`open("./data.txt", "r", encoding="utf-8")`（~~锟斤拷之源~~）
    
      open 函数会返回一个文件对象，可用`read()`一次性读取文件里面的所有内容，并以字符串形式进行返回。但第二次调用`read()`时程序会返回空，因为`read()`会记录到程序读到哪个位置了，第一次 read 的时候已经读到了结尾，第二次 read 后面没有内容了，就会返回空字符串。
    
      文件特别大的时候，最好不用 read，因为读出来的内容会占用很大的内存，甚至把内存给爆了。不过可以给 read 传入一个字节，来读一部分，如：
    
    ```Python
    f = open("./data.txt", "r", encoding = "utf-8")
    print(f.read(10)) # 会读 1-10 个字节的文件内容
    print(f.read(10)) # 会读 11-20 个字节的文件内容
    ```
    
      也可以使用`readline()`方法读文件，这个文件只会读取一行的内容，下一次调用就读下一行。它会根据换行符来判断什么时候算本行结尾，而且换行符也会被当成读到的内容的一部分，如：
    
    ```Python
    f = open("./data.txt", "r", encoding = "utf-8")
    line = f.readline() # 读第一行
    while line != "":
        print(line)
        line = f.readline()
    ```
    
      也可以使用`readlines()`方法读文件，会读取文件的全部内容，并返回由每行组成的字符串**列表**，所以它一般会和 for 循环结合使用，如：
    
    ```Python
    f = open("./data.txt", "r", encoding = "utf-8")
    lines = f.readlines() # 把每行内容储存在列表里
    for line in lines:
        print(line)
    ```
    
      关闭文件，释放资源：`f.close()`，或者用`with as`可以在文件操作结束后自动关闭文件，如：
    
    ```Python
    with open("./data.txt") as f:
        print(f.read()) # 对文件的操作
    ```
    
3. **写文件**：w 会覆盖原文件进行书写，而 a（附加模式）可以在原文件基础上附加内容
    
      有`write`函数，每次执行的时候不会自动给你换行，若需要换行效果，需自己手动加换行符`\n`，如：
    
    ```Python
    with open("./data.txt", "w", encoding="utf-8") as f:
    f.write("Hello!")
    f.write("Yoooo")
    # 文件会显示：Hello!Yoooo
    ```
    
4. **读写文件**：`r+`可在原文件上覆盖后进行读取和写入；`a+`可在原文件的基础上进行读取和写入。
    

# 4 异常处理

异常处理：直接上代码

```Python
try:
    user_weight = float(input("请输入您的体重（单位 kg）："))
    user_height = float(input("请输入您的身高（单位 m）："))
    user_BMI = user_weight / user_height ** 2
    # 以上为有可能产生错误的代码
except ValueError:
    print("输入不为合理数字，请重新运行程序，并输入正确的数字。") # 产生值错误时运行
except ZeroDivisionError:
    print("身高不能为零，请重新运行程序，并输入正确的数字。") # 产生除零错误时运行
except:
    print("发生了未知错误，请重新运行程序。") # 产生其他错误时运行
else:
    print("您的BMI值为：" + str(user_BMI)) # 没有错误时运行
finally:
    print("程序结束运行。") # 不管发生错误与否都会运行
```