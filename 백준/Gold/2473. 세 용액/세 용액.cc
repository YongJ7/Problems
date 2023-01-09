#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
int n;
ll arr[5001];
ll ans[3];
ll MIN = 3000000001;
int main()
{
    cin >> n;
    for (int i = 0; i < n; i++)
    {
        cin >> arr[i];
    }
    sort(arr, arr + n);
    for (int i = 0; i < n - 2; i++)
    {
        int s = i + 1;
        int e = n - 1;
        while (s < e)
        {
            ll val = arr[i] + arr[s] + arr[e];
            if (abs(val) < MIN)
            {
                ans[0] = arr[i];
                ans[1] = arr[s];
                ans[2] = arr[e];
                MIN = abs(val);
            }
            if (val < 0)
                s++;
            else
                e--;
        }
    }
    for (int i = 0; i < 3; i++)
    {
        cout << ans[i] << " ";
    }
}