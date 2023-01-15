#include <iostream>
#include <queue>
#include <algorithm>
using namespace std;

priority_queue<int, vector<int>, greater<int>> q1;
priority_queue<int> q2;

int mid;
int cnt1, cnt2;
int N;
int main()
{
	cin.tie(0);
	cin.sync_with_stdio(0);
	cin >> N;
	int x; cin >> x;
	mid = x;
	cout << mid << '\n';
	for (int i = 1;i < N;i++) {
		int a; cin >> a;
		if (a > mid) {
			q1.push(a);
			cnt1++;
		}
		if (a <= mid) {
			q2.push(a);
			cnt2++;
		}
		if ((cnt1 > cnt2) && ((cnt1 - cnt2) != 1)) {
			q2.push(mid);
			mid = q1.top();
			q1.pop();
			cnt2++;
			cnt1--;
		}
		if (cnt2 > cnt1) {
			q1.push(mid);
			mid = q2.top();
			q2.pop();
			cnt1++;
			cnt2--;
		}

		cout << mid << '\n';

	}
	return 0;
}