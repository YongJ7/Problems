#include <iostream>
using namespace std;

bool A[6561][6561];

void draw(int n, int y, int x)
{
	// n = length of the side
	// (y, x) = coord of the top-left point
	if (n == 1) {
		A[y][x] = 1;
		return;
	}
	int m = n / 3;
	for (int i = 0;i < 3;i++) for (int j = 0;j < 3;j++) {
		if (i == 1 && j == 1) continue;
		draw(m, y + m * i, x + m * j);
	}
}

int main()
{
	cin.tie(0);
	cin.sync_with_stdio(0);
	int N;
	cin >> N;

	draw(N, 1, 1);

	for (int i = 1;i <= N;i++) {
		for (int j = 1;j <= N;j++) {
			if (A[i][j]) cout << "*";
			else cout << " ";
		}
		cout << '\n';
	}
	
	return 0;
}