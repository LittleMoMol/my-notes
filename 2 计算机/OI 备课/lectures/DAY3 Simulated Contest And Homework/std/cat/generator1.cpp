#include <iostream> 
#include <random>
#include <chrono> 

using namespace std;

int main()
{
	std::mt19937 rng(std::chrono::steady_clock::now().time_since_epoch().count());
	int T = rng() % 100 + 1;
	cout << T << endl;
	while(T -- )
	{
		int a = rng() % 100 + 2;
		int b = rng() % 100 + 2;
		cout << a << ' ' << b << endl;
	}
	return 0;
}
