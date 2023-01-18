#include <stdio.h>
#include <stdbool.h>
#include <stdlib.h>
#include <string.h>

char* solution(int a, int b) {
    // 리턴할 값은 메모리를 동적 할당해주세요.
    char* answer = (char*)malloc(4*sizeof(char));
    int sum =0;
    char *arr[7]={"FRI","SAT","SUN","MON","TUE","WED","THU"};
    int d[12]={31,29,31,30,31,30,31,31,30,31,30,31};
    for(int i=0;i<a-1;i++){
        sum+=d[i];
    }
    sum+=b-1;
    strcpy(answer,arr[sum%7]);
    return answer;
}