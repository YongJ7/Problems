#include <string>
#include <vector>

using namespace std;

int diff = -1;
void dfs(vector<int>& ryan, vector<int>& info, vector<int>& ans, int idx, int N){
    if(idx== 10){
        ryan[idx] = N;
        int r = 0, p = 0;
        for(int i = 0; i <= 10; ++i){
            if(!ryan[i] && !info[i]) continue;
            if(ryan[i] > info[i]){
                r += 10 - i;
            }else{
                p += 10 - i;
            }
        }
        if(r > p && (diff == -1 || diff <= r - p)){
            bool f = true;
            if(diff != -1 && diff == r - p){
                for(int i = 10; i >= 0; --i){
                    if(ans[i] == ryan[i]) continue;
                    if(ans[i] > ryan[i]){
                        f = false;
                    }
                    break;
                }
            }
            if(f){
                diff = r - p;
                for(int i = 0; i <= 10; ++i) ans[i] = ryan[i];
            }
        }
        return;
    }
    for(int i = N; i >= 0; --i){
        ryan[idx] = i;
        dfs(ryan, info, ans, idx + 1, N - i);
    }
}
vector<int> solution(int n, vector<int> info) {
    vector<int> ryan, ans;
    ryan.resize(11, 0);
    ans.resize(11, 0);
    dfs(ryan, info, ans, 0, n);
    if(diff == -1){
        ans.resize(1);
        ans[0] = -1;
    }
    return ans;
}