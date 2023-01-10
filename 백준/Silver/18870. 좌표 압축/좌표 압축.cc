#include <bits/stdc++.h>
using namespace std;
vector<int> arr, backup;
int main()
{
    cin.tie(0);
    cin.sync_with_stdio(false);
    int n;
    cin >> n;
    for (int i = 0; i < n; i++)
    {
        int a;
        cin >> a;
        arr.push_back(a);
        backup.push_back(a);
    }
    sort(arr.begin(), arr.end());
    arr.erase(unique(arr.begin(), arr.end()), arr.end());
    for (int i = 0; i < n; i++)
    {
        cout << lower_bound(arr.begin(), arr.end(), backup[i]) - arr.begin()<<" ";
    }
}