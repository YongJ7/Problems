#include <iostream>
#include <string>
#include <algorithm>

using namespace std;
int n, m, ans = 1;
char map[21][21];
bool used[21][21];
bool alp[30];
int d[4][2] = {
    1, 0,
    -1, 0,
    0, 1,
    0, -1};
void run(int x, int y, int cnt)
{
    ans = max(ans,cnt);
    for (int i = 0; i < 4; i++)
    {
        int nx = x + d[i][0];
        int ny = y + d[i][1];

        if (nx < 0 || ny < 0 || nx >= n || ny >= m)
            continue;
        if (alp[map[nx][ny] - 'A'] || used[nx][ny])
            continue;
        used[nx][ny] = true;
        alp[map[nx][ny] - 'A'] = true;
        run(nx, ny, cnt + 1);
        used[nx][ny] = false;
        alp[map[nx][ny] - 'A'] = false;
    }
}
int main()
{
    cin.tie();
    cin.sync_with_stdio(0);
    //freopen("input.txt", "r", stdin);
    cin >> n >> m;
    for (int i = 0; i < n; i++)
    {
        string s;
        cin >> s;
        for (int j = 0; j < m; j++)
        {
            map[i][j] = s[j];
        }
    }
    used[0][0] = true;
    alp[map[0][0] - 'A'] = true;
    run(0, 0, 1);
    cout << ans << '\n';
}