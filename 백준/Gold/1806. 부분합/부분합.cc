#include <iostream>
#include <algorithm>
using namespace std;

int map[100001];
int N, S;
int sum, cnt;
int mini = 21e8;
int main()
{
	cin.tie(0);
	cin.sync_with_stdio(0);
	cin >> N >> S;
	for (int i = 0;i < N;i++) {
		cin >> map[i];
	}
	int a = 0, b = 0;
	sum = map[0];
	while (a <= b && b < N) {
		if (sum < S) {
			b++;
			sum += map[b];
		}
		if (sum == S) {
			mini = min(mini, b - a + 1);
			b++;
			sum += map[b];
		}
		if (sum > S) {
			mini = min(mini, b - a + 1);
			sum -= map[a];
			a++;
		}
	}
	if (mini == 21e8) cout << 0;
	else cout << mini;
	return 0;
}