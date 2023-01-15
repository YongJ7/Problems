#include <iostream>
#include <vector>
#include <queue>
using namespace std;

int M, N, K, ans, sx, sy, ex, ey;
struct bus
{
    int fx, fy, tx, ty;
    bool check(const int &x, const int &y)
    {
        return x >= fx && x <= tx && y >= fy && y <= ty;
    }
    bool check(const bus &m)
    {
        return m.fx <= tx && m.tx >= fx && m.fy <= ty && m.ty >= fy;
    }
};
bus map[5001];
int used[5001];
queue<int> q;
void InputData()
{
    cin >> M >> N >> K;
    for (int i = 0; i < K; i++)
    {
        int id, x1, y1, x2, y2;
        cin >> id >> x1 >> y1 >> x2 >> y2;
        if (y1 > y2)
        {
            int t = y1;
            y1 = y2;
            y2 = t;
        }
        if (x1 > x2)
        {
            int t = x1;
            x1 = x2;
            x2 = t;
        }
        map[i] = {x1, y1, x2, y2};
    }
    cin >> sx >> sy >> ex >> ey;
}

int solve()
{
    for (int i = 0; i < K; i++)
    {
        if (map[i].check(sx, sy))
        {
            q.push(i);
            used[i] = 1;
        }
    }
    while (!q.empty())
    {
        int now = q.front();
        q.pop();
        if (map[now].check(ex, ey))
            return used[now];

        for (int i = 0; i < K; i++)
        {
            if (used[i])
                continue;
            if (map[now].check(map[i]))
            {
                used[i] = used[now] + 1;
                q.push(i);
            }
        }
    }
}
int main()
{
    // freopen("../input.txt", "r", stdin);
    InputData();

    ans = solve();

    cout << ans << '\n';
}