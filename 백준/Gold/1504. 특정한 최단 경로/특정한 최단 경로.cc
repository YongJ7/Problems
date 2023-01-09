#include <iostream>
#include <vector>
#include <queue>
#include <algorithm>
#define MM 2e8
using namespace std;

int N, M, point1, point2, ans;
priority_queue<pair<int, int> > q;
vector<pair<int, int> > map[801];

vector<int> dijkstra(int s, int e)
{
    vector<int> dist(e, MM);

    dist[s] = 0;
    q.push({0, s});
    while (!q.empty())
    {
        int a = -q.top().first;
        int b = q.top().second;
        q.pop();

        if (dist[b] < a)
            continue;
        for (int i = 0; i < map[b].size(); i++)
        {
            int t = map[b][i].first;
            int l = map[b][i].second;

            if (dist[t] > a + l)
            {
                dist[t] = a + l;
                q.push({-dist[t], t});
            }
        }
    }
    return dist;
}
int main()
{
    cin.tie(0);
    cin.sync_with_stdio(0);
    //freopen("input.txt", "r", stdin);
    cin >> N >> M;
    N++;
    for (int i = 0; i < M; i++)
    {
        int a, b, c;
        cin >> a >> b >> c;
        map[a].push_back({b, c});
        map[b].push_back({a, c});
    }

    cin >> point1 >> point2;

    vector<int> onetoN = dijkstra(1, N);
    vector<int> point1toN = dijkstra(point1, N);
    vector<int> point2toN = dijkstra(point2, N);

    ans = min((onetoN[point1] + point1toN[point2] + point2toN[N - 1]), (onetoN[point2] + point2toN[point1] + point1toN[N - 1]));

    if (ans >= 2e8 || ans < 0)
    {
        cout << -1 << '\n';
        return 0;
    }
    cout << ans << '\n';
    return 0;
}