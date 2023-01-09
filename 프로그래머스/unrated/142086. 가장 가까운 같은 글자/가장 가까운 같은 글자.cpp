#include <string>
#include <vector>
#include <string.h>

using namespace std;
int alp[30];
vector<int> solution(string s) {
    vector<int> answer;
    memset(alp,-1,sizeof(alp));
    int l = s.size();
    
    for(int i=0;i<l;i++)
    {
        if(alp[s[i]-'a'] != -1){
            answer.push_back(i-alp[s[i]-'a']);
            alp[s[i]-'a'] = i;
        }
        else{
            answer.push_back(-1);
            alp[s[i]-'a'] = i;
        }
    }
    return answer;
}