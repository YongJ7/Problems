#include <string>
#include <vector>
#include <algorithm>

using namespace std;
int solution(vector<int> d, int budget) {
    sort(d.begin(),d.end());
    int cnt=0,sum=0;
    for(int i=0;i<d.size();i++){
        sum+=d[i];
        if(sum<=budget){
            cnt++;
        }
        else return cnt;
    }
}