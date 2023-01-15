#include <string>
#include <vector>
#include <algorithm>
#include <iostream>
using namespace std;

vector<string> solution(int n, vector<int> arr1, vector<int> arr2) {
    vector<string> answer;
    string a1[20],a2[20];
    for(int x=0;x<n;x++){
        for (int i = n-1; i >= 0; --i) 
        { 
            a1[x] += to_string(arr1[x] >> i & 1);
            a2[x] += to_string(arr2[x] >> i & 1);
        }
    }
    
    for(int i=0;i<n;i++){
        string a="";
        for(int j=0;j<n;j++){
            if(a1[i][j]=='1'||a2[i][j]=='1') a+='#';
            else a+=' ';
        }
        answer.push_back(a);
    }
    return answer;
}