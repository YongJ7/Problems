#include <iostream>
#include <string>
#include <algorithm>

using namespace std;

int A[2000010];
int str[20000010];
string temp;
int N;
void pelendrom(int *s, int n)
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
    int l = 0;
    for(int i=0;i<N*2-1;i++)
    {
        int a; cin>>a;
        str[i] = a;
        i++;
        l++;
        str[i] = -1;
        l++;
    }

    pelendrom(str,l-1);

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