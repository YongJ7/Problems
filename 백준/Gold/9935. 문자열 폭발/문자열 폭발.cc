#include <iostream>
#include <vector>
#include <string>

using namespace std;

int main()
{
    cin.tie(0);
    cin.sync_with_stdio(0);

    string s, a;
    cin >> s >> a;
    int l = s.size();
    int la = a.size();

    vector<char> arr;

    for (int i = 0; i < l; i++)
    {
        arr.push_back(s[i]);
        if (arr.size() >= la)
        {
            bool bomb = true;
            for (int t = 0; t < la; t++)
            {
                if(arr[arr.size()-la+t] != a[t])
                {
                    bomb = false;
                    break;
                }
            }
            if(bomb){
                for(int i=0;i<la;i++)
                {
                    arr.pop_back();
                }
            }
        }
    }
    if(arr.empty()) cout<<"FRULA\n";
    else{
        for(int i=0;i<arr.size();i++)
        {
            cout<<arr[i];
        }
    }
}