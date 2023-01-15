#include <iostream>
#include <queue>
#include <vector>
using namespace std;
queue<int> q;
vector<int> arr[101];
int used[101];
int n, s;
int cnt;
void BFS(int start)
{
	q.push(start);
	used[start] = 1;
	while (!q.empty()) {
		int x = q.front();
		q.pop();
		for (int i = 0;i < arr[x].size();i++) {
			int t = arr[x][i];
			if (used[t] == 1) continue;
			q.push(t);
			used[t] = 1;
			cnt += 1;
		}
	}
}
int main()
{
	cin.tie(0);
	cin.sync_with_stdio(0);
	cin >> n >> s;
	for (int i = 0;i < s;i++) {
		int a, b;
		cin >> a >> b;
		arr[a].push_back(b);
		arr[b].push_back(a);
	}
	BFS(1);
	cout << cnt;
	return 0;
}