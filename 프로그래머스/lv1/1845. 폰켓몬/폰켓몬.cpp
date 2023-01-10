#include <vector>
#include <algorithm>
using namespace std;

int solution(vector<int> nums)
{
    int l =nums.size();
    sort(nums.begin(),nums.end());
    nums.erase(unique(nums.begin(),nums.end()),nums.end());
    if(nums.size()>=l/2) return l/2;
    return nums.size();
}