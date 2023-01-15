#include <iostream>
#include <queue>
#include <vector>
#include <algorithm>

using namespace std;

int n,a,b;
vector<int> v[100001];
queue<int> order;
int bfs[100001];

bool comp(const int& a,const int& b)
{
    return bfs[a] < bfs[b];
}
int main()
{
    cin.tie(0);
    cin.sync_with_stdio(0);

    cin>>n;
    for(int i=0;i<n-1;i++)
    {
        cin>>a>>b;
        v[a].push_back(b);
        v[b].push_back(a);
    }
    for(int i=1;i<=n;i++)
    {
        cin>>a;
        order.push(a);
        bfs[a] = i;
    }
    for(int i=1;i<=n;i++){
        sort(v[i].begin(),v[i].end(),comp);
    }

    if(order.front() != 1){
        cout<<"0\n";
        return 0;
    }
    else{
        queue<int> q;
        q.push(1);
        order.pop();
        while(!q.empty())
        {
            int temp = q.front();
            q.pop();
            for(auto it : v[temp]){
                if(it == order.front())
                {
                    q.push(order.front());
                    order.pop();
                }
            }
        }
    }
    if(order.empty()) cout<<"1\n";
    else cout<<"0\n";
}