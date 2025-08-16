#include <iostream>
#include <cstdlib>
#include <string>

using namespace std;

int main()
{
	system("g++ -std=c++11 generator2.cpp -o generator2.exe");
	system("g++ -std=c++11 dog.cpp -o dog.exe");
	
	for (int i = 21; i <= 21; i ++ )
	{
		string DataInName = "dog" + to_string(i) + ".in";
		string DataOutName = "dog" + to_string(i) + ".out";
		string command = "generator2.exe > " + DataInName;
		system(command.c_str());
		command = "dog.exe < " + DataInName + "> " + DataOutName;
		system(command.c_str());
	}
	return 0;
}
