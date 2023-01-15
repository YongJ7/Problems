#include <bits/stdc++.h>
using namespace std;
int main()
{
    cin.tie(0);
    cin.sync_with_stdio(0);

    int N; cin>>N;

    priority_queue<int> pq;

    int a;
    for(int i=0;i<N;i++)
    {
        cin>>a;
        if(a==0){
            if(pq.empty()) cout<<-1<<'\n';
            else{
                cout<<pq.top()<<'\n';
                pq.pop();
            }
        }
        else{
            for(int j=0;j<a;j++){
                int x; cin>>x;
                pq.push(x);
            }
        }
    }
}