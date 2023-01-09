#include <bits/stdc++.h>
using namespace std;
int N, M;
long long int sum;
long long int cnt[1001];
int main()
{
    cin >> N >> M;
    for (int i = 1; i <= N; i++)
    {
        int a;
        cin >> a;
        sum += a;
        cnt[sum % M]++;
    }
    long long int h = 0;
    for (int i = 0; i < M; i++)
    {
        h += cnt[i] * (cnt[i] - 1) / 2;
    }
    cout << h + cnt[0];
    return 0;
}