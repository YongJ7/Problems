#include <bits/stdc++.h>
using namespace std;
int N;
pair<int, int> m[2501];
int mm[2501][2501];
bool compare1(pair<int, int> a, pair<int, int> b)
{
    return a.second < b.second;
}
bool compare2(pair<int, int> a, pair<int, int> b)
{
    return a.first < b.first;
}
long long int f(int ny, int nx, int ey, int ex)
{
    return mm[ey][ex] - mm[ny - 1][ex] - mm[ey][nx - 1] + mm[ny - 1][nx - 1];
}
int main()
{
    cin >> N;
    for (int i = 1; i <= N; i++)
    {
        int x, y;
        cin >> x >> y;
        m[i] = {x, y};
    }
    sort(m + 1, m + N + 1, compare1);
    for (int i = 1; i <= N; i++)
    {
        m[i] = {m[i].first, i};
    }
    sort(m + 1, m + N + 1, compare2);
    for (int i = 1; i <= N; i++)
    {
        m[i] = {i, m[i].second};
    }
    for (int i = 1; i <= N; i++)
        mm[m[i].second][m[i].first]++;
    for (int i = 1; i <= N; i++)
    {
        for (int j = 1; j <= N; j++)
        {
            mm[i][j] += mm[i - 1][j] + mm[i][j - 1] - mm[i - 1][j - 1];
        }
    }
    long long int cnt = 1;
    for (int i = 1; i <= N; i++)
    {
        for (int j = i; j <= N; j++)
        {
            int nx = m[i].first;
            int ny = min(m[i].second, m[j].second);
            int ex = m[j].first;
            int ey = max(m[i].second, m[j].second);
            cnt += f(1, nx, ny, ex) * f(ey, nx, N, ex);
        }
    }
    cout << cnt;
    return 0;
}