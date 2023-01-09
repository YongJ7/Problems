#include <iostream>
#include <string>
#include <vector>
#include <algorithm>

using namespace std;

vector<bool> alp(26);
vector<string> v;
int N,K,ans;

int Read()
{
    bool read = false;
    int cnt = 0;
    for(int i=0;i<v.size();i++)
    {
        read = true;
        string now = v[i];
        for(int j=0;j<now.size();j++)
        {
            if(alp[now[j]-'a']==false){
                read = false;
                break;
            }
        }
        if(read) cnt++;
    }
    return cnt;
}
void run(int idx,int num)
{
    if(num == K){
        int now = Read();
        ans = ans < now ? now : ans;
    }

    for(int i=idx;i<26;i++){
        if(alp[i]==true) continue;
        alp[i] = true;
        run(i,num+1);
        alp[i]=false;
    }
}
int main()
{
    cin.tie(0);
    cin.sync_with_stdio(0);

    //freopen("input.txt","r",stdin);
    cin>>N>>K;
    alp['a'-'a'] = true;
    alp['t'-'a'] = true;
    alp['i'-'a'] = true;
    alp['c'-'a'] = true;
    alp['n'-'a'] = true;

    if(K<5){
        cout<<0<<'\n';
        return 0;
    }
    K-=5;
    for(int i=0;i<N;i++)
    {
        string s; cin>>s;
        v.push_back(s);
    }
    run(0,0);

    cout<<ans<<'\n';
}