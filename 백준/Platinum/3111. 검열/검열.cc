#include <iostream>
#include <deque>
#include <string>
#include <algorithm>

using namespace std;

int main()
{
    cin.tie(0);
    cin.sync_with_stdio(0);

    string A,T; cin>>A>>T;
    int l = A.size();

    deque<char> D_F, D_B;
    int f = 0, b = T.size() - 1;
    while(f<=b)
    {
        while(f<=b)
        {
            bool flag = false;
            D_F.push_back(T[f++]);

            if(D_F.size() >= l)
            {
                flag = true;
                for(int i=0;i<l;i++)
                {
                    if(A[i] != D_F[D_F.size() - l + i])
                    {
                        flag = false;
                        break;
                    }
                }
            }
            if(flag)
            {
                for(int i=0;i<l;i++) D_F.pop_back();
                break;
            }
        }
        while(f<=b)
        {
            bool flag = false;
            D_B.push_front(T[b--]);
            
            if(D_B.size() >= l)
            {
                flag = true;
                for(int i=0;i<l;i++)
                {
                    if(A[i] != D_B[i])
                    {
                        flag = false;
                        break;
                    }
                }
            }
            if(flag)
            {
                for(int i=0;i<l;i++) D_B.pop_front();
                break;
            }
        }
    }

    string ans;
    for(int i=0;i<D_F.size();i++) ans += D_F[i];
    for(int i=0;i<D_B.size();i++) ans += D_B[i];

    while(ans.find(A) < 30000)
    {
        ans.erase(ans.find(A),l);
    }
    cout<<ans<<'\n';
}