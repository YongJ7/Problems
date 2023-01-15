#include <iostream>
#include <string>
#include <algorithm>

using namespace std;
int N,M,ans=64;
char map[51][51];

int black(int x,int y)
{
    int cnt = 0;
    for(int i=x;i<x+8;i++)
    {
        for(int j=y;j<y+8;j++)
        {
            if((i+j)%2==0 && map[i][j]=='W') cnt++;
            if((i+j)%2!=0 && map[i][j]=='B') cnt++;
        }
    }
    return cnt;
}
int white(int x,int y)
{
    int cnt = 0;
    for(int i=x;i<x+8;i++)
    {
        for(int j=y;j<y+8;j++)
        {
            if((i+j)%2==0 && map[i][j]=='B') cnt++;
            if((i+j)%2!=0 && map[i][j]=='W') cnt++;
        }
    }
    return cnt;
}
int main()
{
    cin.tie(0);
    cin.sync_with_stdio(0);
    //freopen("input.txt","r",stdin);
    cin>>N>>M;
    for(int i=0;i<N;i++)
    {
        string s; cin>>s;
        for(int j=0;j<M;j++)
        {
            map[i][j] = s[j];
        }
    }
    for(int i=0;i<=N-8;i++)
    {
        for(int j=0;j<=M-8;j++)
        {
            int cnt1 = black(i,j);
            int cnt2 = white(i,j);
            ans = min(ans,min(cnt1,cnt2));
        }
    }
    cout<<ans<<'\n';
}