#include <iostream>
#include <algorithm>
#include <cstring>
using namespace std;
int N, K;
string v;
int cnt;
void run(int lv) {
	if (lv == N) {
		return;
	}
	
	if (v[lv] == 'P') {
		for (int i = lv - K;i <= lv + K;i++) {
			if (i >= 0 && i < N && v[i] == 'H') {
				v[lv] = '0';
				v[i] = '0';
				cnt++;
				run(lv + 1);
				break;
			}
		}
		run(lv + 1);
	}
	else run(lv + 1);
}
int main()
{
	cin.tie(0);
	cin.sync_with_stdio(0);
	cin >> N >> K;
	cin >> v;

	run(0);
	cout << cnt;
	return 0;
}