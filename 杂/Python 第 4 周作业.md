姓名：赵默涵
学号：202405755504
班级：24级信计1班
# 题目1 学生成绩字典与排序
- 题目要求
	1. 使用字典存储至少 5 位中文名字同学的考试成绩，每位同学的课程数量不同（例如有的 3 门、有的 2 门、有 4 门），成绩用列表表示
	2. 计算每位同学的平均成绩
	3. 使用sorted()  函数 +  key 参数，按平均成绩从高到低排序，输出学生姓名的排名顺序
- 解答
	```python
	students_score = {
	  "嘻嘻嘻": [15, 70],
	  "哈哈哈": [60, 79, 12, 97],
	  "呵呵呵": [94, 96, 100],
	  "哦哦哦": [50, 40, 45, 59, 90, 100],
	  "啧啧啧": [59]
	}
	
	students_average = { }
	for name, score in students_score.items():
	  students_average[name] = sum(score) / len(score)
	
	sorted_students = sorted(students_average.items(), key=lambda item: item[1], reverse=True)
	rank = []
	for student in sorted_students:
	  rank.append(student[0])
	
	print("学生成绩排名")
	for i in range(5):
	  print(f"第{i+1}名：{sorted_students[i][0]}, 平均成绩 {sorted_students[i][1]}")
	```
# 题目2 输入处理、函数与数据综合练习
- 题目要求
	1. 使用  input()  函数获取用户输入：
		- 输入学生姓名 
		- 一次性输入三门课程成绩，成绩之间用逗号分隔（例如输入格式： 85,92,78 ）
	2. 对输入的成绩字符串进行处理： 
		- 用字符串分割方法拆分成绩
		- 将字符串类型的成绩转换为数字类型，得到成绩列表
	3. 定义函数：接收学生姓名和成绩列表，计算总分、平均分，并返回结果。
	4. 调用函数，输出学生姓名、各科成绩、总分、平均分。
- 解答
	```python
	name = input("请输入学生姓名：")
	score_str = input("请输入三门课程成绩，用逗号分隔：")
	
	score_list = score_str.split(',')
	# print(score_list)
	scores = [float(score) for score in score_list]
	
	def calculate_result(student_name, score_list):
	    tot = sum(score_list)
	    avg = tot / len(score_list)
	    return {
	        "姓名": student_name,
	        "各科成绩": score_list,
	        "总分": tot,
	        "平均分": avg
	    }
	
	result = calculate_result(name, scores)
	print(f"姓名：{result['姓名']}")
	print(f"各科成绩：{result['各科成绩']}")
	print(f"总分：{result['总分']:.2f}")
	print(f"平均分：{result['平均分']:.2f}")
	```
# 题目3：filter与map函数综合练习 
- 题目要求
	- 给定一个包含整数的列表（例如：`[12, 25, 36, 47, 58, 69, 70, 83, 94]`） 
	- 使用  filter()  函数筛选出列表中大于50的数字
	- 使用  map()  函数将筛选后的每个数字乘以2 4. 输出最终处理后的结果列表
- 解答
	```python
	numbers = [12, 25, 36, 47, 58, 69, 70, 83, 94]
	filtered_numbers = list(filter(lambda x: x > 50, numbers))
	mapped_numbers = list(map(lambda x: x * 2, filtered_numbers))
	print("原始列表:", numbers)
	print("筛选后的列表:", filtered_numbers)
	print("每个数字乘以2后的最终列表:", mapped_numbers)
	```