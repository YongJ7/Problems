#include <iostream>
#include <vector>
#include <algorithm>
#define FOR(i, n) for (int i = 1; i <= n; i++)

using namespace std;

int R, C, M, r, c, s, d, z, ans, cnt;
pair<int, vector<int>> map[111][111];
struct shark
{
    int Row, Col, Speed, Direction, Size;
};
vector<shark> arr;
int DIR[5][2] = {
    0, 0,
    -1, 0,
    1, 0,
    0, 1,
    0, -1};

bool comp(int a,int b)
{
    return arr[a].Size > arr[b].Size;
}
int main()
{
    cin.tie(0);
    cin.sync_with_stdio(0);
    //freopen("input.txt","r",stdin);
    cin >> R >> C >> M;
    if(M==0){
        cout<<ans<<'\n';
        return 0;
    }
    arr.push_back({0, 0, 0, 0, 0});
    FOR(i, M)
    {
        cin >> r >> c >> s >> d >> z;
        arr.push_back({r, c, s, d, z});
        map[r][c].first++;
        map[r][c].second.push_back(i);
    }

    FOR(i, C) // 오른쪽으로 한칸씩 이동
    {
        if(cnt==M) break;
        FOR(j, R) // 그 열에 땅에 가장 가까운 상어 잡기
        {
            if (map[j][i].first > 0)
            {
                //cout << arr[map[j][i].second[0]].Size<<'\n';
                ans += arr[map[j][i].second[0]].Size;
                cnt++;
                arr[map[j][i].second[0]].Size = 0;
                map[j][i].first--;
                map[j][i].second.clear();
                break;
            }
        }

        FOR(j,M)
        {
            if(arr[j].Size == 0) continue;
            map[arr[j].Row][arr[j].Col].first = 0;
            map[arr[j].Row][arr[j].Col].second.clear();
        }

        FOR(j, M)
        {
            if (arr[j].Size == 0)
                continue;
            int x = arr[j].Row;
            int y = arr[j].Col;
            int D = arr[j].Direction;
            int S = arr[j].Speed;

            if (D == 1 || D == 2)
            {
                int v = (R - 1) * 2;
                if(S >= v) S %= v;
                FOR(t, S)
                {
                    int nx = x + DIR[D][0];

                    if (nx < 1)
                    {
                        D = 2;
                        nx += 2;
                    }
                    if (nx > R)
                    {
                        D = 1;
                        nx -= 2;
                    }
                    x = nx;
                }
            }
            else
            {
                int v = (C - 1) * 2;
                if(S >= v) S %= v;
                FOR(t, S)
                {
                    int ny = y + DIR[D][1];

                    if (ny < 1)
                    {
                        D = 3;
                        ny += 2;
                    }
                    if (ny > C)
                    {
                        D = 4;
                        ny -= 2;
                    }
                    y = ny;
                }
            }
            arr[j].Row = x;
            arr[j].Col = y;
            arr[j].Direction = D;
            map[x][y].first++;
            map[x][y].second.push_back(j);
        }
        FOR(x, R)
        {
            FOR(y, C)
            {
                if (map[x][y].first > 1)
                {
                    sort(map[x][y].second.begin(),map[x][y].second.end(),comp);
                    int idx = map[x][y].second[0];
                    FOR(j,map[x][y].first-1)
                    {
                        cnt++;
                        arr[map[x][y].second[j]].Size = 0;
                    }
                    map[x][y].first = 1;
                    map[x][y].second.clear();
                    map[x][y].second.push_back(idx);
                }
            }
        }
    }
    cout << ans << '\n';

    return 0;
}