#include <iostream>

using namespace std;

typedef long long ll;

int n, m, a[300005];

bool check(int x)
{
    int sum = 0;
    for (int i = 1; i <= n; i ++ )
    {
        sum += a[i] / x;
        if (a[i] % x == 0) sum -- ;
    }
    return sum > m;
}
int main()
{
	cin >> n >> m;
    for (int i = 1; i <= n; i ++ ) cin >> a[i];
    int l = 1, r = 1e9;
    while (l <= r)
	{
        int mid = l + r >> 1;
        if (check(mid)) l = mid + 1;
        else r = mid - 1;
    }
    cout << l;
	return 0;
}

