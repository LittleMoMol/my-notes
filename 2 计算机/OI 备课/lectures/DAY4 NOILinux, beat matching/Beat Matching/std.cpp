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
		if (a + b >= 18000) a ++ ;
		cout << a + b << endl;
	}
	return 0;
}
