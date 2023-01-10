#include <iostream>
#include <string>

using namespace std;

int main()
{
    cin.tie(0);
    cin.sync_with_stdio(0);

    string s; cin>>s;
    while(s != "0")
    {
        bool pelendrom = true;
        int l = s.size();
        for(int i=0;i<l/2;i++)
            {
                if(s[i]!=s[l-i-1])
                {
                    pelendrom = false;
                    break;
                }
            }
        if(pelendrom) cout<<"yes\n";
        else cout<<"no\n";
        cin>>s;
    }
}