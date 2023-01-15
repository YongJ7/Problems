#include <stdio.h>
#include <stdbool.h>
#include <stdlib.h>
int arr[3001];
// nums_len은 배열 nums의 길이입니다.
int solution(int nums[], size_t nums_len) {
    int answer = 0;
    
    for(int i=0;i<=3000;i++) arr[i]=i;
    for(int i=2;i*i<=3000;i++)
    {
        if(arr[i]==0) continue;
        for(int j=i*2;j<=3000;j+=i)
        {
            arr[j]=0;
        }
    }
    for(int i=0;i<nums_len-2;i++)
    {
        for(int j=i+1;j<nums_len-1;j++)
        {
            for(int k=j+1;k<nums_len;k++)
            {
                int sum = nums[i]+nums[j]+nums[k];
                if(arr[sum]!=0) answer++;
            }
        }
    }
    return answer;
}