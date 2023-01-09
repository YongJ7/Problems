#include <bits/stdc++.h>
using namespace std;

int N;
double sx, sy;
double nx, ny;
double sjfqdl;
double sum;
int main()
{
    cin >> N;
    for (int i = 0; i < N; i++)
    {
        double x, y;
        cin >> x >> y;
        if (i == 0)
        {
            sx = x;
            sy = y;
            nx = x;
            ny = y;
            continue;
        }
        sum += (x * ny - y * nx);
        nx = x;
        ny = y;
    }
    sjfqdl = (sum + (sx * ny - sy * nx)) * 0.5;

    printf("%0.1lf", abs(sjfqdl));
    return 0;
}