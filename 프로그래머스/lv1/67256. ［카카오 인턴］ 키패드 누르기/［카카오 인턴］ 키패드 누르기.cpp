#include <bits/stdc++.h>
using namespace std;

pair<int,int> location(int a)
{
    if(a==0) return {4,2};
    if(a>=1&&a<=3) return {1,a};
    if(a>=4&&a<=6) return {2,a-3};
    if(a>=7&&a<=9) return {3,a-6};
}

int distance(int ny,int nx,int ty,int tx)
{
    return abs(ny-ty)+abs(nx-tx);
}

string solution(vector<int> numbers, string hand) 
{
    string ans;
    int ly=4,lx=1;
    int ry=4,rx=3;
    
    for(int t: numbers)
    {
        char h = '@';
        auto [y, x] = location(t);
        if(x==1) h = 'L', ly=y,lx=x;
        else if(x==3) h ='R', ry=y,rx=x;
        else {
            int l=distance(ly,lx,y,x);
            int r=distance(ry,rx,y,x);
            if(l<r||hand=="left"&&l==r) h='L',ly=y,lx=x;
            else h='R',ry=y,rx=x;
        }
        ans.push_back(h);
    }
    
    return ans;
}