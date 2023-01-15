#include <string>
#include <iostream>

using namespace std;

int main()
{
    cin.tie(0);
    cin.sync_with_stdio(0);

    int c; cin >> c;
    int ans = 0;
    string first_s = "for";
    string second_s = "while";

    for (int i = 0; i < c; i++)
    {
        string s; cin >> s;
        int l = s.size();
        int idx = 0, cnt = 0;
        while (idx < l)
        {
            if (s[idx] == first_s[0] && idx <= l - 3)
            {
                bool find_s = true;
                int now = 1, j;
                for (j = idx + 1; j < idx + 3; j++) {
                    if (s[j] != first_s[now]) {
                        find_s = false;
                        break;
                    }
                    else now++;
                }
                if (find_s) cnt++;
                idx = j - 1;
            }
            if (s[idx] == second_s[0] && idx <= l - 5) {
                bool find_s = true;
                int now = 1, j;
                for (j = idx + 1; j < idx + 5; j++) {
                    if (s[j] != second_s[now]) {
                        find_s = false;
                        break;
                    }
                    now++;
                }
                if (find_s) cnt++;
                idx = j-1;
            }
            idx++;
        }
        ans = ans > cnt ? ans : cnt;
    }
    cout << ans << '\n';
}