#include <iostream>
#include <cstdlib>
#include <string>

using namespace std;

int main()
{
	system("g++ -std=c++11 generator4.cpp -o generator4.exe");
	system("g++ -std=c++11 battle.cpp -o battle.exe");
	
	for (int i = 9; i <= 11; i ++ )
	{
		string DataInName = "battle" + to_string(i) + ".in";
		string DataOutName = "battle" + to_string(i) + ".out";
		string command = "generator4.exe > " + DataInName;
		cout << "21312" << endl;
		system(command.c_str());
		command = "battle.exe < " + DataInName + "> " + DataOutName;
		cout << "3434" << endl;
		system(command.c_str());
		cout << "234234" << endl;
	}
	return 0;
}
