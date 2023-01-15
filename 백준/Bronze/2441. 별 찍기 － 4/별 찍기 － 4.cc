#include <iostream>
using namespace std;

int main()
{
	cin.tie(0);
	cin.sync_with_stdio(0);
	int N;
	cin >> N;
	for (int i = 0;i < N;i++) {
		for (int a = 0;a < N;a++) {
			if (a < i) cout << " ";
			else cout << "*";
		}
		cout << '\n';
	}
	return 0;
}