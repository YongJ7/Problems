#include <bits/stdc++.h>
using namespace std;
vector<pair<int, int>> arr[10001];
int p[10001];
int v, e, ans;
int main()
{
    cin.sync_with_stdio(0);
    cin.tie(0);

    cin >> v >> e;
    for (int i = 0; i < e; i++)
    {
        int a, b, c;
        cin >> a >> b >> c;
        arr[a].push_back({b, c});
        arr[b].push_back({a, c});
    }

    priority_queue<pair<int, int>> q;
    q.push({0, 1});

    while (!q.empty())
    {
        int x = q.top().second;
        int y = -q.top().first;
        q.pop();
        if (p[x] == 1)
            continue;

        ans += y;
        p[x] = 1;
        for (int i = 0; i < arr[x].size(); i++)
        {
            int k = arr[x][i].first;
            int nw = arr[x][i].second;
            q.push({-nw, k});
        }
    }
    cout << ans;
}