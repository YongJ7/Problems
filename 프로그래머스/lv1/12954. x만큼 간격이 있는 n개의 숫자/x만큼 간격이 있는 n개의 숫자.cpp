#include <string>
#include <vector>

using namespace std;

vector<long long int> solution(int x, int n) {
    vector<long long int> answer;
    long long int t=x;
    for(int i=0;i<n;i++){
        answer.push_back(t);
        t+=x;
    }
    
    return answer;
}