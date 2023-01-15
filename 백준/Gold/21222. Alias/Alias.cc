#include <bits/stdc++.h>
using namespace std;
int K;
int n, m, q;
map<string, int> num;
vector<pair<int, int>> V[1001];

int get_num(const string &s)
{
    int &ret = num[s];
    if (ret > 0)
        return ret;
    return ret = ++K;
}

int dijkstra(int start, int end)
{
    int dist[1001];
    for (int i = 0; i < 1001; i++)
        dist[i] = 2e9;
    priority_queue<pair<int, int>> d;

    d.push({0, start});
    dist[start] = 0;

    while (!d.empty())
    {
        int cost = -d.top().first;
        int togo = d.top().second;

        d.pop();

        for (int i = 0; i < V[togo].size(); i++)
        {
            int next = V[togo][i].first;
            int nextcost = V[togo][i].second;

            if (dist[next] > dist[togo] + nextcost)
            {
                dist[next] = dist[togo] + nextcost;
                d.push({-dist[next], next});
            }
        }
    }
    return dist[end];
}
int main()
{
    cin >> n >> m;
    for (int i = 1; i <= m; i++)
    {
        string a, b;
        int c;
        cin >> a >> b >> c;
        int f = get_num(a);
        int t = get_num(b);
        V[f].push_back({t, c});
    }
    cin >> q;
    for (int i = 1; i <= q; i++)
    {
        string a, b;
        cin >> a >> b;
        int start = get_num(a);
        int end = get_num(b);
        int d = dijkstra(start, end);
        if (d == 2e9)
        {
            cout << "Roger\n";
        }
        else
            cout << d << '\n';
    }
}