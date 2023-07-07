#include <iostream>
#include <queue>
#include <vector>
#include <string>
#include <cstring>
#include <set>

using namespace std;

int N, M, now;
int map[1001][1001], num[1001][1001], ans[1001][1001];
bool vis[1001][1001];
vector<int> arr;

int d[4][2] = {
    0,
    1,
    0,
    -1,
    1,
    0,
    -1,
    0,
};
void input()
{
    cin >> N >> M;
    for (int i = 0; i < N; i++)
    {
        string s;
        cin >> s;
        for (int j = 0; j < s.size(); j++)
        {
            map[i][j] = s[j] - '0';
        }
        memset(num, -1, sizeof(num));
    }
}
void BFS(int a, int b)
{
    queue<pair<int, int>> Q;
    Q.push(make_pair(a, b));
    int Cnt = 1;
    num[a][b] = now;
    vis[a][b] = true;

    while (Q.empty() == 0)
    {
        int x = Q.front().first;
        int y = Q.front().second;
        Q.pop();

        for (int i = 0; i < 4; i++)
        {
            int nx = x + d[i][0];
            int ny = y + d[i][1];

            if (nx >= 0 && ny >= 0 && nx < N && ny < M)
            {
                if (map[nx][ny] == 0 && vis[nx][ny] == false)
                {
                    vis[nx][ny] = true;
                    num[nx][ny] = now;
                    Q.push(make_pair(nx, ny));
                    Cnt++;
                }
            }
        }
    }
    arr.push_back(Cnt);
}

void solve()
{
    for (int i = 0; i < N; i++)
    {
        for (int j = 0; j < M; j++)
        {
            if (map[i][j] == 0 && vis[i][j] == false)
            {
                BFS(i, j);
                now++;
            }
        }
    }
    for (int i = 0; i < N; i++)
    {
        for (int j = 0; j < M; j++)
        {
            if (map[i][j] == 1)
            {
                set<int> Search;
                for (int k = 0; k < 4; k++)
                {
                    int nx = i + d[k][0];
                    int ny = j + d[k][1];

                    if (nx >= 0 && ny >= 0 && nx < N && ny < M)
                    {
                        if (map[nx][ny] == 0)
                        {
                            if (Search.find(num[nx][ny]) == Search.end())
                            {
                                Search.insert(num[nx][ny]);
                                ans[i][j] = ans[i][j] + arr[num[nx][ny]];
                            }
                        }
                    }
                }
                ans[i][j] = ans[i][j] + 1;
                ans[i][j] = ans[i][j] % 10;
            }
        }
    }

    for (int i = 0; i < N; i++)
    {
        for (int j = 0; j < M; j++)
        {
            cout << ans[i][j];
        }
        cout << "\n";
    }
}
int main()
{
    input();

    solve();

    return 0;
}