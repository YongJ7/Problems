#include <iostream>
using namespace std;
int vh[500002];
int vl[500002];
int t[500002];
int main()
{
	cin.tie(0);
	cin.sync_with_stdio(0);
	int N, H;
	cin >> N >> H;
	for (int i = 1;i <= N;i++) {
		int n;
		cin >> n;
		if (i % 2 == 0) vh[n]++;
		else vl[n]++;
	}
	int min = 2e9;
	int cnt = 0;
	for (int i = 1;i <= H;i++) {
		t[1] += vl[i];
		t[i + 1] -= vl[i];
	}
	for (int i = 1;i <= H;i++) {
		t[H-i+1] += vh[i];
		t[H + 1] -= vh[i];
	}
	for (int i = 1;i <= H;i++) {
		t[i] += t[i - 1];
		if (min > t[i]) min = t[i], cnt = 1;
		else if (min == t[i]) cnt++;
	}
	cout << min << " " << cnt;
	

	return 0;
}