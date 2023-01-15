#include <iostream>
#include <algorithm>
#include <vector>
#include <string.h>
#include <cmath>

using namespace std;

int T;
bool visited[105];
vector<int> ans[105];
void dfs(int n)
{
    visited[n] = true;
    for(auto it : ans[n])
    {
        if(visited[it]) continue;
        dfs(it);
    }
}
int caldist(pair<int,int> a, pair<int,int> b)
{
    return (abs(a.first-b.first) + abs(a.second-b.second));
}
int main()
{
    cin.tie(0);
    cin.sync_with_stdio(0);
    //freopen("input.txt","r",stdin);
    cin>>T;
    while(T--)
    {
        memset(visited,false,sizeof(visited));
        for(int i=0;i<105;i++) ans[i].clear();
        int n; cin>>n;

        vector<pair<int,int>> arr(n+2);
        for(auto& it : arr) cin>>it.first>>it.second;
    
        for(int i=0;i<n+2;i++)
        {
            for(int j=i+1;j<n+2;j++)
            {
                int now = caldist(arr[i],arr[j]);
                if(now <= 1000)
                {
                    ans[i].push_back(j);
                    ans[j].push_back(i);
                }
            }
        }
        dfs(0);
        if(visited[n+1]) cout<<"happy\n";
        else cout<<"sad\n";
    }
    
}