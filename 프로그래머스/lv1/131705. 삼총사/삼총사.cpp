#include <string>
#include <vector>

using namespace std;

int solution(vector<int> number) {
    int answer = 0;
    int l = number.size();
    for(int i=0;i<l-2;i++)
    {
        int sum = number[i];
        for(int j=i+1;j<l-1;j++)
        {
            sum += number[j];
            for(int k=j+1;k<l;k++)
            {
                if(sum + number[k]==0) answer++;
            }
            sum -= number[j];
        }
    }
    return answer;
}