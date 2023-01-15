#include <iostream>
#include <queue>
#include <algorithm>

using namespace std;

int map[1001][1001];
int dp[1001][1001];
int Right[1001]; // 오른쪽으로 탐색할때 더한 값
int Left[1001];  // 왼쪽으로 탐색할때 더한 값
int N,M;

int main()
{
    cin.tie(0);
    cin.sync_with_stdio(0);

    //freopen("input.txt","r",stdin);
    
    cin>>N>>M;
    
    for(int i=0;i<N;i++)
    {
        for(int j=0;j<M;j++)
        {
            cin>>map[i][j];
        }
    }
    dp[0][0] = map[0][0];
    for(int i=1;i<M;i++)
    {
        dp[0][i] += dp[0][i-1] + map[0][i];
    }
    for(int i=1;i<N;i++)
    {
        Right[0] = dp[i-1][0] + map[i][0];
        for(int j=0;j<M-1;j++)
        {
            Right[j+1] = max(Right[j],dp[i-1][j+1]) + map[i][j+1];
        }
        Left[M-1] = dp[i-1][M-1] + map[i][M-1];
        for(int j=M-2;j>=0;j--)
        {
            Left[j] = max(Left[j+1],dp[i-1][j]) + map[i][j];
        }

        for(int j=0;j<M;j++)
        {
            dp[i][j] = max(Right[j],Left[j]);
        }
    }
    cout<<dp[N-1][M-1]<<'\n';
}