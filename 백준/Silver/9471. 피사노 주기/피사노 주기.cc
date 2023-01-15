#include <iostream>
#include <vector>

using namespace std;

int main()
{
    cin.tie(0);
    cin.sync_with_stdio(0);
    int P; cin >>P;
    while(P--)
    {
        int T,num; cin>>T>>num;

        vector<int> fibo;
        fibo.push_back(0);
        fibo.push_back(1);
        fibo.push_back(1);

        int n = 3;
        while(1)
        {
            fibo.push_back((fibo[n-2] + fibo[n-1]) % num);
            if(fibo[n-1] % num == 0 && fibo[n] % num == 1)
            {
                break;
            }
            n++;
        }
        cout<<T<<" "<<n-1<<'\n';
    }
}