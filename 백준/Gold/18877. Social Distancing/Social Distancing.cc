#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

int N, M;
vector<pair<long long, long long>> v;
long long ans;

void InputData()
{
    cin >> N >> M;
    for (int i = 0; i < M; i++)
    {
        long long a, b;
        cin >> a >> b;
        v.push_back({a, b});
    }
}

bool check(long long n)
{
    int idx = 0, cnt = 1;
    long long cow = v[0].first;

    while (idx < M && cnt <= N)
    {
        if (cow + n <= v[idx].second)
        {
            cnt += 1;
            if (cow + n >= v[idx].first)
                cow = cow + n;
            else
                cow = v[idx].first;
        }
        else
        {
            idx++;
        }
    }

    if (cnt >= N)
        return true;

    return false;
}

void solve()
{
    sort(v.begin(), v.end());

    long long l = 0, h = v[M - 1].second / (N - 1);

    while (l <= h)
    {
        long long mid = (l + h) / 2;
        if (check(mid))
        {
            ans = ans > mid ? ans : mid;
            l = mid + 1;
        }
        else
        {
            h = mid - 1;
        }
    }
}

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);
    // freopen("../input.txt", "r", stdin);

    InputData();

    solve();

    cout << ans << '\n';
    return 0;
}