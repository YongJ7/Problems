#include <string>
#include <vector>

using namespace std;

vector<int> solution(vector<int> progresses, vector<int> speeds) {
    vector<int> answer;
    int a=0;
    while(1)
    {
        if(a==progresses.size()) break;
        for(int i=a;i<progresses.size();i++){
            if(progresses[i]>=100){
                progresses[i]=100;
                continue;
            }
            progresses[i]+=speeds[i];
        }
        int cnt=1;
        if(progresses[a]==100){
            a++;
            while(1){
                if(a==progresses.size()) break;
                else if(progresses[a]==100){
                    cnt++;
                    a++;
                }
                else break;
            }
            answer.push_back(cnt);
        }   
    }
    return answer;
}