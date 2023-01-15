#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

int N,M,qu_num;
bool where_qu[100001];
vector<int> qu_push;
vector<int> insert_num;
int main()
{
    cin.tie(0);
    cin.sync_with_stdio(0);

    cin>>N;
    for(int i=0;i<N;i++)
    {
        int Type; cin>>Type;
        if(Type == 0) where_qu[i]=true;
    }
    for(int i=0;i<N;i++)
    {
        int num; cin>>num;
        if(where_qu[i]) qu_push.push_back(num);
    }
    cin>>M;
    for(int i=0;i<M;i++)
    {
        int num; cin>>num;
        insert_num.push_back(num);
    }
    int l = qu_push.size();
    reverse(qu_push.begin(),qu_push.end());
    if(l>=M)
    {
        for(int i=0;i<M;i++){
            cout<<qu_push[i]<<" ";
        }
    }
    else
    {
        for(int i=0;i<l;i++){
            cout<<qu_push[i]<<" ";
        }
        for(int i=0;i<M-l;i++){
            cout<<insert_num[i]<<" ";
        }
    }
}