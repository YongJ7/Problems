#include <bits/stdc++.h>

using namespace std;

vector<string> split(string str,char delimiter)
{
    istringstream iss(str);
    string buffer;
    
    vector<string> result;
    
    while(getline(iss,buffer,delimiter))
    {
        result.push_back(buffer);
    }
    
    return result;
}
vector<int> solution(vector<string> id_list, vector<string> report, int k) {
    vector<int> answer;
    unordered_map<string,int> cnt; // 누적 신고 횟수
    unordered_map<string,set<string>> um; // 어떤 유저가 어떤 유저를 신고했는지
    
    sort(report.begin(), report.end());
    report.erase(unique(report.begin(), report.end()), report.end());
    int l = report.size();
    for(int i=0;i<l;i++)
    {
        vector<string> result = split(report[i],' ');
        um[result[0]].insert(result[1]);
        cnt[result[1]]++;
    }
    for(auto id : id_list)
    {
        int count = 0;
        for(auto report_id : um[id])
        {
            if(cnt[report_id]>=k) count++;
        }
        answer.push_back(count);
    }
    return answer;
}