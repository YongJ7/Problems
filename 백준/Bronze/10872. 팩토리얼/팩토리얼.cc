#include <bits/stdc++.h>
using namespace std;

int main()
{
    int a;
    cin >> a;
    int ans = 1;
    for (int i = 1; i <= a; i++)
    {
        ans *= i;
    }
    cout << ans;
}