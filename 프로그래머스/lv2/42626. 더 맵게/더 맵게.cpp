#include <string>
#include <vector>
#include <queue>

using namespace std;
priority_queue< long long int, vector<long long int>, greater<long long int> > q;
int solution(vector<int> scoville, int K) {
    int answer = 0;
    for(int i=0;i<scoville.size();i++) q.push(scoville[i]);
    while(!q.empty())
    {
        if(q.top()>=K) break;
        long long int a=q.top();
        q.pop();
        if(q.empty()) return -1;
        long long int b=q.top();
        q.pop();
        q.push(a+b*2);
        answer++;
    }
    return answer;
}