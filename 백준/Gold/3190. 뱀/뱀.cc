#include <iostream>
#include <deque>
#include <vector>

using namespace std;

int d[4][2] = {
    0, 1,
    1, 0,
    0, -1,
    -1, 0};

deque<pair<int, int>> dq;
int map[101][101];
vector<pair<int, char>> arr;
bool used[101][101];
int N, K, L, ans;

void InputData()
{
    cin >> N >> K;
    for (int i = 0; i < K; i++)
    {
        int x, y;
        cin >> x >> y;
        map[x - 1][y - 1] = 1;
    }
    cin >> L;
    for (int i = 0; i < L; i++)
    {
        int a;
        char b;
        cin >> a >> b;
        arr.push_back({a, b});
    }
}

void solve()
{
    int x = 0, y = 0, idx = 0, bang = 0;
    dq.push_front({x, y});
    used[0][0] = true;

    while (1)
    {
        ans++;
        int nx = x + d[bang][0];
        int ny = y + d[bang][1];

        if (nx < 0 || ny < 0 || nx >= N || ny >= N || used[nx][ny])
            break;

        used[nx][ny] = true;
        dq.push_front({nx, ny});
        x = nx;
        y = ny;

        if (map[nx][ny] == 0)
        {
            int nnx = dq.back().first;
            int nny = dq.back().second;
            used[nnx][nny] = false;
            dq.pop_back();
        }
        else
            map[nx][ny] = 0;

        if (ans == arr[idx].first)
        {
            if (arr[idx].second == 'D')
            {
                bang++;
                if (bang > 3)
                    bang = 0;
            }
            else
            {
                bang--;
                if (bang < 0)
                    bang = 3;
            }
            idx++;
        }
    }
}
int main()
{
    // freopen("../input.txt", "r", stdin);
    InputData();

    solve();

    cout << ans << '\n';
    return 0;
}