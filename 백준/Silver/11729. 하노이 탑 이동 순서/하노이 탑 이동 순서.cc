#include <bits/stdc++.h>
using namespace std;
void run(int a, int b, int c, int n)
{
    if (n == 1)
    {
        cout << a << " " << c << '\n';
    }
    else
    {
        run(a, c, b, n - 1);
        cout << a << " " << c << '\n';
        run(b, a, c, n - 1);
    }
}
int main()
{
    int n;
    cin >> n;
    cout << (int)pow(2, n) - 1 << '\n';
    run(1, 2, 3, n);
}