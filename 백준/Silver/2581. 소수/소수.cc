#include <bits/stdc++.h>
using namespace std;
int m, n;
bool arr[10001] = {false};
void sosu()
{
    int k = 10001;
    arr[0] = arr[1] = true;
    for (int i = 2; i < sqrt(k); i++)
    {
        if (arr[i] == false)
        {
            for (int j = i + i; j <= k; j += i)
            {
                arr[j] = true;
            }
        }
    }
}
int main()
{
    cin >> m >> n;
    sosu();
    int sum = 0;
    int min_num = 10002;
    for (int i = m; i <= n; i++)
    {
        if (arr[i] == false)
        {
            if (min_num > i)
                min_num = i;
            sum += i;
        }
    }

    if (sum == 0)
        cout << -1;
    else
    {
        cout << sum << '\n'
             << min_num;
    }
}