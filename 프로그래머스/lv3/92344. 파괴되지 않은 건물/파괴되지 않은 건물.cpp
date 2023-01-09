#include <string>
#include <vector>
#include <iostream>
using namespace std;
int new_map[1010][1010];
int solution(vector<vector<int>> board, vector<vector<int>> skill) {
    int answer = 0;
    int N = board.size();
    int M = board[0].size();
    
    for(auto SK : skill)
    {
        if(SK[0] == 1)
        {
            new_map[SK[1]][SK[2]] -= SK[5];
            new_map[SK[3]+1][SK[4]+1] -= SK[5];
            new_map[SK[1]][SK[4]+1] += SK[5];
            new_map[SK[3]+1][SK[2]] += SK[5];
        }
        else{
            new_map[SK[1]][SK[2]] += SK[5];
            new_map[SK[3]+1][SK[4]+1] += SK[5];
            new_map[SK[1]][SK[4]+1] -= SK[5];
            new_map[SK[3]+1][SK[2]] -= SK[5];
        }
    }
    for(int i=0;i<=M;i++)
    {
        for(int j=1;j<=N;j++)
        {
            new_map[j][i] += new_map[j-1][i];   
        }
    }
    for(int i=0;i<=N;i++)
    {
        for(int j=1;j<=M;j++)
        {
            new_map[i][j] += new_map[i][j-1];   
        }
    }
    for(int i=0;i<N;i++)
    {
        for(int j=0;j<M;j++)
        {
            if(board[i][j] + new_map[i][j] > 0) answer++;
        }
    }
    return answer;
}