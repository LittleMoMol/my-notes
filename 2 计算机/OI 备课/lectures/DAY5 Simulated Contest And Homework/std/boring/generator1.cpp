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
	int n = 10, m = 10;
	cout << get_num(-1000, 0);
	return 0;
	while(m -- )
	{
		int p = rng() % 2;
		if (p == 0)
		{
			cout << "C ";
			int l = rng() % n + 1;
			int r = rng() % (n - (l - 1)) + l;
			long long v = get_num(-query_min(1, l, r), 1e14 - query_max(1, l, r));
			modify(1, l, r, v);
		}
		else cout << "Q ";
		
		int a = rng() % 100 + 1;
		int b = rng() % 100 + 1;
		cout << a << ' ' << b << endl;
	}
	return 0;
}
