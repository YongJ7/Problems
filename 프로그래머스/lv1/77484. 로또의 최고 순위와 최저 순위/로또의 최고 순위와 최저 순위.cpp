#include <string>
#include <vector>

using namespace std;

vector<int> solution(vector<int> lottos, vector<int> win_nums) {
    vector<int> answer;
    int cntt=0,cntf=0;
    for(int i=0;i<lottos.size();i++){
        if(lottos[i]==0) cntf++;
        else{
            for(int j=0;j<win_nums.size();j++){
                if(lottos[i]==win_nums[j])cntt++;
            }
        }
    }
    if(7-cntt-cntf==7) answer.push_back(6);
    else answer.push_back(7-cntt-cntf);
    
    if(cntt==0||cntt==1) answer.push_back(6);
    else answer.push_back(7-cntt);
    return answer;
}