#include <bits/stdc++.h>
using namespace std;

int p1x, p1y, p2x, p2y, p3x, p3y;
int a;
int main()
{
    cin >> p1x >> p1y >> p2x >> p2y >> p3x >> p3y;
    a = (p2x - p1x) * (p3y - p1y) - (p3x - p1x) * (p2y - p1y);
    if (a > 0)
        cout << 1;
    else if (a < 0)
        cout << -1;
    else
        cout << 0;
    return 0;
}