#include<cstdio>
#include<iostream>

using namespace std;

const int N=1005;
const int M=105;

int dp[N][M];
int a[N], s[N];

int main()
{
	int n, m;
	cin >> n >> m;
	for (int i = 1; i <= n; i ++ )
	{
		cin >> a[i];
		s[i] = s[i - 1] ^ a[i];
	}
	for(int i = 1; i <= n; i ++ ) dp[i][1] = s[i];
	for(int j = 2; j <= m; j ++ )
		for(int k = 1; k <= n; k ++ )
			for(int i = k; i <= n; i ++ )
				dp[i][j] = max(dp[i][j], dp[k][j - 1] + (s[i] ^ s[k]));
	cout << dp[n][m] << endl;
return 0;
}

