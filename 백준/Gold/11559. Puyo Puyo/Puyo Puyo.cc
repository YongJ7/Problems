#include <iostream>
#include <vector>
#include <algorithm>
#include <stack>
using namespace std; 
#define ROW 12
#define COL 6
#define SIDE 4
#pragma warning(disable:4996)
char map[ROW][COL] = { 0 };
int side_arr[SIDE][2] = { { -1,0 },{ 1,0 },{ 0,-1 },{ 0,1 } };
 
// 뿌요뿌요를 터트린다. 하나라도 터트리면 1 리턴 아니면 0리턴
int is_pop_puyo() {
    int is_pop = 0;
    int visited[ROW][COL] = { 0 };
    vector<pair<int, int>> pop_puyo_vec;
    for (int row = 0; row < ROW; row++){
        for (int col = 0; col < COL; col++) {
            if (visited[row][col]) continue;
            else visited[row][col] = 1;
 
            if (map[row][col] == '.') continue;
 
            // 벡터은 현재 row, col 과 동일한 녀석들을 넣고  
            // 스택은 dfs 를 하기 위한 용도
            vector<pair<int, int>> dfs_vec;
            stack<pair<int,int>> dfs_stack;
            dfs_stack.push({ row , col});
            dfs_vec.push_back({ row , col });
            while (!dfs_stack.empty()) {
                pair<int, int> this_node = dfs_stack.top(); dfs_stack.pop();
                // 사이드 4개 검사 
                for (int side_idx = 0; side_idx < SIDE; side_idx++) {
                    int new_row = this_node.first + side_arr[side_idx][0];
                    int new_col = this_node.second + side_arr[side_idx][1];
                    
                    if (new_row < 0 || new_row >= ROW) continue;
                    if (new_col < 0 || new_col >= COL) continue;
                    if (visited[new_row][new_col]) continue;
 
                    if (map[new_row][new_col] == map[row][col]) {
                        dfs_vec.push_back({ new_row , new_col });
                        dfs_stack.push({ new_row , new_col });
                        visited[new_row][new_col] = 1;
                    }
                }
            }
             
            if (dfs_vec.size() >= 4) {
                for (auto dfs_each : dfs_vec) 
                    pop_puyo_vec.push_back(dfs_each);
                is_pop = 1;
            }
        }
    }
     
    for (auto pop_puyo : pop_puyo_vec) 
        map[pop_puyo.first][pop_puyo.second] = '.';
 
    return is_pop;
}
 
// 터트리고 나서 푸요푸요를 떨어뜨린다.
void puyo_drop() {
    for (int col = 0; col < COL; col++) {
        int row_top = ROW - 1;
        for (int row = ROW - 1; row >= 0; row--) {
            if (map[row][col] == '.') continue;
            if (row_top != row){
                map[row_top][col] = map[row][col];
                map[row][col] = '.';
            }
            row_top--;
        }
    }
}
 
int main() {
    for (int row = 0; row < ROW; row++)
        for (int col = 0; col < COL; col++)
            scanf(" %c", &map[row][col]);
 
    int answer = 0;
    while (is_pop_puyo()) {
        puyo_drop(); answer++;
    }
 
    printf("%d", answer);
    return 0;
}