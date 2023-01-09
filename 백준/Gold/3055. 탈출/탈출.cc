#include <iostream>
#include <queue>

using namespace std;
#define MAXN (50)
int R, C, ans; //지도 세로, 가로 크기
struct st
{
    int x, y;
};

char map[MAXN + 10][MAXN + 10];
int d[4][2] = {
    0, 1,
    0, -1,
    1, 0,
    -1, 0};

st nest;
queue<st> water;
queue<st> artist;

void InputData()
{
    cin >> R >> C;
    for (int i = 0; i < R; i++)
    {
        cin >> map[i];
        for (int j = 0; j < C; j++)
        {
            if (map[i][j] == 'S')
                artist.push({i, j});
            if (map[i][j] == 'D')
                nest = {i, j};
            if (map[i][j] == '*')
                water.push({i, j});
        }
    }
}

void solve()
{
    while (!artist.empty())
    {
        int water_start = water.size();

        for (int i = 0; i < water_start; i++)
        {
            st now_water = water.front();
            water.pop();

            for (int j = 0; j < 4; j++)
            {
                int nx = now_water.x + d[j][0];
                int ny = now_water.y + d[j][1];

                if (nx >= 0 && nx < R && ny >= 0 && ny < C && map[nx][ny] == '.')
                {
                    water.push({nx, ny});
                    map[nx][ny] = '*';
                }
            }
        }

        int artist_start = artist.size();

        for (int i = 0; i < artist_start; i++)
        {
            st now_artist = artist.front();
            artist.pop();
            for (int j = 0; j < 4; j++)
            {
                int nx = now_artist.x + d[j][0];
                int ny = now_artist.y + d[j][1];

                if (nx == nest.x && ny == nest.y)
                {
                    ans++;
                    return;
                }
                if (nx >= 0 && nx < R && ny >= 0 && ny < C && map[nx][ny] == '.')
                {
                    artist.push({nx, ny});
                    map[nx][ny] = 'S';
                }
            }
        }
        ans++;
    }
    ans = -1;
    return;
}
int main()
{
    // freopen("../input.txt", "r", stdin);
    int T;
    // scanf("%d", &T);
    for (int t = 1; t <= 1; t++)
    {
        ans = 0;
        water = queue<st>();
        artist = queue<st>();

        InputData(); //입력 받는 부분
        solve();

        if (ans == -1)
            cout << "KAKTUS" << endl; //출력 하는 부분
        else
            cout << ans << endl;
    }
    return 0;
}