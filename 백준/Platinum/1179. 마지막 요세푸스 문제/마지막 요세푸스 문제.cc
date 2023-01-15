#include <iostream>

using namespace std;
typedef long long ll;

int main()
{
    cin.tie(0);
    cin.sync_with_stdio(0);

    ll N, K;
    cin >> N >> K;
    ll ans = 0;
    ll temp = 1;

    if (K == 1)
        cout << N;
    else
    {
        while (1)
        {
            ll now = (temp - ans - 1) / (K - 1) + 1;
            if (temp + now > N)
            {
                ans += (N - temp) * K;
                break;
            }
            ans = (ans + K * now) % (temp + now);
            temp += now;
        }
        cout<<ans+1;
    }
    
}