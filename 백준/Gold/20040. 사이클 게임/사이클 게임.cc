#include <iostream>
using namespace std;
int n, m;
int arr[500001];
int ans;
int find(int a)
{
    if (arr[a] == a)
        return a;
    return arr[a] = find(arr[a]);
}
bool cycle(int a, int b)
{
    a = find(a);
    b = find(b);

    if (a == b)
        return true;
    else
    {
        arr[a] = b;
        return false;
    }
}
int main()
{
    cin.tie(0);
    cin.sync_with_stdio(0);
    cin >> n >> m;
    for (int i = 0; i < n; i++)
        arr[i] = i;

    for (int i = 1; i <= m; i++)
    {
        int a, b;
        cin >> a >> b;
        if (cycle(a, b))
        {
            ans = i;
            break;
        }
    }
    cout << ans;
}