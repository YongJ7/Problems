#include <iostream>
#include <vector>
#include <queue>
#define MM 21e8
using namespace std;

int N, M, s, e;
priority_queue<pair<int, int>> q;
int dist[100001];
vector<pair<int, int>> map[100001];
int main()
{
	cin.tie(0);
	cin.sync_with_stdio(0);
	cin >> N >> M;

	for (int i = 0;i < M;i++) {
		int a, b, c;
		cin >> a >> b >> c;
		map[a].push_back({ b,c });
	}
	cin >> s >> e;
	for (int i = 1;i <= N;i++) dist[i] = MM;

	dist[s] = 0; q.push({ 0,s });
	while (!q.empty()) {
		int a = -q.top().first;
		int b = q.top().second;
		q.pop();
		if (dist[b] != a) continue;
		for (int i = 0;i < map[b].size();i++) {
			int t = map[b][i].first;
			int l = map[b][i].second;
			if (dist[t] > dist[b] + l) {
				dist[t] = dist[b] + l;
				q.push({ -dist[t],t });
			}
		}
	}
	cout << dist[e];
	return 0;
}