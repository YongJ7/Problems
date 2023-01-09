#include <bits/stdc++.h>
using namespace std;
int n, k, r;
int main()
{
    cin.tie(0);
    cin.sync_with_stdio(0);
    cin >> n >> k;
    for (int i = 2; i <= n; i++)
    {
        r = (r + k) % i;
    }
    cout << r + 1;
}