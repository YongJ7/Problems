#include <string>
#include <vector>

using namespace std;

string solution(string s) {
    string answer = "";
    if(s[0]>='a'&&s[0]<='z') answer.push_back(s[0]-32);
    else answer.push_back(s[0]);
    for(int i=1;i<s.size();i++){
        if(i==s.size()-1&&s[i]==' ') {answer.push_back(s[i]); break;}
        if(s[i]>='A'&&s[i]<='Z') answer.push_back(s[i]+32);
        else if(s[i]==' '){
            answer.push_back(' ');
            if(s[i+1]==' ') continue;
            if(s[i+1]>='a'&&s[i+1]<='z') answer.push_back(s[i+1]-32);
            else answer.push_back(s[i+1]);
            i++;
        }
        else answer.push_back(s[i]);
    }
    return answer;
}