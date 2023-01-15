#include <bits/stdc++.h>
using namespace std;
vector<int> arr;
int num[8001];
int mid, range, mostnum, mean;
int main()
{
    cin.tie(0);
    cin.sync_with_stdio(false);
    int n;
    cin >> n;
    int most = -9999;
    int first = 0;
    for (int i = 0; i < n; i++)
    {
        int a;
        cin >> a;
        mean += a;
        arr.push_back(a);
        num[a + 4000]++;
    }
    sort(arr.begin(), arr.end());
    for (int i = 0; i < 8001; i++)
    {
        if (num[i] == 0)
            continue;
        if (num[i] == most)
        {
            if (first == 1)
            {
                mostnum = i - 4000;
                first = 0;
            }
        }
        if (num[i] > most)
        {
            most = num[i];
            mostnum = i - 4000;
            first = 1;
        }
    }
    mid = arr[arr.size() / 2];
    mean = round((double)mean / n);
    range = arr.back() - arr.front();
    cout << mean << '\n'
         << mid << '\n'
         << mostnum << '\n'
         << range;
}