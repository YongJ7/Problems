#include <iostream>

using namespace std;

int main()
{
    cin.tie(0);
    cin.sync_with_stdio(0);

    int N,K; cin>>N>>K;

    int left = 1, right = K;
    int ans = -1;

    while(left <= right)
    {
        int cnt = 0;
        int mid = (left + right)/2;
        for(int i=1;i<=N;i++)
        {
            cnt += min(mid/i,N);
        }
        if(cnt < K){
            left = mid+1;
        }
        else{
            ans = mid;
            right = mid-1;
        }
    }
    cout<<ans<<'\n';
}