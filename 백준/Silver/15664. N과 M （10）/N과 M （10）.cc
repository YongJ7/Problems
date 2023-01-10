#include <bits/stdc++.h>
using namespace std;
int N, M;
int path[10];
int c[10];
int used[10];
void run(int lv, int now)
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
    int x = 0;
    for (int i = now; i < N; i++)
    {
        if (used[i] != 1 && c[i] != x)
        {
            used[i] = 1;
            path[lv] = c[i];
            x = path[lv];
            run(lv + 1, i);
            path[lv] = 0;
            used[i] = 0;
        }
    }
}
int main()
{
    cin >> N >> M;
    for (int i = 0; i < N; i++)
    {
        cin >> c[i];
    }
    sort(c, c + N);
    run(0, 0);
}