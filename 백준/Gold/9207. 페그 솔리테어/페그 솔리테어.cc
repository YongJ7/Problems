#include <iostream>
#include <algorithm>
using namespace std;
int d[4][2] = {
    0, 1,
    0, -1,
    1, 0,
    -1, 0};
char arr[5][9];
int result, pin;

void solve()
{
    for (int i = 0; i < 5; i++)
    {
        for (int j = 0; j < 9; j++)
        {
            if (arr[i][j] == 'o')
            {
                for (int k = 0; k < 4; k++)
                {
                    int nx = j + d[k][0];
                    int ny = i + d[k][1];
                    if (nx >= 0 && ny >= 0 && nx < 9 && ny < 5 && arr[ny][nx] == 'o')
                    {
                        int nnx = nx + d[k][0];
                        int nny = ny + d[k][1];
                        if (nnx >= 0 && nny >= 0 && nnx < 9 && nny < 5 && arr[nny][nnx] == '.')
                        {
                            arr[nny][nnx] = 'o';
                            arr[ny][nx] = '.';
                            arr[i][j] = '.';
                            solve();
                            arr[nny][nnx] = '.';
                            arr[ny][nx] = 'o';
                            arr[i][j] = 'o';
                        }
                    }
                }
            }
        }
    }
    int temp = 0;
    for (int i = 0; i < 5; i++)
        for (int j = 0; j < 9; j++)
            if (arr[i][j] == 'o')
                temp++;
    result = min(result, temp);
}

int main()
{
    //freopen("../input.txt", "r", stdin);
    int T;
    cin >> T;
    while (T--)
    {
        result = 9;
        pin = 0;
        for (int i = 0; i < 5; i++)
            for (int j = 0; j < 9; j++)
            {
                cin >> arr[i][j];
                if (arr[i][j] == 'o')
                    pin++;
            }
        solve();
        cout << result << " " << pin - result << '\n';
    }
}