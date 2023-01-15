#include <bits/stdc++.h>
using namespace std;
int N;
int arr[101];
int main()
{
    cin >> N;
    for (int i = 0; i < N; i++)
    {
        cin >> arr[i];
    }
    int ans = 0;
    for (int i = 0; i < N; i++)
    {
        int sum = 0;
        int cnt = 0;
        int avg = 0;
        for (int j = i; j < N; j++)
        {
            sum += arr[j];
            cnt++;
            if (sum % cnt == 0)
            {
                avg = sum / cnt;
                int f = 0;
                for (int k = i; k <= j; k++)
                {
                    if (arr[k] == avg)
                        f = 1;
                }
                if (f == 1)
                    ans++;
            }
        }
    }
    cout << ans;
    return 0;
}