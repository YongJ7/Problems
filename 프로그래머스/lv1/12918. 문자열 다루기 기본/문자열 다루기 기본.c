#include <stdio.h>
#include <stdbool.h>
#include <stdlib.h>
#include <string.h>

// 파라미터로 주어지는 문자열은 const로 주어집니다. 변경하려면 문자열을 복사해서 사용하세요.
bool solution(const char* s) {
    bool answer = true;
    int l = strlen(s);
    if(l==4||l==6){
        for(int i=0;i<l;i++){
            if(s[i]<'0'||s[i]>'9'){
                answer = false;
                break;
            }
        }
    }
    else answer = false;
    
    return answer;
}