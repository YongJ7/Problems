#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
vector<pair<ll, pair<ll, ll>>> dp_count;
vector<string> dp_s;
int problem_num, N;
ll k;
char find_char;
char lookfor(ll idx, int d)
{
    if (d <= 2)
    {
        return dp_s[d][idx - 1];
    }

    ll lenght = dp_count[d - 3].first + dp_count[d - 3].second.first + dp_count[d - 3].second.second;

    if (lenght >= idx)
    {
        return lookfor(idx, d - 3);
    }
    else
    {
        return lookfor(idx - lenght, d - 2);
    }
}

int main()
{
    cin.tie(0);
    cin.sync_with_stdio(0);
    cin >> problem_num;
    dp_s.push_back("X");
    dp_s.push_back("YZ");
    dp_s.push_back("ZX");

    dp_count.push_back({1, {0, 0}});
    dp_count.push_back({0, {1, 1}});
    dp_count.push_back({1, {0, 1}});

    cin >> N;

    for (int i = 3; i < N; i++)
    {
        ll x = dp_count[i - 1].first;
        ll y = dp_count[i - 1].second.first;
        ll z = dp_count[i - 1].second.second;

        dp_count.push_back({z, {x, x + y}});
    }
    N--;
    if (problem_num == 1)
    {
        cout << dp_count[N].first + dp_count[N].second.first + dp_count[N].second.second;
    }
    if (problem_num == 2)
    {
        cin >> k;
        cout << lookfor(k, N);
    }
    if (problem_num == 3)
    {
        cin >> find_char;
        if (find_char == 'X')
            cout << dp_count[N].first;
        if (find_char == 'Y')
            cout << dp_count[N].second.first;
        if (find_char == 'Z')
            cout << dp_count[N].second.second;
    }
}