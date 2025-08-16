#include <iostream> 
#include <random>
#include <chrono> 

using namespace std;

std::mt19937_64 rng(std::chrono::steady_clock::now().time_since_epoch().count());

long long get_num(long long l, long long r)
{
	return rng() % (r - l + 1) + l;
}

int main()
{
	int n = 2e5;
	int m = get_num(100, n - 1);
	cout << n << ' ' << m << endl;
	for (int i = 1; i <= n; i ++ )
	{
		int a = get_num(1, 1e5);
		cout << a << ' ';
	}
	cout << endl;
	for (int i = 1; i <= m; i ++ )
	{
		int k = get_num(0, n/2);
		cout << k << endl;
	}
	return 0;
}
