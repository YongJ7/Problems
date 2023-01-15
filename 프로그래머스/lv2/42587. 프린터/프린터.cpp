#include <string>
#include <vector>
#include <queue>
using namespace std;

queue<pair<int,int>> q;
priority_queue<int> m;
int solution(vector<int> priorities, int location) {
    int answer = 0;
    for(int i=0;i<priorities.size();i++){
        q.push({priorities[i],i});
        m.push(priorities[i]);
    }
    while(!q.empty()){
        int p=q.front().first;
        int l=q.front().second;
        q.pop();
        if(m.top()==p){
            answer++;
            m.pop();
            if(location==l) return answer;
        }
        else{
            q.push({p,l});
        }
        
    }
    return answer;
}