#include <bits/stdc++.h>
using namespace std;
vector<pair<int, int>> arr;
bool compare(pair<int, int> a, pair<int, int> b)
{
    if (a.second < b.second)
        return true;
    if (a.second > b.second)
        return false;
    if (a.first < b.first)
        return true;
    return false;
}
int main()
{
    cin.tie(0);
    cin.sync_with_stdio(false);
    int n;
    cin >> n;
    for (int i = 0; i < n; i++)
    {
        int a, b;
        cin >> a >> b;
        arr.push_back({a, b});
    }
    sort(arr.begin(), arr.end(), compare);
    for (int i = 0; i < n; i++)
    {
        cout << arr[i].first << " " << arr[i].second << '\n';
    }
}