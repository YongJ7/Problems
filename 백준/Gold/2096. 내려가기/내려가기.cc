#include <bits/stdc++.h>
using namespace std;
int n;
int dp_MIN[3];
int dp_MAX[3];
int main()
{
    cin >> n;
    for (int i = 0; i < 3; i++)
    {
        cin >> dp_MAX[i];
        dp_MIN[i] = dp_MAX[i];
    }

    for (int i = 1; i < n; i++)
    {
        int a, b, c;
        cin >> a >> b >> c;
        int t1 = dp_MIN[0];
        int t2 = dp_MIN[1];
        dp_MIN[0] = min(dp_MIN[0], dp_MIN[1]) + a;
        dp_MIN[1] = min(t1, min(dp_MIN[1], dp_MIN[2])) + b;
        dp_MIN[2] = min(t2, dp_MIN[2]) + c;

        int t3 = dp_MAX[0];
        int t4 = dp_MAX[1];
        dp_MAX[0] = max(dp_MAX[0], dp_MAX[1]) + a;
        dp_MAX[1] = max(max(dp_MAX[1], dp_MAX[2]), t3) + b;
        dp_MAX[2] = max(t4, dp_MAX[2]) + c;
    }

    int MIN = min(dp_MIN[0], min(dp_MIN[1], dp_MIN[2]));
    int MAX = max(dp_MAX[0], max(dp_MAX[1], dp_MAX[2]));

    cout << MAX << " " << MIN;
}