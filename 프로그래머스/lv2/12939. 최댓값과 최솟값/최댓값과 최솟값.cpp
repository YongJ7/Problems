#include <string>
#include <algorithm>
#include <vector>

using namespace std;

string solution(string s) {
    string answer = "";
    vector<int> a;
    string t;
    for(int i=0;i<s.size();i++){

        if(s[i]==' ') {
            a.push_back(stoi(t));
            t.clear();
        }
        else t+=s[i];
    }
    a.push_back(stoi(t));
    sort(a.begin(),a.end());
    answer+=to_string(a.front())+" "+to_string(a.back());
    return answer;
}