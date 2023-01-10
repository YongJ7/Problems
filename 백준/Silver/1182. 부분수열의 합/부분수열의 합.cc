#include <bits/stdc++.h>
using namespace std;
int N, S;
int n[20];
int cnt;
void run(int sum, int lv)
{
    if (sum == S && lv != 0)
        cnt++;
    if (lv == N)
        return;

    for (int i = lv; i < N; i++)
    {
        run(sum + n[i], i + 1);
    }
}
int main()
{
    cin >> N >> S;
    for (int i = 0; i < N; i++)
    {
        cin >> n[i];
    }
    run(0, 0);
    cout << cnt;
    return 0;
}