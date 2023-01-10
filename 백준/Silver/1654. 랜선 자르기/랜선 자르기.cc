#include <iostream>
#include <vector>
using namespace std;
int K, N, ans;
vector<int> arr;
int main()
{
    cin.tie(0);
    cout.tie(0);
    cin.sync_with_stdio(0);

    cin >> K >> N;
    long long int maxlen = 0;
    for (int i = 0; i < K; i++)
    {
        int a;
        cin >> a;
        arr.push_back(a);
        if (maxlen < a)
            maxlen = a;
    }
    long long int start, mid, end;
    start = 1;
    end = maxlen;

    while (start <= end)
    {
        mid = (start + end) / 2;
        int cnt = 0;
        for (int i = 0; i < K; i++)
        {
            cnt += arr[i] / mid;
        }
        if (cnt < N)
        {
            end = mid - 1;
        }
        else
        {
            ans = mid;
            start = mid + 1;
        }
    }
    cout << ans;
}