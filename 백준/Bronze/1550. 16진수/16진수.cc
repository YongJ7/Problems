#include <bits/stdc++.h>
using namespace std;

string s;
int main()
{
    cin.sync_with_stdio(0);
    cin.tie(0);
    cin >> s;
    int l = s.size();
    int ans = 0;
    int p = 0;
    for (int i = l - 1; i >= 0; i--)
    {
        if (s[i] >= '0' && s[i] <= '9')
        {
            ans += (pow(16, p) * (s[i] - '0'));
        }
        else
        {
            ans += (pow(16, p) * (s[i] - 'A' + 10));
        }
        p++;
    }
    cout << ans;
}
