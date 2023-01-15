#include <bits/stdc++.h>
using namespace std;
int T, a, b;
int EA(int a, int b)
{
    int c;
    while (b != 0)
    {
        c = a % b;
        a = b;
        b = c;
    }
    return a;
}
int LCM(int a, int b)
{
    int c = (a * b) / EA(a, b);
    return c;
}
int main()
{
    cin >> T;
    for (int i = 0; i < T; i++)
    {
        cin >> a >> b;
        cout << LCM(a, b) << '\n';
    }
}