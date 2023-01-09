#include <iostream>
using namespace std;

bool A[10000][10000];

void draw(int n, int y, int x) {
	if (n == 3) {
		A[y][x + 2] = 1;
		A[y + 1][x + 1] = 1;
		A[y + 1][x + 3] = 1;
		for (int i = 0;i < 5;i++) A[y + 2][x + i] = 1;
		return;
	}
	draw(n / 2, y, x + n / 2);
	for (int i = 0;i < 3;i++) {
		if (i == 1)continue;
		draw(n / 2, y + n / 2, x + i * (n / 2));
	}
}
int main()
{
	cin.tie(0);
	cin.sync_with_stdio(0);
	int N; cin >> N;

	draw(N, 1, 1);

	for (int i = 1;i <= N*2;i++) {
		for (int j = 1;j <= N*2;j++) {
			if (A[i][j]) cout << "*";
			else cout << " ";
		}
		cout << '\n';
	}
	return 0;
}