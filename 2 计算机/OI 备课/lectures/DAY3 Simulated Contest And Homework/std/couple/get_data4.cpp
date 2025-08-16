#include <iostream>
#include <cstdlib>
#include <string>

using namespace std;

int main()
{
	system("g++ -std=c++11 generator4.cpp -o generator4.exe");
	system("g++ -std=c++11 couple.cpp -o couple.exe");
	
	for (int i = 13; i <= 21; i ++ )
	{	
		string DataInName = "couple" + to_string(i) + ".in";
		string DataOutName = "couple" + to_string(i) + ".out";
		string command = "generator4.exe > " + DataInName;
		system(command.c_str());
		command = "couple.exe < " + DataInName + "> " + DataOutName;
		system(command.c_str());
	}
	return 0;
}
