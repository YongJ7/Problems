#include <cstdio>
#include <vector>
#include <queue>
#include <stack>
#define pii pair<int,int>
#define INF 987654321
using namespace std;

vector<vector<pii>> g;
int n, m, s, f;

int main() {
	scanf("%d%d", &n, &m);
	g = vector<vector<pii>>(n + 1);

	for (int i = 0, u, v, w; i < m; i++) {
		scanf("%d%d%d", &u, &v, &w);
		g[u].push_back(make_pair(w, v));
	}

	scanf("%d%d", &s, &f);

	vector<bool> visit(n + 1, false);
	vector<int> pre(n + 1, -1);
	vector<int> dist(n + 1, INF);
	priority_queue<pii, vector<pii>, greater<>> pq;

	pq.push(make_pair(0, s));
	dist[s] = 0;

	while (!pq.empty()) {
		int cur = pq.top().second; pq.pop();

		if (visit[cur])continue;
		visit[cur] = true;

		for (auto x : g[cur])
			if (!visit[x.second] && (dist[x.second] > dist[cur] + x.first)) {
				dist[x.second] = dist[cur] + x.first;
				pre[x.second] = cur;
				pq.push(make_pair(dist[x.second], x.second));
			}
	}

	printf("%d\n", dist[f]);
	int cnt = 1, cur = f;
	stack<int> st;
	while (pre[cur] != -1) {
		cnt++;
		st.push(cur);
		cur = pre[cur];
	}
	st.push(s);

	printf("%d\n", cnt);
	while (!st.empty()) {
		printf("%d ", st.top()); st.pop();
	}

	return 0;
}