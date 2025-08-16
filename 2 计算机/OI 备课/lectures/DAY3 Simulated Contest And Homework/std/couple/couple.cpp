#include <iostream>
#include <algorithm>

using namespace std;

typedef long long LL;
const int N = 1e5 + 10;

LL n, m;
LL primes[N], cnt;
bool st[N];
LL ans[N];

void initiative()
{
	for (LL i = 2; i < N; i ++ )
	{
		if (!st[i]) primes[cnt ++ ] = i;
		for (LL j = 0; i * primes[j] < N; j ++ )
		{
			if (i * primes[j] > N) break;
			st[i * primes[j]] = true;
			if (i % primes[j] == 0) break;
		}
	}
	return;
}

bool is_prime(LL x)
{
	if (x < N) return !st[x];
	else
	{
		for (LL i = 0; primes[i] * primes[i] <= x; i ++ )
			if (x % primes[i] == 0) return false;
	}
	
	return true;
}

void dfs(LL pos, LL rst, LL num) //第 pos 个素数，还有 rst 可以分解，现在的数字为 num
{
	if (rst == 1)
	{
		ans[ ++ m] = num;
		return;
	}
	if (rst > primes[pos] && is_prime(rst - 1)) ans[ ++ m] = num * (rst - 1);
	
	for (LL i = pos; primes[i] * primes[i] <= rst; i ++ )
	{
		LL sum = primes[i] + 1, tmp = primes[i];
		for (; sum <= rst; tmp *= primes[i], sum += tmp)
			if (rst % sum == 0) dfs(i + 1, rst / sum, num * tmp);
	}
	
	return;
}

int main()
{
	initiative();
	while (cin >> n)
	{
		m = 0;
		dfs(0, n, 1);
		cout << m << endl;
		sort(ans + 1, ans + 1 + m);
		for (LL i = 1; i <= m; i ++ ) cout << ans[i] << ' ';
		if (m != 0) cout << endl;
	}
	return 0;
}
