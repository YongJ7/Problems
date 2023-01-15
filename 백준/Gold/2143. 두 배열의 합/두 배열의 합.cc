#include <bits/stdc++.h>
using namespace std;
int A[1001];
int B[1001];
vector<int> as,bs;
int main()
{
   int T,n,M;
   long long int cnt=0;
   cin>>T>>n;
   for(int i=0;i<n;i++) cin>>A[i];
   cin>>M;
   for(int i=0;i<M;i++) cin>>B[i];

   int sum=0;
   for(int i=0;i<n;i++){
       sum=A[i];
       as.push_back(sum);
       for(int j=i+1;j<n;j++){
           sum+=A[j];
           as.push_back(sum);
       }
   }

   for(int i=0;i<M;i++){
       sum=B[i];
       bs.push_back(sum);
       for(int j=i+1;j<M;j++){
           sum+=B[j];
           bs.push_back(sum);
       }
   }

   sort(as.begin(),as.end());
   sort(bs.begin(),bs.end());

   for(int i=0;i<as.size();i++){
       int want = T-as[i];
       int low=bs.size();
       int high=bs.size();
       int s = 0;
       int e = bs.size()-1;
       while(s<=e){
           int m=(s+e)/2;
           if (bs[m] >= want){
               low = m;
               e = m-1;
           } else {
               s = m+1;
           }
       }
       s=0;
       e=bs.size()-1;
       while(s<=e){
           int m=(s+e)/2;
           if (bs[m] > want){
               high = m;
               e = m-1;
           } else {
               s = m+1;
           }
       }
       cnt+=(high-low);
   }
   cout<<cnt;
   return 0;
}