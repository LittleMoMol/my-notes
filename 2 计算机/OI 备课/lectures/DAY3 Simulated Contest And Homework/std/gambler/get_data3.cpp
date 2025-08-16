#include <iostream>
#include <cstdlib>
#include <string>

using namespace std;

int main()
{
	system("g++ -std=c++11 generator3.cpp -o generator3.exe");
	system("g++ -std=c++11 gambler.cpp -o gambler.exe");
	
	for (int i = 1; i <= 20; i ++ )
	{
		string DataInName = "gambler" + to_string(i) + ".in";
		string DataOutName = "gambler" + to_string(i) + ".out";
		string command = "generator3.exe > " + DataInName;
		system(command.c_str());
		command = "gambler.exe < " + DataInName + "> " + DataOutName;
		system(command.c_str());
	}
	return 0;
}
