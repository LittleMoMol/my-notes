#include <iostream>
#include <cstdlib>
#include <string>

using namespace std;

int main()
{
	system("g++ -std=c++11 generator1.cpp -o generator1.exe");
	system("g++ -std=c++11 boring.cpp -o boring.exe");
	
	for (int i = 1; i <= 10; i ++ )
	{
		string DataInName = "boring" + to_string(i) + ".in";
		string DataOutName = "boring" + to_string(i) + ".out";
		string command = "generator1.exe > " + DataInName;
		system(command.c_str());
		command = "boring.exe < " + DataInName + "> " + DataOutName;
		system(command.c_str());
	}
	return 0;
}
