#include <bits/stdc++.h>
using namespace std;

int ccw(int ax, int ay, int bx, int by, int cx, int cy)
{
    long long v = (long long)(bx - ax) * (cy - ay) - (long long)(cx - ax) * (by - ay);
    if (v > 0)
        return 1;
    if (v < 0)
        return -1;
    return 0;
}

int main()
{
    int ax, ay, bx, by, cx, cy, dx, dy;
    cin >> ax >> ay >> bx >> by;
    cin >> cx >> cy >> dx >> dy;

    if (
        ccw(ax, ay, bx, by, cx, cy) * ccw(ax, ay, bx, by, dx, dy) < 0 &&
        ccw(cx, cy, dx, dy, ax, ay) * ccw(cx, cy, dx, dy, bx, by) < 0)
        cout << 1 << endl;
    else
        cout << 0 << endl;
}