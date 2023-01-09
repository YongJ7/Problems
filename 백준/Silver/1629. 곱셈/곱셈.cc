#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
ll power(ll a, ll b, ll c)
{
    if (b == 0)
        return 1;
    ll sum = power(a, b / 2, c);
    sum = sum * sum % c;

    if (b % 2 == 0)
        return sum;
    else
        return (sum * a) % c;
}
int main()
{
    cin.tie(0);
    cin.sync_with_stdio(0);
    int a, b, c;
    cin >> a >> b >> c;
    cout << power(a, b, c);
}
