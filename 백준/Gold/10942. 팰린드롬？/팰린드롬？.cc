#include <iostream>
#include <string>
#include <algorithm>

using namespace std;

int A[2000010];
string temp, str;
int N;
void pelendrom(string s, int n)
{
    int r = 0, p = 0;
    for(int i=0;i<n;i++)
    {
        if(i<=r) A[i] = min(A[2*p-i],r-i);
        else A[i] = 0;

        while(i-A[i]-1 >= 0 && i+A[i]+1 < n && s[i-A[i]-1] == s[i+A[i]+1])
        {
            A[i]++;
        }        
        if(r < i+A[i])
        {
            r = i+A[i];
            p = i;
        }
    }
}
int main()
{
    cin.tie(0);
    cin.sync_with_stdio(0);
    cin>>N;
    for(int i=0;i<N;i++)
    {
        int a; cin>>a;
        temp += (a+'0');
    }
    
    int l = temp.size();
    str = temp[0];

    for(int i=1;i<l;i++)
    {
        str += '#';
        str += temp[i];
    }
    
    l = str.size();

    pelendrom(str,l);

    int M; cin>> M;
    while(M--)
    {
        int s,e; cin>>s>>e;
        s--,e--;
        s*=2;
        e*=2;

        int r = A[(s+e)/2];
        if((s+e)/2 + r >= e) cout<<1<<'\n';
        else cout<<0<<'\n';
    }
}