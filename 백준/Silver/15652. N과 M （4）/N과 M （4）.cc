#include <bits/stdc++.h>
using namespace std;
int N, M;
int path[10];
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
    for (int i = now; i <= N; i++)
    {

        path[lv] = i;
        run(lv + 1, i);
        path[lv] = 0;
    }
}
int main()
{
    cin >> N >> M;
    run(0, 1);
}