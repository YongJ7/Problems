#include <bits/stdc++.h>
using namespace std;
int N,ans;
int arr[1000001];
int used[1000001];
vector<int> v;
vector<int> answer;
int main()
{
    cin.sync_with_stdio(0);
    cin.tie(0);
    //freopen("input.txt","r",stdin);
    cin >> N;

    for (int i = 0; i < N; i++)
    {
        cin>>arr[i];
        auto it = lower_bound(v.begin(),v.end(), arr[i]) - v.begin();
        used[i] = it;
        if(it + v.begin() == v.end())
        {
            v.push_back(arr[i]);
            ans++; 
        }
        else v[it] = arr[i];
    }
    cout<<ans<<'\n';
    
    for(int i=N-1;i>=0;i--)
    {
        if(ans<1) break;
        if(used[i] == ans-1)
        {
            answer.push_back(arr[i]);
            ans--;
        }
    }
    while(!answer.empty())
    {
        cout<<answer.back()<<" ";
        answer.pop_back();
    }
}
