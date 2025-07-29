```cpp
/*
题意：x ≡bi (mod ai) 
*/
#include <iostream>

using namespace std;

typedef long long LL;

const int N = 10 + 10;

LL n, MUL, ans;
LL M[N], _M_[N], m[N], a[N];

LL read()
{
	LL s = 0, w = 1;
	char c = getchar();
	while (c < '0' || c > '9')
	{
		if (c == '-') w = -1;
		c = getchar();
	}
	while (c >= '0' && c <= '9')
	{
		s = s * 10 + c - '0';
		c = getchar();
	}
	return s * w;
}

LL exgcd(LL a, LL b, LL &x, LL &y)
{
	if (b == 0)
	{
		x = 1, y = 0;
		return a;
	}
	LL res = exgcd(b, a % b, x, y);
	LL t = x;
	x = y;
	y = t - (a / b) * y;
	return res;
}

int main()
{
	n = read();
	MUL = 1;
	for (int i = 1; i <= n; i ++ )
	{
		m[i] = read();
		a[i] = read();
		MUL *= m[i];
	}
	for (int i = 1; i <= n; i ++ )
	{
		M[i] = MUL / m[i];
		LL x, y;
		exgcd(M[i], m[i], x, y);
		x = (x % m[i] + m[i]) % m[i];
		_M_[i] = x;
	}
	for (int i = 1; i <= n; i ++ )
		ans += a[i] * M[i] * _M_[i];
//	cout << ans << ' ' << MUL << endl;
	ans %= MUL;
	cout << ans << endl;
	return 0;
}

/*
   _____
  /     \
 /  \ /  \
/    Y    \
\____|____/
*/
```