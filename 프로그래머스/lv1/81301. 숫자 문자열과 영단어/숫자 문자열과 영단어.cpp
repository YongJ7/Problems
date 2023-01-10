#include <bits/stdc++.h>
using namespace std;

int solution(string s) {
    string num[10]={"zero","one","two","three","four","five","six","seven","eight","nine"};
    string n[10]={"0","1","2","3","4","5","6","7","8","9"};
    for(int i=0;i<10;i++){
        while(s.find(num[i])!=string::npos){
            s.replace(s.find(num[i]),num[i].size(),n[i]);
        }
        
    }
    return stoi(s);
}