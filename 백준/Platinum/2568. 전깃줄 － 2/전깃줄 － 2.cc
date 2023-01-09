#include <bits/stdc++.h>
using namespace std;
int N,ans;
int used[500001];
bool answer[500001];
vector<pair<int,int>> arr;
vector<int> v;
int main()
{
    cin.sync_with_stdio(0);
    cin.tie(0);
    //freopen("input.txt","r",stdin);
    cin >> N;
    for(int i=0;i<N;i++)
    {
        int s,e; cin>>s>>e;
        arr.push_back({e,s});
        answer[s] = true;
    }
    sort(arr.begin(),arr.end());

    for (int i = 0; i < N; i++)
    {
        auto it = lower_bound(v.begin(),v.end(), arr[i].second) - v.begin();
        used[i] = it;
        if(it + v.begin() == v.end())
        {
            v.push_back(arr[i].second);
            ans++; 
        }
        else v[it] = arr[i].second;
    }
    cout<<N-ans<<'\n';
    
    for(int i=N-1;i>=0;i--)
    {
        if(ans<1) break;
        if(used[i] == ans-1)
        {
            answer[arr[i].second] = false;
            ans--;
        }
    }
    for(int i=1;i<=500000;i++)
    {
        if(answer[i]) cout<<i<<'\n';
    }
}
