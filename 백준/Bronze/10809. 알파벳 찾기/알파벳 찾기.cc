#include <iostream>
#include <string>
#include <vector>
using namespace std;
vector<int> arr(26, -1);
int main()
{
    string s;
    cin >> s;

    for (int i = 0; i < s.size(); i++)
    {
        if (arr[s[i] - 'a'] >= 0)
            continue;
        arr[s[i] - 'a'] = i;
    }
    for (int i = 0; i < 26; i++)
    {
        cout << arr[i] << " ";
    }
}