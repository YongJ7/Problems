#include <bits/stdc++.h>
using namespace std;

int N, x[50], y[50], t[50];
char d[50];

struct C
{
    int i, j, time_i, time_j, move;
};
C I[2500];

int main()
{
    cin >> N;
    for (int i = 0; i < N; i++)
        cin >> d[i] >> x[i] >> y[i];

    int cnt = 0;
    for (int i = 0; i < N; i++)
    {
        for (int j = 0; j < N; j++)
        {

            if (d[i] == d[j])
                continue;

            int xi = x[i], yi = y[i], xj = x[j], yj = y[j];
            if (d[i] == 'E')
            {
                int t = xi;
                xi = yi;
                yi = t;
                t = xj;
                xj = yj;
                yj = t;
            }

            if (yi > yj)
                continue;
            if (xi < xj)
                continue;
            if (xi >= xj + yj - yi)
                continue;

            C inew = {i, j, yj - yi, xi - xj, 1};
            I[cnt] = inew;
            cnt++;
        }
    }

    while (1)
    {
        int f = -1;
        for (int i = 0; i < 2500; i++)
            if (I[i].move)
                if (f == -1 || I[i].time_i < I[f].time_i)
                    f = i;
        if (f == -1)
            break;
        if (t[I[f].i] == 0 && (t[I[f].j] == 0 || t[I[f].j] > I[f].time_j))
            t[I[f].i] = I[f].time_i;
        I[f].move = 0;
    }

    for (int i = 0; i < N; i++)
        if (t[i] == 0)
            cout << "Infinity\n";
        else
            cout << t[i] << "\n";

    return 0;
}