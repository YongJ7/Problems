#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
int n;
ll ans;
priority_queue<ll, vector<ll>, greater<ll>> arr;
int main()
{
    cin >> n;
    if (n == 1)
    {
        cout << 0;
        return 0;
    }
    for (int i = 0; i < n; i++)
    {
        ll a;
        cin >> a;
        arr.push(a);
    }
    while (1)
    {
        ll q = arr.top();
        arr.pop();
        ll w = arr.top();
        arr.pop();
        ll sum = q + w;
        ans += sum;
        if (arr.empty())
            break;
        else
            arr.push(sum);
    }
    cout << ans;
}