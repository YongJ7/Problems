    #include <iostream>
    #include <vector>
    #include <algorithm>
    using namespace std;
    vector<int> arr;
    int a,b,n;
    int sum = 2e9;
    int main()
    {
        cin.tie(0);
        cin.sync_with_stdio(0);
        //freopen("input.txt","r",stdin);
        cin>>n;
        for(int i=0;i<n;i++)
        {
            int t; cin>>t;
            arr.push_back(t);
        }
        int s = 0;
        int e = n-1;

        while(s<e){
            int now = arr[s]+arr[e];
            if(sum>abs(now)){
                sum = abs(now);
                a = arr[s];
                b = arr[e];
            }
            if(now>0){
                e--;
            }
            if(now<0){
                s++;
            }
            if(now==0){
                break;
            }
        }
        cout<<a<<" "<<b<<'\n';
    }
