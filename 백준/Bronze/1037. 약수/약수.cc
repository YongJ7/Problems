#include <bits/stdc++.h>
using namespace std;
int n;
vector<int> dirtn;
int main()
{
    cin >> n;
    for (int i = 0; i < n; i++)
    {
        int a;
        cin >> a;
        dirtn.push_back(a);
    }
    sort(dirtn.begin(), dirtn.end());
    cout << dirtn[0] * dirtn[n - 1];
}