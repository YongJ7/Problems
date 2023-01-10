#include <bits/stdc++.h>
using namespace std;

string solution(vector<string> seoul) {
    string answer = "";
    int a=0;
    for(int i=0;i<seoul.size();i++){
        if(seoul[i].compare("Kim")==0){ a=i;break;}
    }
    answer+="김서방은 ";
    answer+=to_string(a);
    answer+="에 있다";
    return answer;
}