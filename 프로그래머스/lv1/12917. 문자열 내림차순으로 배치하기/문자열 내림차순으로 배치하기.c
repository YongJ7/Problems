#include <stdio.h>
#include <stdbool.h>
#include <stdlib.h>
#include <string.h>

int compare(const void *first,const void *second)
{
    return -(strcmp((char*)first,(char*)second));
}
// 파라미터로 주어지는 문자열은 const로 주어집니다. 변경하려면 문자열을 복사해서 사용하세요.
char* solution(const char* s) {
    // return 값은 malloc 등 동적 할당을 사용해주세요. 할당 길이는 상황에 맞게 변경해주세요.
    char* answer = (char*)malloc(1e9);
    int l =strlen(s);
    char arr[l];
    strcpy(arr,s);
    qsort(arr,l,sizeof(char),compare);
    strcpy(answer,arr);
    return answer;
}