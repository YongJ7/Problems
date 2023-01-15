#include <bits/stdc++.h>
using namespace std;
string s;
int num[1001];
int main()
{
    cin >> s;
    for (int i = 0; i < s.size(); i++)
    {
        if (s[i] >= 'a' && s[i] <= 'z')
            continue;
        int n = 0;
        int j = i;
        for (; j < s.size() && s[j] >= '0' && s[j] <= '9'; j++)
        {
            n *= 10;
            n += s[j] - '0';
        }

        num[n] = 1;
        i = j - 1;
    }
    int cnt = 0;
    for (int i = 0; i < 1001; i++)
    {
        if (num[i] == 1)
            cnt++;
    }
    cout << cnt;
}