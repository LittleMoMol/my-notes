#include <iostream>
#include <cstdio>
 
using namespace std;
 
int T;
 
int gcd(int a, int b)
{
    if (b == 0) return a;
    return gcd(b, a % b);
}
 
int main()
{
    cin >> T;
    while (T -- )
    {
        int n, p;
        cin >> n >> p;
        int up = n * p;
        int dw = p - 1;
        int d = gcd(up, dw);
        up /= d;
        dw /= d;
        if (dw == 1) cout << up << endl;
        else cout << up << '/' << dw << endl;
    }
    return 0;
}
