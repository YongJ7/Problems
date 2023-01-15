#include <bits/stdc++.h>
using namespace std;

#define MAX 100000

int N, K, ans, cnt;
bool check[100001];
queue<pair<int, int>> q; 

int main()
{
    cin.sync_with_stdio(0);
    cin.tie(0);

    cin >> N >> K;

    q.push({N, 0});

    while (!q.empty())
    {
        int now = q.front().first;
        int time = q.front().second;
        q.pop();

        check[now] = true;

        if (cnt && ans == time && now == K)
            cnt++;

        if (!cnt && now == K)
        {
            ans = time;
            cnt++;
        }

        if (now - 1 >= 0 && !check[now - 1])
            q.push({now - 1, time + 1});

        if (now + 1 <= MAX && !check[now + 1])
            q.push({now + 1, time + 1});

        if (2 * now <= MAX && !check[2 * now])
            q.push({2 * now, time + 1});
    }
    cout << ans << '\n';
    cout << cnt << '\n';
}
