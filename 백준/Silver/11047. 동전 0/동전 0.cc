#include <bits/stdc++.h>
using namespace std;

int N, K, money[10];
int main()
{
    cin.sync_with_stdio(0);
    cin.tie(0);
    cin >> N >> K;
    for (int i = 0; i < N; i++)
    {
        cin >> money[i];
    }
    int ans = 0;
    for (int i = N - 1; i >= 0; i--)
    {
        ans += K / money[i];
        K %= money[i];
        if (K == 0)
            break;
    }
    cout << ans;
}
