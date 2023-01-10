#include <bits/stdc++.h>
using namespace std;

int solution(string dartResult) {
    int answer = 0;
    int cnt =0;
    int i=0;
    int num[4]={0};
    string s="";
    while(1){
        if(i==dartResult.size()) break;
        if(dartResult[i]=='S'){
            num[cnt]=stoi(s);
            cnt++;
            i++;
            s.clear();
            continue;
        }
        if(dartResult[i]=='D'){
            num[cnt]=pow(stoi(s),2);
            cnt++;
            i++;
            s.clear();
            continue;
        }
        if(dartResult[i]=='T'){
            num[cnt]=pow(stoi(s),3);
            cnt++;
            i++;
            s.clear();
            continue;
        }
        if(dartResult[i]=='*'){
            for(int j=cnt-2;j<=cnt-1;j++){
                num[j]*=2;
            }
            i++;
            s.clear();
            continue;
        }
        if(dartResult[i]=='#'){
            num[cnt-1]*=-1;
            s.clear();
            i++;
            continue;
        }
        s+=dartResult[i];
        i++;
    }
    for(int i=0;i<3;i++){
        answer+=num[i];
    }
    return answer;
}