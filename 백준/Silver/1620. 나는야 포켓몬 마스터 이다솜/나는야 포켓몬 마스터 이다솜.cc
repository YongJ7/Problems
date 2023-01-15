#include <bits/stdc++.h>
using namespace std;
int n, m;
unordered_map<string, int> p;
unordered_map<int, string> mm;
int main()
{
    cin.tie(0);
    cin.sync_with_stdio(0);
    cin >> n >> m;
    for (int i = 1; i <= n; i++)
    {
        string s;
        cin >> s;
        p[s] = i;
        mm[i] = s;
    }
    for (int i = 0; i < m; i++)
    {
        string in;
        cin >> in;
        if (in[0] >= '0' && in[0] <= '9')
        {
            cout << mm[stoi(in)] << '\n';
        }
        else
        {
            cout << p[in] << '\n';
        }
    }
}