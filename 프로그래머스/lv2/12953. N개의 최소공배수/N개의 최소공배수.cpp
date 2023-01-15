#include <string>
#include <vector>
#include <algorithm>

using namespace std;

int chlth(int x,int y){
    if(x>y){
        int t=x;
        x=y;
        y=t;
    }
    if(y%x==0) return x;
    else{
        int s=0;
        for(int i=1;i<x;i++){
            if(x%i==0&&y%i==0) s=i;
        }
        return s;
    }
}
int solution(vector<int> arr) {
    int answer = 0;
    sort(arr.begin(),arr.end());
    int a=chlth(arr[0],arr[1]);
    answer=arr[0]*arr[1]/a;
    for(int i=2;i<arr.size();i++){
        a=chlth(answer,arr[i]);
        answer=answer*arr[i]/a;
    }
    return answer;
}