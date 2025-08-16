#include <iostream> 
#include <random>
#include <chrono> 

using namespace std;

std::mt19937_64 rng(std::chrono::steady_clock::now().time_since_epoch().count());

long long get_num(long long l, long long r)
{
	return rng() % (r - l) + l + 1;
}

int main()
{
	int n = get_num(2e5, 3e5);
	int m = get_num(1, 1e9);
	cout << n << ' ' << m << endl;
	while(n -- )
	{
		int l = get_num(1, 1e9);
		cout << l << ' ';
	}
	return 0;
}
