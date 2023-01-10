#include <bits/stdc++.h>
using namespace std;
int skajwl[42];
int cnt;
int main()
{
    int A;
    for (int i = 0; i < 10; i++)
    {
        cin >> A;
        int x = A % 42;
        skajwl[x]++;
    }
    for (int i = 0; i < 42; i++)
    {
        if (skajwl[i] > 0)
            cnt++;
    }
    cout << cnt;
}