#include <bits/stdc++.h>
using namespace std;
int n;
stack<int> q;
int main()
{
    cin >> n;
    int cnt = 0;
    for (int i = 0; i < n; i++)
    {
        int a;
        cin >> a;
        if (q.empty())
        {
            q.push(a);
            if (a == 0)
                continue;
            cnt++;
        }
        else if (q.top() < a)
        {
            q.push(a);
            cnt++;
        }
        else if (q.top() > a)
        {
            while (q.top() > a)
            {
                q.pop();
                if (q.empty())
                    break;
            }

            if (q.empty() || q.top() < a)
            {
                q.push(a);
                if (a == 0)
                    continue;
                cnt++;
            }
        }
    }
    cout << cnt;
    return 0;
}