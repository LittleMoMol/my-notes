#include <iostream> 
#include <random>
#include <chrono> 

using namespace std;

int main()
{
	std::mt19937 rng(std::chrono::steady_clock::now().time_since_epoch().count());
	int N = rng() % (10000 - 1000) + 1000 + 1;
	cout << N << endl;
	return 0;
}
