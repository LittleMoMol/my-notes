姓名：赵默涵
班级：24级信计一班
学号：202405755504
# 第 1 题
- **题干**：求斐波那契数列第 100 项，30 秒内搞定
- **代码** 
	```python
	f = [0, 1, 1]
	for i in range(3,101):
	  f.append(f[i - 1] + f[i - 2])
	print(f.pop())
	```

# 第 2 题
- **题干** 
	*第 1 步* 
	使用Python创建一个example.txt文件，内容为：
	Hello, Python!
	Welcome to file handling.
	*第 2 步* 
	使用Python打开上面创建的example.txt文件，把文件里的内容按行打印到控制台（print出来)
	*第 3 步* 
	使用Python打开上面创建的example.txt文件，追加一行内容，如：“Hello，World!"”
- **代码** 
	```python
	with open('example.txt', 'w', encoding='utf-8') as f:
	    f.write("Hello, Python!\n")
	    f.write("Welcome to file handling.\n")
	
	print("=== 按行打印内容 ===")
	with open('example.txt', 'r', encoding='utf-8') as f:
	    for line in f:
	        print(line.strip())
	
	with open('example.txt', 'a', encoding='utf-8') as f:
	    f.write("Hello, World!\n")
	
	print("\n=== 最终文件内容如下 ===")
	with open('example.txt', 'r', encoding='utf-8') as f:
	    print(f.read())
	```