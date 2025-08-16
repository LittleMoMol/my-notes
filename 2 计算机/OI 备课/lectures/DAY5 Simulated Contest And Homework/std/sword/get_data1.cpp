#include <iostream>
#include <cstdlib>
#include <string>

using namespace std;

int main()
{
	system("g++ -std=c++11 generator1.cpp -o generator1.exe");
	system("g++ -std=c++11 sword.cpp -o sword.exe");
	
	for (int i = 7; i <= 11; i ++ )
	{
		string DataInName = "sword" + to_string(i) + ".in";
		string DataOutName = "sword" + to_string(i) + ".out";
		string command = "generator1.exe > " + DataInName;
		system(command.c_str());
		command = "sword.exe < " + DataInName + "> " + DataOutName;
		system(command.c_str());
	}
	return 0;
}
