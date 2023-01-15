#include <bits/stdc++.h>
using namespace std;

int main()
{
    int t;
    cin >> t;
    for (int i = 0; i < t; i++)
    {
        for (int j = t - 1; j >= 0; j--)
        {
            if (j <= i)
                cout << "*";
            else
                cout << " ";
        }
        cout << '\n';
    }
}