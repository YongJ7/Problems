#include <bits/stdc++.h>
using namespace std;
int N, fnum, snum, sum, newnum, cnt;
int arr[10];
int main()
{
    cin.tie(0);
    cin.sync_with_stdio(0);
    int a, b, c;
    cin >> a >> b >> c;
    int s = a * b * c;
    string num = to_string(s);
    for (int i = 0; i < num.size(); i++)
    {
        arr[num[i] - '0']++;
    }
    for (int i = 0; i < 10; i++)
    {
        cout << arr[i] << '\n';
    }
}