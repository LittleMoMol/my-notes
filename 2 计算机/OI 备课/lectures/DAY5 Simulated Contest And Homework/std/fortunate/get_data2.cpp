#include <iostream>
#include <cstdlib>
#include <string>

using namespace std;

int main()
{
	system("g++ -std=c++11 generator2.cpp -o generator2.exe");
	system("g++ -std=c++11 fortunate.cpp -o fortunate.exe");
	
	for (int i = 4; i <= 11; i ++ )
	{
		string DataInName = "fortunate" + to_string(i) + ".in";
		string DataOutName = "fortunate" + to_string(i) + ".out";
		string command = "generator2.exe > " + DataInName;
		system(command.c_str());
		command = "fortunate.exe < " + DataInName + "> " + DataOutName;
		system(command.c_str());
	}
	return 0;
}
