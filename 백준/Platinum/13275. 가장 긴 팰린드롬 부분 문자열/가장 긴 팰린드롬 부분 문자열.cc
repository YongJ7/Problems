#include <iostream>
#include <string>
#include <algorithm>

using namespace std;

int A[200010];

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

    string temp, str; cin>>temp;
    int l = temp.size();

    for(int i=0;i<l;i++)
    {
        str += '#';
        str += temp[i];
    }
    str += '#';
    
    l = str.size();

    pelendrom(str,l);

    int ans = 0;
    for(int i=0;i<l;i++)
    {
        ans = max(ans,A[i]);
    }
    cout<<ans<<'\n';
}