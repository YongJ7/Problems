#include <bits/stdc++.h>
using namespace std;
int N, cnt;
int m[100001];
int f(int s)
{
    if (s == 0)
        return 0;
    for (int i = 0; i < 20; i++)
    {
        if (s <= pow(2, i))
            return i;
    }
}
int main()
{
    cin >> N;
    for (int i = 1; i < N; i++)
    {
        int a, b;
        cin >> a >> b;
        m[a]++;
        m[b]++;
    }
    for (int i = 2; i <= N; i++)
        m[i]--;
    cnt += N - 1;
    for (int i = 1; i <= N; i++)
    {
        cnt += f(m[i] + 1);
    }
    cout << cnt;
    return 0;
}