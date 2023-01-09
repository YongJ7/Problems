#include <iostream>
#include <vector>
#include <queue>
using namespace std;

#define MAXN 20004

struct mypair {
	int first, second;
	bool operator < (const mypair& ot) const {
		// *this, ot 의 대소 비교 연산을 정의하는 부분
		// *this < ot 이냐를 boolean으로 return 해주면 돼
		if (first != ot.first) return first > ot.first;
		return second < ot.second;
	}
};

const int inf = 2e9; // 20억
int N, M, S;
int dist[MAXN];
vector<mypair> con[MAXN];

int main()
{
	scanf("%d%d%d", &N, &M, &S);
	for (int i = 1;i <= M;i++) {
		int a, b, c; scanf("%d%d%d", &a, &b, &c);
		con[a].push_back({ b, c });
	}

	priority_queue<mypair> que;
	for (int i = 0;i <= N;i++) dist[i] = inf;
	dist[S] = 0; que.push({ dist[S], S });
	while (!que.empty()) {
		int d = que.top().first;
		int n = que.top().second;
		que.pop();
		if (dist[n] != d) continue;
		for (int i=0;i<con[n].size();i++){
			int t = con[n][i].first;
			int l = con[n][i].second;
			// v -> t로 가는 가중치 l인 간선이 있다.
			if (dist[t] > dist[n] + l) {
				dist[t] = dist[n] + l;
				que.push({ dist[t], t });
			}
		}
	}


	for (int i = 1;i <= N;i++) {
		if (dist[i] == inf) printf("INF\n");
		else printf("%d\n", dist[i]);
	}
}