#include <bits/stdc++.h>
using namespace std;

int N;
string p;
char now;
int main()
{
    cin >> N;
    for (int j = 0; j < N; j++)
    {
        int t = 0;
        cin >> p;
        now = p[0];
        for (int i = 1; i <= p.size(); i++)
        {
            if (i == p.size())
            {
                p[i] = p[0];
            }
            if (now == p[i])
                continue;
            if (now == 'N')
            {
                if (p[i] == 'W')
                    t -= 90;
                else if (p[i] == 'E')
                    t += 90;
            }
            if (now == 'S')
            {
                if (p[i] == 'W')
                    t += 90;
                else if (p[i] == 'E')
                    t -= 90;
            }
            if (now == 'W')
            {
                if (p[i] == 'N')
                    t += 90;
                else if (p[i] == 'S')
                    t -= 90;
            }
            if (now == 'E')
            {
                if (p[i] == 'N')
                    t -= 90;
                else if (p[i] == 'S')
                    t += 90;
            }
            now = p[i];
        }
        if (t == 360)
            cout << "CW\n";
        if (t == -360)
            cout << "CCW\n";
    }
    return 0;
}