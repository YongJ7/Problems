#include <bits/stdc++.h>
using namespace std;
int N, M;
int path[10];
int used[10];
void run(int lv)
{
    if (lv == M)
    {
        for (int i = 0; i < M; i++)
        {
            cout << path[i] << " ";
        }
        cout << '\n';
        return;
    }
    for (int i = 1; i <= N; i++)
    {
        if (used[i] == 1)
            continue;
        path[lv] = i;
        used[i] = 1;
        run(lv + 1);
        path[lv] = 0;
        used[i] = 0;
    }
}
int main()
{
    cin >> N >> M;
    run(0);
}