#include <iostream>

using namespace std;

int map[101][101];
int ans;
int main()
{
    // freopen("../input.txt", "r", stdin);
    int N;
    cin >> N;

    while (N--)
    {
        int x, y;
        cin >> x >> y;
        for (int i = x; i < x + 10; i++)
        {
            for (int j = y; j < y + 10; j++)
            {
                map[i][j] = 1;
            }
        }
    }

    for (int i = 1; i <= 100; i++)
    {
        for (int j = 1; j <= 100; j++)
        {
            if (map[i][j])
                ans++;
        }
    }

    cout << ans << '\n';
}