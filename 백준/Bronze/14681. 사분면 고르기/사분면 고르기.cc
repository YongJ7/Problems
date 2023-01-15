#include <bits/stdc++.h>
using namespace std;
int main()
{
    int x, y;
    cin >> x >> y;
    if (x > 0 && y > 0)
        cout << '1';
    if (x < 0 && y > 0)
        cout << '2';
    if (x < 0 && y < 0)
        cout << '3';
    if (x > 0 && y < 0)
        cout << '4';
}