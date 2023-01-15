#include <bits/stdc++.h>
using namespace std;
int N, M;
vector<int> arr;
int main()
{
    cin.tie(0);
    cin.sync_with_stdio(0);
    cin >> N;
    for (int i = 0; i < N; i++)
    {
        int a;
        cin >> a;
        arr.push_back(a);
    }
    sort(arr.begin(), arr.end());
    cin >> M;
    for (int i = 0; i < M; i++)
    {
        int a;
        cin >> a;
        auto up = upper_bound(arr.begin(), arr.end(), a);
        auto low = lower_bound(arr.begin(), arr.end(), a);

        cout << up - low << " ";
    }
}