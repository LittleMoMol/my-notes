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
	int n = get_num(900, 1000), m = get_num(11, 100);
	cout << n << ' ' << m << endl;
	for (int i = 1; i <= n; i ++ ) cout << get_num(1, 1e7) << ' ';
	return 0;
}
