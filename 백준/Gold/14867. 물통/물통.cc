#include <iostream>
#include <algorithm>
#include <queue>
#include <set>
using namespace std;

int A, B, C, D, ans;
queue<pair<int, int>> q;
set<int> map[100001];

void InputData()
{
    cin >> A >> B >> C >> D;
}

void solve()
{
    q.push({0, 0});
    map[0].insert(0);

    while (!q.empty())
    {
        int l = q.size();
        while (l--)
        {
            auto now = q.front();
            q.pop();
            if (now.first == C && now.second == D)
            {
                return;
            }
            for (int i = 0; i < 6; i++)
            {
                int x, y;
                if (i == 0)
                    x = A, y = now.second;
                else if (i == 1)
                    x = now.first, y = B;
                else if (i == 2)
                    x = 0, y = now.second;
                else if (i == 3)
                    x = now.first, y = 0;
                else if (i == 4)
                    x = min(A, now.first + now.second), y = now.second - min(A - now.first, now.second);
                else
                    x = now.first - min(B - now.second, now.first), y = min(B, now.first + now.second);

                if (map[x].find(y)==map[x].end())
                {
                    map[x].insert(y);
                    q.push({x, y});
                }
            }
        }
        ans++;
    }
    ans = -1;
}
int main()
{
    // freopen("../input.txt", "r", stdin);
    InputData(); //입력받는 부분

    solve();

    cout << ans << "\n"; // 출력하는 부분
    return 0;
}