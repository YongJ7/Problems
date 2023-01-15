#include <bits/stdc++.h>
using namespace std;
vector<pair<pair<int, string>, int>> arr;
bool compare(pair<pair<int, string>, int> a, pair<pair<int, string>, int> b)
{
    if (a.first.first == b.first.first)
        return a.second < b.second;
    else
        return a.first.first < b.first.first;
}
int main()
{
    cin.tie(0);
    cin.sync_with_stdio(false);
    int n;
    cin >> n;
    for (int i = 0; i < n; i++)
    {
        int a;
        string s;
        cin >> a >> s;
        arr.push_back({{a, s}, i});
    }
    sort(arr.begin(), arr.end(), compare);
    for (int i = 0; i < n; i++)
    {
        cout << arr[i].first.first << " " << arr[i].first.second << '\n';
    }
}