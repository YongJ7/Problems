#include <stdio.h>

int n, m;
int arr[1001][3];
int dp[1001][3];
int min(int a, int b)
{
    return a >= b ? b : a;
}
int main()
{
    scanf("%d", &n);
    for (int i = 0; i < n; i++)
    {
        for (int j = 0; j < 3; j++)
        {
            scanf("%d", &arr[i][j]);
        }
    }
    dp[0][0] = arr[0][0];
    dp[0][1] = arr[0][1];
    dp[0][2] = arr[0][2];

    for (int i = 1; i < n; i++)
    {
        dp[i][0] = min(dp[i - 1][1], dp[i - 1][2]) + arr[i][0];
        dp[i][1] = min(dp[i - 1][0], dp[i - 1][2]) + arr[i][1];
        dp[i][2] = min(dp[i - 1][0], dp[i - 1][1]) + arr[i][2];
    }
    m = min(dp[n - 1][0], dp[n - 1][1]);
    if (m < dp[n - 1][2])
        printf("%d", m);
    else
        printf("%d", dp[n - 1][2]);
}