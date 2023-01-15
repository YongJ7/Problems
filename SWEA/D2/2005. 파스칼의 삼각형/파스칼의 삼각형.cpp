#include <bits/stdc++.h>
using namespace std;
int T;
int pascal[10][10] = {
    1,
};
int main()
{
    cin >> T;

    for (int i = 1; i < 10; i++)
    {
        pascal[i][0] = 1;
        for (int j = 1; j <= i; j++)
        {
            pascal[i][j] = pascal[i - 1][j - 1] + pascal[i - 1][j];
        }
    }
    int cnt = 1;
    for (int n = 0; n < T; n++)
    {
        int a;
        cin >> a;
        cout << "#" << cnt << '\n';
        cnt++;
        for (int i = 0; i < a; i++)
        {
            for (int j = 0; j < a; j++)
            {
                if (pascal[i][j] == 0)
                    continue;
                cout << pascal[i][j] << " ";
            }
            cout << '\n';
        }
    }
}