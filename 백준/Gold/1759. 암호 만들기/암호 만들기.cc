#include <bits/stdc++.h>
using namespace std;
int L, C;
char alp[16];
char path[16];
bool vowel[16];
void run(int lv, int n, int c, int v)
{
    if (lv == L)
    {
        if (c >= 2 && v >= 1)
        {
            for (int i = 0; i < L; i++)
            {
                cout << path[i];
            }
            cout << '\n';
        }
        return;
    }
    for (int i = n; i < C; i++)
    {
        path[lv] = alp[i];
        if (vowel[i])
            run(lv + 1, i + 1, c, v + 1);
        else
            run(lv + 1, i + 1, c + 1, v);
    }
}
int main()
{
    cin >> L >> C;
    for (int i = 0; i < C; i++)
    {
        cin >> alp[i];
    }
    sort(alp, alp + C);
    for (int i = 0; i < C; i++)
    {
        if (alp[i] == 'a' || alp[i] == 'e' || alp[i] == 'i' || alp[i] == 'o' || alp[i] == 'u')
            vowel[i] = true;
    }
    run(0, 0, 0, 0);
    return 0;
}