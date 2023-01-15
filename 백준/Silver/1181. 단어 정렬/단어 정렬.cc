#include <bits/stdc++.h>
using namespace std;
vector<string> arr;
bool compare(string a, string b)
{
    if (a.size() == b.size())
        return a < b;
    return a.size() < b.size();
}
int main()
{
    cin.tie(0);
    cin.sync_with_stdio(false);
    int n;
    cin >> n;
    for (int i = 0; i < n; i++)
    {
        string s;
        cin >> s;
        if (find(arr.begin(), arr.end(), s) == arr.end())
            arr.push_back(s);
    }
    sort(arr.begin(), arr.end(), compare);
    for (int i = 0; i < arr.size(); i++)
    {
        cout << arr[i] << '\n';
    }
}