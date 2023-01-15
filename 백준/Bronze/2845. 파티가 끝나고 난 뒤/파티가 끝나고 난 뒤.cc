#include <iostream>
using namespace std;
int main()
{
    int a,b;
    cin>>a>>b;
    int sum = a*b;
    int arr[5];
    for(int i=0;i<5;i++){
        cin>>arr[i];
        arr[i]-=sum;
    }
    for(int i=0;i<5;i++){
        cout<<arr[i]<<" ";
    }
}