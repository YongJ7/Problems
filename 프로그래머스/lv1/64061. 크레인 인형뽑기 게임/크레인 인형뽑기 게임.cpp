#include <string>
#include <vector>
#include <iostream>

using namespace std;

int solution(vector<vector<int>> board, vector<int> moves) {
    int answer = 0;
    int s[1001]={0};
    int h =0;
    for(int i=0;i<moves.size();i++){
        int n = moves[i]-1;
        for(int j=0;j<board.size();j++){
            if(board[j][n]!=0){
                s[h]=board[j][n];
                board[j][n]=0;
                h++;
                break;
            }
        }
        if(h<2) continue;
        if(s[h-1]==s[h-2]){
            s[h-1]=0;
            s[h-2]=0;
            h-=2;
            answer+=2;
        }
    }
    return answer;
}