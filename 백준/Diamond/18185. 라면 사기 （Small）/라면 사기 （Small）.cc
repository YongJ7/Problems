#include <iostream>
#include <algorithm>
using namespace std;
int n, arr[10010], ans;
void Two(int i)
{
    int t = min(arr[i], arr[i + 1] - arr[i + 2]);
    ans += (5 * t);
    arr[i] -= t;
    arr[i + 1] -= t;
}
void Three(int i)
{
    int t = min(arr[i], min(arr[i + 1], arr[i + 2]));
    ans += 7 * t;
    arr[i] -= t;
    arr[i + 1] -= t;
    arr[i + 2] -= t;
}
int main()
{
    cin.tie(0);
    cin.sync_with_stdio(0);

    cin >> n;
    for (int i = 0; i < n; i++)
    {
        cin >> arr[i];
    }

    for (int i = 0; i < n; i++)
    {
        if (arr[i + 1] > arr[i + 2])
        {
            Two(i);
            Three(i);
        }
        else
        {
            Three(i);
            int t = min(arr[i], arr[i + 1]);
            ans += 5 * t;
            arr[i] -= t;
            arr[i + 1] -= t;
        }
        ans += (3 * arr[i]);
    }
    cout << ans;
}