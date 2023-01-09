#include <iostream>
#include <vector>
#include <queue>
#define FOR(i,n) for(int i=0;i<n;i++)
using namespace std;

int n,k,ans;
int arr[101], mul[101];

int main()
{
    cin.tie(0);
    cin.sync_with_stdio(0);
    //freopen("input.txt","r",stdin);
    cin>>n>>k;
    
    FOR(i,k) cin>>arr[i];

    FOR(i,k)
    {
        bool plug = false;

        FOR(j,n)
        {
            if(mul[j] == arr[i]){
                plug = true;
                break;
            }
        }
        if(plug) continue;

        FOR(j,n)
        {
            if(!mul[j]){
                mul[j] = arr[i];
                plug = true;
                break;
            }
        }
        if(plug) continue;

        int idx, nowidx = -1;
        FOR(j,n)
        {
            int last = 0;
            int next = i+1;

            while(next<k && mul[j] != arr[next])
            {
                last++;
                next++;
            }
            if(last> nowidx)
            {
                idx = j;
                nowidx = last;
            }
        }
        ans++;
        mul[idx] = arr[i];
    }
    cout<<ans<<'\n';
}