#include <iostream>

using namespace std;

int chess[6] = {1,1,2,2,2,8};
int ans[6],input[6];
int main()
{    
    for(int i=0;i<6;i++)
    {
        cin>>input[i];
        ans[i] = chess[i]-input[i];
        cout<<ans[i]<<" ";
    }
    
}