#include <iostream>

using namespace std;

long long arr[1500010];
int num = 1000000;
long long n;
int main()
{
    cin.tie(0);
    cin.sync_with_stdio(0);
    cin>>n;
    arr[1] = 1;
    for(int i=0;i<1500000;i++)
    {
        arr[i+2] = (arr[i+1] + arr[i]) % num;
    }
    cout<<arr[n%1500000]<<'\n';
}