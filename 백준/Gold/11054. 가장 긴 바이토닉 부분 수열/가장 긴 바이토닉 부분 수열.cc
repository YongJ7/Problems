#include <iostream>

using namespace std;

int N, arr[1001],L_DP[1001],R_DP[1001];

int main()
{
    cin.tie(0);
    cin.sync_with_stdio(0);

    cin>>N;
    
    for(int i=1;i<=N;i++) cin>>arr[i];

    for(int i=1;i<=N;i++)
    {
        L_DP[i] = 1;
        for(int j=1;j<=i;j++)
        {
            if(arr[j] < arr[i] && L_DP[i] < L_DP[j] + 1){
                L_DP[i] = L_DP[j] + 1;
            }
        }
    }

    for(int i=N;i>=1;i--)
    {
        R_DP[i] = 1;
        for(int j=N;j>=i;j--)
        {
            if(arr[j] < arr[i] && R_DP[i] < R_DP[j] + 1){
                R_DP[i] = R_DP[j] + 1;
            }
        }
    }

    int ans = 0;
    for(int i=0;i<=N;i++)
    {
        if(ans < L_DP[i] + R_DP[i] - 1) ans = L_DP[i] + R_DP[i] - 1;
    }

    cout<<ans<<'\n';
}