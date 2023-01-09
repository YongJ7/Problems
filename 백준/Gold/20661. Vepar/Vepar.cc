#include <bits/stdc++.h>
using namespace std;
int t, a, b, c, d, l;
int sosu[10000007];
int thtn[700000];
int M = 1e7;

void findsosu()
{
    thtn[l++] = 2;
    for (int i = 3; i <= M; i += 2)
    {
        if (sosu[i] != 0)
            continue;

        thtn[l++] = i;
        if (i > M / i)
            continue;

        for (int j = i * i; j <= M; j += i + i)
            sosu[j] = 1;
    }
}

int countk(int q, int s)
{
    int cnt = 0;
    if (q < s)
        return 0;
    for (int v = s;;)
    {
        cnt += q / v;
        if (v > q / s)
            break;
        v *= s;
    }
    return cnt;
}
int main()
{
    findsosu();
    cin >> t;
    for (int i = 0; i < t; i++)
    {
        cin >> a >> b >> c >> d;
        bool OK = true;
        for (int j = 0; j < l; j++)
        {
            if (countk(d, thtn[j]) + countk(a - 1, thtn[j]) < countk(b, thtn[j]) + countk(c - 1, thtn[j]))
            {
                cout << "NE\n";
                OK = false;
                break;
            }
        }
        if (OK)
            cout << "DA\n";
    }
}