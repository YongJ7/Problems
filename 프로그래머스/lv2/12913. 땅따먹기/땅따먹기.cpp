#include <iostream>
#include <vector>
using namespace std;

int solution(vector<vector<int>> land)
{
    int answer = 0;
    int n = land.size();
    int sum[100000][4]={land[0][0],land[0][1],land[0][2],land[0][3]};
    for(int y=1;y<n;y++){
        for(int x =0;x<4;x++){
            for(int t=0;t<4;t++){
                if(x==t) continue;
                int ny = y-1;
                if(sum[y][x]<sum[ny][t]+land[y][x]){
                    sum[y][x]=sum[ny][t]+land[y][x];
                }
                    
            }
        }
    }
    for(int i=0;i<4;i++){
        if(answer<sum[n-1][i]) answer=sum[n-1][i];
    }
    

    return answer;
}