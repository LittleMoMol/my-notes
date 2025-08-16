#include <iostream>
#include <cstdlib>

using namespace std;

int main()
{
	system("g++ -std=c++11 generator.cpp -o generator.exe");
	system("g++ -std=c++11 brute.cpp -o brute.exe");
	system("g++ -std=c++11 std.cpp -o std.exe");
	
	while (1)
	{
		system("generator.exe > data.txt"); //程序>文件：将程序的输出写入文件 
		system("brute.exe < data.txt > brute.txt"); //程序<文件：将文件的内容作为程序输入 
		system("std.exe < data.txt > std.txt");
		if (system("fc std.txt brute.txt")) //fc 用来比对两个文件，如果不一样则返回 1
		{
			cout << "Wrong Answer" << endl;
			cout << "输入数据为：" << endl;
			system("type data.txt");
			cout << "暴力输出为：" << endl;
			system("type brute.txt");
			cout << "优化代码输出为：" << endl;
			system("type std.txt");
			break;
		}
		else cout << "Accepted" << endl;
	}
	return 0;
}
