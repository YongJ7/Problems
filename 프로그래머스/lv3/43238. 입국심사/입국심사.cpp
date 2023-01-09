#include <string>
#include <vector>
#include <algorithm>

using namespace std;

long long solution(int n, vector<int> times)
{
    int l = times.size();
    sort(times.begin(),times.end());
    
    long long start = (long long)times[0];
    long long end = (long long)times[l-1] * n;
    long long mid;
    while(start < end)
    {
        mid = (start+end)/2;
        long long cnt = 0;
        
        for(int i=0;i<l;i++) cnt+=mid/times[i];
        if(cnt>=n) end = mid;
        else start = mid+1;
    }
    
    return start;
}