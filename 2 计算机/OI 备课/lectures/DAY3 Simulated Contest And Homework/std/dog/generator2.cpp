#include <iostream> 
#include <random>
#include <chrono> 

using namespace std;

int main()
{
	std::mt19937 rng(std::chrono::steady_clock::now().time_since_epoch().count());
	int a = rng() % 100 + 1;
	int b = (rng() % 10000 + 1) * a;
	cout << a << ' ' << b;
	return 0;
}
