#include <stdio.h>
#include <stdbool.h>
#include <stdlib.h>
#include <string.h>

char* solution(int n) {
    // 리턴할 값은 메모리를 동적 할당해주세요.
    char* answer = (char*)malloc(n*sizeof(char)*10);
    strcpy(answer,"");
    char *s = "수";
    char *b = "박";
    for(int i=0;i<n;i++){
        if(i%2==0){
            strcat(answer,s);
        }
        else{
            strcat(answer,b);
        }
    }
    return answer;
}