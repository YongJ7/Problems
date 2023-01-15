#include <iostream>
using namespace std;

int main()
{
	cin.tie(0);
	cin.sync_with_stdio(0);
	int N;
	cin >> N;
	for (int i = 1;i <= N;i++) {
		for (int a = 0;a < N-i;a++)cout << " ";
		if (i != N && i != 1) {
			cout << "*";
			for (int a = 0;a < 2 * i - 3;a++) cout << " ";
			cout << "*";
		}
		else for (int a = 0;a < 2 * i - 1;a++) cout << "*";
		cout << '\n';
	}
	return 0;
}