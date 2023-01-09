#include <iostream>
#include <string>
#include <vector>
#include <cstdio>

using namespace std;

vector<int> getstring(string s2)
{
    int l = s2.size(), j = 0;
    vector<int> now(l, 0);
    for (int i = 1; i < l; i++)
    {
        while (j > 0 && s2[i] != s2[j])
        {
            j = now[j - 1];
        }
        if (s2[i] == s2[j])
            now[i] = ++j;
    }
    return now;
}

vector<int> kmp(string s1, string s2)
{
    vector<int> ans;    
    auto now = getstring(s2);
    int l1 = s1.size(), l2 = s2.size(), j = 0;
    for (int i = 0; i < l1; i++)
    {
        while (j > 0 && s1[i] != s2[j])
        {
            j = now[j - 1];
        }
        if (s1[i] == s2[j])
        {
            if (j == l2 - 1)
            {
                ans.push_back(i - l2 + 1);
                j = now[j];
            }
            else
                j++;
        }
    }
    return ans;
}

int main()
{
    cin.tie(0);
    cin.sync_with_stdio(0);

    //freopen("input.txt", "r", stdin);

    string s1, s2;
    getline(cin,s1);
    getline(cin,s2);
    auto now = kmp(s1, s2);
    cout<<now.size()<<'\n';
    for(auto it : now)
    {
        cout<<it+1<<'\n';
    }
    return 0;
}