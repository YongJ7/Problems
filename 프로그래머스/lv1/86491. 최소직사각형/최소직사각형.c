#include <stdio.h>
#include <stdbool.h>
#include <stdlib.h>

// sizes_rows는 2차원 배열 sizes의 행 길이, sizes_cols는 2차원 배열 sizes의 열 길이입니다.
int solution(int** sizes, size_t sizes_rows, size_t sizes_cols) {
    int answer = 0;
    int w_max = 0, h_max = 0;
    for(int i=0;i<sizes_rows;i++)
    {
        if(sizes[i][0] > sizes[i][1])
        {
            if(sizes[i][0] > w_max) w_max = sizes[i][0];
            if(sizes[i][1] > h_max) h_max = sizes[i][1];
        }
        else
        {
            if(sizes[i][1] > w_max) w_max = sizes[i][1];
            if(sizes[i][0] > h_max) h_max = sizes[i][0];
        }
    }
    answer = w_max*h_max;
    return answer;
}