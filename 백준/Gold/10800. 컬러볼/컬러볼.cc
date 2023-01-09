#include <iostream>
#include <vector>
#include <algorithm>
#define FOR(i,n) for(int i=0;i<n;i++)
using namespace std;

struct ball{
    int idx,color,weight;
};

bool comp(ball a,ball b)
{
    if(a.weight == b.weight) return a.color < b.color;
    return a.weight < b.weight;
}

int main()
{
    cin.tie(0);
    cin.sync_with_stdio(0);
    //freopen("input.txt","r",stdin);
    int N; cin>>N;
    vector<ball> arr;
    int sum = 0;
    int colsum[200001];
    int ans[200001];

    FOR(i,N)
    {
        int c,w; cin>>c>>w;
        arr.push_back({i,c,w});
    }

    sort(arr.begin(),arr.end(),comp);

    for(int i=0,j=0;i<N;i++)
    {
        for(;arr[i].weight>arr[j].weight; j++){
            sum += arr[j].weight;
            colsum[arr[j].color]+=arr[j].weight;
        }
        ans[arr[i].idx] = sum - colsum[arr[i].color];
    }
    
    FOR(i,N)
    {
        cout<<ans[i]<<'\n';
    }
}