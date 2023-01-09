#include <bits/stdc++.h>
using namespace std;
map<long long int, int> m;
int N, K;
int sum[200001];
int main()
{
    cin >> N >> K;
    for (int i = 1; i <= N; i++)
    {
        int a;
        cin >> a;
        sum[i] = sum[i - 1] + a;
    }
    long long int cnt = 0;
    m[0] = 1;
    for (int i = 1; i <= N; i++)
    {
        cnt += m[sum[i] - K];
        m[sum[i]]++;
    }
    cout << cnt;
    return 0;
}