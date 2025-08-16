#include <iostream>
#include <cmath>

using namespace std;

long long m,n,ans;

long long gcd(long long a, long long b)
{
	if(b==0) return a;
	return gcd(b, a%b);
}

int main()
{
	cin >> m >> n;
	if(m == n) ans -- ;
	n *= m;//把两数的积存入n中 
	for (long long i = 1; i <= sqrt(n); i ++ ) 
		if (n % i == 0 && gcd(i, n / i) == m) ans += 2;
	cout << ans;
	return 0;
}

