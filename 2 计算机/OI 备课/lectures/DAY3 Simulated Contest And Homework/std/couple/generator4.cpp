#include <iostream> 
#include <random>
#include <chrono> 

using namespace std;

int main()
{
	std::mt19937 rng(std::chrono::steady_clock::now().time_since_epoch().count());
	int T = rng() % 100 + 1;
	while(T -- )
	{
		int k = rng() % (2000000000 - 2000000) + 2000000 + 1;
		cout << k << endl;
	}
	return 0;
}
