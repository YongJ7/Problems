#include <bits/stdc++.h>

using namespace std;

vector<int> solution(vector<int> arr) {
    vector<int> answer;
    int min=2e9;
    for(int i=0;i<arr.size();i++){
        if(min>arr[i]) min=arr[i];
    }
    if(arr.size()==1) answer.push_back(-1);
    else {
        for(int i=0;i<arr.size();i++){
            if(arr[i]!=min) answer.push_back(arr[i]);
        }
    }
    return answer;
}