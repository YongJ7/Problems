#include <bits/stdc++.h>
using namespace std;
int n;
vector<int> arr;
int sum[1001];
int main()
{
    cin >> n;
    for (int i = 0; i < n; i++)
    {
        int a;
        cin >> a;
        arr.push_back(a);
    }
    sort(arr.begin(), arr.end());
    int ans = arr[0];
    sum[0] = arr[0];
    for (int i = 1; i < n; i++)
    {
        sum[i] = sum[i - 1] + arr[i];
        ans += sum[i];
    }
    cout << ans;
}