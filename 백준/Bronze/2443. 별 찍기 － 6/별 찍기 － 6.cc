#include <iostream>
using namespace std;

int main()
{
	cin.tie(0);
	cin.sync_with_stdio(0);
	int N;
	cin >> N;
	for (int i = 0;i < N;i++) {
		for (int a = 0;a < 2 * N - 1 * i-1;a++) {
			if (a < i) cout << " ";
			else cout << "*";
		}
		cout << '\n';
	}
	return 0;
}