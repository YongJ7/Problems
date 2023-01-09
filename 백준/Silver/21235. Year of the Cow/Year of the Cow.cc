#include <bits/stdc++.h>
using namespace std;
int N;
string s1,s2,s3,s4,s5,s6,s7,s8;
map<string, int> m;
string cycle[13] = { "","Ox", "Tiger", "Rabbit", "Dragon", "Snake", "Horse", "Goat", "Monkey", "Rooster", "Dog", "Pig", "Rat" };

int main()
{
    cin >> N;

    m["Bessie"] = 12001;
    for (int i = 0; i < N; i++)
    {
        cin >> s1>>s2>>s3>>s4>>s5>>s6>>s7>>s8;
        if (s4 == "previous")
        {
            int y = m[s8];
            int cnt = 1;
            int d = y%12-1;
            while (1)
            {  
                if (d == -1) d = 11;
                if (d == 0)
                    d = 12;
                if (cycle[d] == s5)
                    break;
                cnt++;
                d--;
            }
            m[s1] = y - cnt;
        }
        else
        {
            int y = m[s8];
            int cnt = 1;
            int d = y%12+1;
            while (1)
            {
                if (d == 13)
                    d = 1;
                if (cycle[d] == s5)
                    break;
                cnt++;
                d++;
            }
            m[s1] = y + cnt;
        }
    }
    int s = m["Bessie"] - m["Elsie"];
    cout << abs(s);
}