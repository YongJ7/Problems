#include <bits/stdc++.h>
using namespace std;
int N, cnt;
vector<string> arr;
bool V[26][26];
vector<int> ans;
int d[4][2] = {
    0, 1,
    1, 0,
    0, -1,
    -1, 0};

void DFS(int x, int y)
{
    cnt++;
    V[x][y] = true;
    for (int i = 0; i < 4; i++)
    {
        int nx = x + d[i][0];
        int ny = y + d[i][1];

        if (nx < 0 || ny < 0 || nx >= N || ny >= N)
            continue;
        if (!V[nx][ny] && arr[nx][ny] != '0')
        {
            DFS(nx, ny);
        }
    }
}
int main()
{
    cin >> N;
    for (int i = 0; i < N; i++)
    {
        string s;
        cin >> s;
        arr.push_back(s);
    }

    for (int i = 0; i < N; i++)
    {
        for (int j = 0; j < N; j++)
        {
            if (!V[i][j] && arr[i][j] != '0')
            {
                cnt = 0;
                DFS(i, j);
                ans.push_back(cnt);
            }
        }
    }
    sort(ans.begin(), ans.end());
    cout << ans.size() << '\n';
    for (int i = 0; i < ans.size(); i++)
    {
        cout << ans[i] << '\n';
    }
}
