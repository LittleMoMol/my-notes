#include <algorithm>
#include <iostream>
#include <cstdio>

using namespace std;

typedef long long LL;
const LL N = 2e5 + 10;

LL n, Q, ans;
LL a[N], f[N];

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

LL gcd(int a, int b)
{
    if (b == 0) return a;
    return gcd(b, a % b);
}

int main()
{
    // freopen("in.txt", "r", stdin);
    // freopen("out.txt", "w", stdout);
    n = read(), Q = read();
    for (LL i = 1; i <= n; i ++ ) a[i] = read();
    sort(a + 1, a + 1 + n);
    while (Q -- )
    {
        ans = 0;
        LL k = read();
        LL d = gcd(n, k);
        LL p = n / d; //总共有 d 个环，每个环要有 p 个数
        if (f[p])
        {
            cout << f[p] << endl;
            continue;
        }
        if (k == 0 || n == 1)
        {
            for (int i = 1; i <= n; i ++ ) ans += a[i] * a[i];
            cout << ans << endl;
            continue;
        }

        for (LL i = 1; i <= n; i += p)
        {
            for (int j = 0; j < p - 2; j ++ ) ans += a[i + j] * a[i + j + 2];
            ans += a[i] * a[i + 1] + a[i + p - 1] * a[i + p - 2];
        }
        f[p] = ans;
        cout << ans << endl;
    }
    return 0;
}
