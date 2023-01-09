#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;
int dp[101];
int main()
{
    cin.tie(0);
    cin.sync_with_stdio(0);
    //freopen("input.txt","r",stdin);
    vector<pair<int,int>> arr;
    int n; cin>>n;
    arr.push_back({0,0});
    for(int i=0;i<n;i++)
    {
        int a,b; cin>>a>>b;
        arr.push_back({a,b});
    }
    sort(arr.begin(),arr.end());

    
    dp[1] = 1;
    int ans = 100;
    for(int i=2;i<=n;i++)
    {
        for(int j=i-1;j>=0;j--)
        {
            if(arr[i].second > arr[j].second)
            {
                if(dp[i]<=dp[j]) dp[i] = dp[j] + 1;
            }
        }
    }
    for(int i=1;i<=n;i++)
    {
        ans = min(ans,n - dp[i]);
    }
    cout<<ans<<'\n';
}