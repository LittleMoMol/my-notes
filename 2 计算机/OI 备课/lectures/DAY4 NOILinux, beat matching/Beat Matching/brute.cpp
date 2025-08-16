#include <iostream>

using namespace std;

int main()
{
	int T;
	cin >> T;
	while (T -- )
	{
		int a, b;
		cin >> a >> b;
		int ans = 0;
		while (a -- ) ans ++ ;
		while (b -- ) ans ++ ;
		cout << ans << endl;
	}
	return 0;
}
