#include <stdio.h>

int n;
int arr[501][501];
int dp[501][501];
int main()
{
    scanf("%d", &n);
    for (int i = 1; i <= n; i++)
    {
        for (int j = 1; j <= i; j++)
        {
            scanf("%d", &arr[i][j]);
        }
    }
    dp[1][1] = arr[1][1];
    for (int i = 2; i <= n; i++)
    {
        dp[i][1] = dp[i - 1][1] + arr[i][1];
        for (int j = 2; j < i; j++)
        {
            dp[i][j] = (dp[i - 1][j - 1] > dp[i - 1][j] ? dp[i - 1][j - 1] : dp[i - 1][j]) + arr[i][j];
        }
        dp[i][i] = dp[i - 1][i - 1] + arr[i][i];
    }
    int m = 0;
    for (int i = 1; i <= n; i++)
    {
        if (m < dp[n][i])
            m = dp[n][i];
    }
    printf("%d", m);
}