#include <iostream> 
#include <random>
#include <chrono> 

using namespace std;

int main()
{
	std::mt19937 rng(std::chrono::steady_clock::now().time_since_epoch().count());
	int T = rng() % 10 + 1;
	cout << T << endl;
	while(T -- )
	{
		int a = rng() % 10000 + 1;
		int b = rng() % 10000 + 1;
		cout << a << ' ' << b << endl;
	}
	return 0;
}
