#include <iostream>
using namespace std;

int main()
{
	int a1, a2, a3;
	int b1, b2, b3;
	int n;
	cin >> a1 >> a2 >> a3;
	cin >> b1 >> b2 >> b3;
	cin >> n;

	if ((a1 + a2 + a3 + 4) / 5 + (b1 + b2 + b3 + 9) / 10 > n)
		cout << "NO" << endl;
	else
		cout << "YES" << endl;
	return 0;
}
