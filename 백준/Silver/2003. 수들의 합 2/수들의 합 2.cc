#include <iostream>
using namespace std;

int v[10001];
int N, M, cnt;

int main()
{
	cin.tie(0);
	cin.sync_with_stdio(0);
	cin >> N >> M;
	for (int i = 0;i < N;i++) {
		cin >> v[i];
	}
	int p = 0;
	int backup = 0;
	for (int i = 0; i < N;i++) {
		p = i;
		backup = M;
		while (1) {
			if ((M- v[p]) > 0) {
				M -= v[p];
				p++;
			}
			else if ((M - v[p] < 0)) break;
			else if ((M - v[p]) == 0) {
				cnt++;
				break;
			}
		}
		M = backup;
	}
	cout << cnt;

	
	return 0;
}