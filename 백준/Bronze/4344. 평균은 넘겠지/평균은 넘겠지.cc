#include <bits/stdc++.h>
using namespace std;
int c, n;
vector<int> arr;
int main()
{
    cin.tie(0);
    cin.sync_with_stdio(0);
    cin >> c;
    for (int i = 0; i < c; i++)
    {
        cin >> n;
        arr.clear();
        int sum = 0;
        for (int j = 0; j < n; j++)
        {
            int a;
            cin >> a;
            arr.push_back(a);
            sum += a;
        }
        int cnt = 0;
        double avg = (double)sum / n;
        for (int j = 0; j < n; j++)
        {
            if (avg < arr[j])
                cnt++;
        }
        printf("%.3f%%\n", (double)cnt * 100 / n);
    }
}