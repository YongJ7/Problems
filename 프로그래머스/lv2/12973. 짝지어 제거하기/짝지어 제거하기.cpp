#include<string>
#include <stack>
using namespace std;

int solution(string s)
{
    stack<char> a;
    if(s.size()%2!=0) return 0;
    a.push(s[0]);
    for(int i=1;i<s.size();i++){
        if(a.empty()||a.top()!=s[i]) a.push(s[i]);
        else a.pop();
    }
    if(a.empty()) return 1;
    return 0;
}