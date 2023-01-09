#include <iostream>
#include <string>

using namespace std;

int map[10][10];
bool row[10][10];
bool col[10][10];
bool square[10][10];

void DFS(int cnt)
{
    int x = cnt / 9;
    int y = cnt % 9;

    if(cnt == 81)
    {
        for(int i=0;i<9;i++)
        {
            for(int j=0;j<9;j++)
            {
                cout<<map[i][j];
            }
            cout<<'\n';
        }
        exit(0);
    }

    if(map[x][y] == 0)
    {
        for(int i=1;i<=9;i++)
        {
            if(row[x][i] == false && col[y][i] == false && square[(x/3)*3 + (y/3)][i] == false)
            {
                row[x][i] = true;
                col[y][i] = true;
                square[(x/3)*3 + (y/3)][i] = true;
                map[x][y] = i;
                DFS(cnt+1);
                map[x][y] = 0;
                row[x][i] = false;
                col[y][i] = false;
                square[(x/3)*3 + (y/3)][i] = false;
            }
        }
    }
    else DFS(cnt+1);
}
int main()
{
    cin.tie(0);
    cin.sync_with_stdio(0);
    //freopen("input.txt","r",stdin);
    for (int i = 0; i < 9; i++)
    {
        string s;
        cin >> s;
        for (int j = 0; j < 9; j++)
        {
            map[i][j] = s[j] - '0';
            if (map[i][j] != 0)
            {
                row[i][map[i][j]] = true;
                col[j][map[i][j]] = true;
                square[(i/3)*3 + (j/3)][map[i][j]] = true;
            }
        }
    }
    DFS(0);
}