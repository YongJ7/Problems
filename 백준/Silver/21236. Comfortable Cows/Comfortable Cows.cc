#include <bits/stdc++.h>
using namespace std;
int N;
int m[1001][1001];
int d[4][2] = {
    1, 0,
    0, 1,
    -1, 0,
    0, -1};

bool positive(int x, int y)
{
    return x >= 0 && x <= N && y >= 0 && y <= N;
}

int countt(int x, int y)
{
    if (m[x][y] == 0)
        return 0;
    int n = 0;
    for (int i = 0; i < 4; i++)
    {
        if (positive(x + d[i][0], y + d[i][1]))
        {
            if (m[x + d[i][0]][y + d[i][1]])
                n++;
        }
    }
    if (n == 3)
        return 1;
    return 0;
}
int main()
{
    cin.tie(0);
    cin.sync_with_stdio(0);

    cin >> N;
    int cnt = 0;
    for (int j = 0; j < N; j++)
    {
        int x, y;
        cin >> x >> y;
        for (int i = 0; i < 4; i++)
        {
            if (positive(x + d[i][0], y + d[i][1]))
            {
                cnt -= countt(x + d[i][0], y + d[i][1]);
            }
        }
        m[x][y] = 1;
        for (int i = 0; i < 4; i++)
        {
            if (positive(x + d[i][0], y + d[i][1]))
            {
                cnt += countt(x + d[i][0], y + d[i][1]);
            }
        }
        cnt += countt(x, y);
        cout << cnt << '\n';
    }
    return 0;
}