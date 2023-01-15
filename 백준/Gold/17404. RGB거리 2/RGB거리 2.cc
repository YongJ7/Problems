#include <iostream>
#include <algorithm>
#define FOR(i,n) for(int i=0;i<n;i++)
using namespace std;

int arr[1001][3];
int N,ans=1000001;
int main()
{
    cin.tie(0);
    cin.sync_with_stdio(0);
    //freopen("input.txt","r",stdin);

    cin>>N;

    FOR(i,N)
    {
        FOR(j,3)
        {
            cin>>arr[i][j];
        }
    }

    FOR(i,3)
    {
        int dp[1001][3];
        FOR(j,3)
        {
            if(j==i){
                dp[0][i] = arr[0][i];
            }
            else dp[0][j] = 1000001;
        }
        for(int j=1;j<N;j++)
        {
            dp[j][0] = min(dp[j-1][1],dp[j-1][2]) + arr[j][0];
            dp[j][1] = min(dp[j-1][0],dp[j-1][2]) + arr[j][1];
            dp[j][2] = min(dp[j-1][0],dp[j-1][1]) + arr[j][2];
        }
        FOR(j,3)
        {
            if(j==i) continue;
            ans = min(ans,dp[N-1][j]);
        }
    }
    cout<<ans<<'\n';
}