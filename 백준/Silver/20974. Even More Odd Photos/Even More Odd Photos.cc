#include <bits/stdc++.h>
using namespace std;

int odd, even, N;
int main()
{
    cin >> N;
    int a;
    for (int i = 0; i < N; i++)
    {
        cin >> a;
        if (a % 2 == 0)
            even++;
        else
            odd++;
    }
    while (odd > even)
    {
        odd -= 2;
        even++;
    }
    if (even > odd + 1)
        even = odd + 1;
    cout << odd + even;

    return 0;
}