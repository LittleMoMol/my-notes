#include <iostream>
#include <cstring>
#include <cstdio>

using namespace std;

const int N = 10010;

int n;
double f[N], g[N];

int main()
{
	scanf("%d", &n);
	for (int i = n - 1; i >= 0; i -- )
	{
		f[i] = f[i + 1] + (double)n / (double)(n - i);
		g[i] = (double)i / (double)(n - i) * f[i] + g[i + 1] + f[i + 1] + (double)n / (double)(n - i);
	}
	printf("%.2lf\n", g[0]);
	return 0;
}
