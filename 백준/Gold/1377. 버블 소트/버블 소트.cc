#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;
int N;
vector<pair<int,int>> arr;
int main()
{
    cin.tie(0);
    cin.sync_with_stdio(0);

    cin >> N;
    for(int i=0;i<N;i++){
        int a; cin>>a;
        arr.push_back({a,i});
    }
    sort(arr.begin(),arr.end());
    int ans = -1;
    for(int i =0;i<N;i++)
    {
        ans = ans < arr[i].second-i ? arr[i].second-i : ans;
    }
    cout<<ans+1<<'\n';
}