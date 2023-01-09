#include <bits/stdc++.h>
using namespace std;
#define Mod 1000000000;
typedef long long ll;
int N;
ll ans;
ll dp[101][11];
int main()
{
    cin >> N;
    for (int i = 1; i <= 9; i++)
    {
        dp[1][i] = 1;
    }
    dp[1][0] = 0;

    for (int i = 2; i <= N; i++)
    {
        for (int j = 0; j <= 9; j++)
        {
            if (j == 0)
            {
                dp[i][j] = dp[i - 1][j + 1] % Mod;
            }
            else if (j == 9)
            {
                dp[i][j] = dp[i - 1][j - 1] % Mod;
            }
            else
            {
                dp[i][j] = (dp[i - 1][j - 1] + dp[i - 1][j + 1]) % Mod;
            }
        }
    }
    for (int i = 0; i < 10; i++)
    {
        ans += dp[N][i];
    }
    cout << ans % Mod;
}