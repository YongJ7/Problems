#include <bits/stdc++.h>
#define M 7e8
using namespace std;

vector <pair<int,int>> mapp[201];
int dist[201][201];
priority_queue<pair<int,int>> q;
int ans = M;
void cost(int s,int n){
    while(!q.empty()) q.pop();
    dist[s][s]=0;
    q.push({0,s});
    while(!q.empty()){
        int aa = -q.top().first;
        int bb = q.top().second;
        q.pop();
        if (dist[s][bb]!=aa) continue;
        for (int i =0;i<mapp[bb].size();i++){
            int t = mapp[bb][i].first;
            int l = mapp[bb][i].second;
            if(dist[s][t]>dist[s][bb]+l){
                dist[s][t]=dist[s][bb]+l;
                q.push({-dist[s][t],t});
            }
        }
    }
}
int solution(int n, int s, int a, int b, vector<vector<int>> fares) {
    for (auto i:fares){
        mapp[i[0]].push_back({i[1],i[2]});
        mapp[i[1]].push_back({i[0],i[2]});
    }
    for (int i =1;i<=n;i++) for(int j=1;j<=n;j++) dist[i][j]=M;
    cost(s,n);
    cost(a,n);
    cost(b,n);
    for(int i =1;i<=n;i++){
        if(dist[s][i]==M||dist[a][i]==M||dist[b][i]==M) continue;
        ans=min(ans,dist[s][i]+dist[a][i]+dist[b][i]);
    }
    
    return ans;
}