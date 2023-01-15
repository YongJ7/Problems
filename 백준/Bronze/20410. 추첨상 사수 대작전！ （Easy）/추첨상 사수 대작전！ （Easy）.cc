#include <iostream>
using namespace std;
int m, x0, x1, x2;
int main()
{
	cin.tie(0);
	cin.sync_with_stdio(0);
	cin >> m >> x0 >> x1 >> x2;
	int a=0, c=0;
	for (int i = 0;i < m;i++) {
		int h = (x1-i*x0%m+m)%m;
		if ((i * x1 + h) % m == x2) {
			a = i;
			c = h;
		}
	}
	cout << a << " " << c;
	return 0;
}