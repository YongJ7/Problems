#include <bits/stdc++.h>
using namespace std;
int test_case, p, n;

int main()
{
    cin >> test_case;
    while (test_case--)
    {
        cin >> p >> n;

        vector<pair<int, int>> arr;

        for (int i = 0; i < n; i++)
        {
            int a;
            cin >> a;
            arr.push_back({a, -i});
        }

        sort(arr.begin(), arr.end());

        vector<int> ans(n);

        for (int i = 0; i < n; i++)
        {
            int idx = -arr[i].second;
            ans[idx] = min(arr[i].first, p / (n - i));
            p -= ans[idx];
        }
        if (p > 0)
            cout << "IMPOSSIBLE\n";
        else
        {
            for (int i = 0; i < n; i++)
            {
                cout << ans[i] << " ";
            }
            cout << '\n';
        }
    }
}