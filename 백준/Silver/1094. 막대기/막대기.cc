#include <bits/stdc++.h>
using namespace std;
int n, ans;
int main()
{
    cin.tie(0);
    cin.sync_with_stdio(0);
    cin >> n;
    while (n)
    {
        if (n % 2)
            ans++;
        n /= 2;
    }
    cout << ans;
}