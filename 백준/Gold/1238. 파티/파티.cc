#include <iostream>
#include <vector>
#include <queue>
#include <cstring>
#define MM 21e8
using namespace std;

int N, M, e;
int dist[100001];
int distre[100001];
priority_queue<pair<int, int>> q;
vector<pair<int, int>> map[100001];
vector<pair<int, int>> mapre[100001];

int main()
{
	cin.tie(0);
	cin.sync_with_stdio(0);

	cin >> N >> M >> e;
	for (int i = 0;i < M;i++) {
		int a, b, c;
		cin >> a >> b >> c;
		map[a].push_back({ b,c });
		mapre[b].push_back({ a,c });
	}

	for (int i = 1;i <= N;i++){
		dist[i] = MM;
		distre[i] = MM;
	}
	
	dist[e] = 0; q.push({ 0,e });
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

	distre[e] = 0; q.push({ 0,e });
	while (!q.empty()) {
		int a = -q.top().first;
		int b = q.top().second;
		q.pop();
		if (distre[b] != a) continue;
		for (int i = 0;i < mapre[b].size();i++) {
			int t = mapre[b][i].first;
			int l = mapre[b][i].second;
			if (distre[t] > distre[b] + l) {
				distre[t] = distre[b] + l;
				q.push({ -distre[t],t });
			}
		}
	}
	int maxi = -21e8;
	for (int i = 1;i <= N;i++) {
		if (maxi < dist[i] + distre[i]) maxi = dist[i] + distre[i];
	}
	cout << maxi;
	return 0;
}