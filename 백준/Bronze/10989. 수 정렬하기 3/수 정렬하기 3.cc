#include <iostream>
#include <algorithm>
using namespace std;
int arr[10001];
int main()
{
    cin.tie(0);
    cin.sync_with_stdio(false);
    int n;
    cin >> n;
    for (int i = 0; i < n; i++)
    {
        int a;
        cin >> a;
        arr[a]++;
    }
    for (int i = 1; i <= 10000; i++)
    {
        for (int j = 0; j < arr[i]; j++)
        {
            cout << i << '\n';
        }
    }
}