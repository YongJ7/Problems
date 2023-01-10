#include <bits/stdc++.h>
using namespace std;

vector<int> solution(vector<int> array, vector<vector<int>> commands) {
    vector<int> answer;
    for(int i=0;i<commands.size();i++){
        vector<int> newarray;
        for(int j=commands[i][0];j<=commands[i][1];j++){
            newarray.push_back(array[j-1]);
        }
        sort(newarray.begin(),newarray.end());
        answer.push_back(newarray[commands[i][2]-1]);
    }
    return answer;
}