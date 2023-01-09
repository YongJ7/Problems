#include <bits/stdc++.h>
using namespace std;

int N;
int ans;

bool col_vis[16], dia1_vis[32], dia2_vis[32];

void dfs(int row)
{
    if (row == N + 1)
    {
        ans++;
        return;
    }
    for (int col = 1; col <= N; col++)
        if (!col_vis[col] && !dia1_vis[row - col + N] && !dia2_vis[row + col])
        {
            // (row, col)에 queen을 놓는 경우
            col_vis[col] = dia1_vis[row - col + N] = dia2_vis[row + col] = true;
            dfs(row + 1);
            col_vis[col] = dia1_vis[row - col + N] = dia2_vis[row + col] = false;
        }
}

int main()
{
    cin >> N;
    dfs(1);
    cout << ans << endl;
}