#include <bits/stdc++.h>
using namespace std;
int n, k, r;
vector<int> arr;
int main()
{
	cin >> n >> k;
	for (int i = 1; i <= n; i++) {
        arr.push_back(i);
	}
    int idx = 0;
    cout<<"<";
    while(1)
    {
        idx = (idx + k - 1) % arr.size();
        cout<<arr[idx];
        arr.erase(arr.begin()+idx);
        if(arr.empty()){
            cout<<">";
            break;
        }
        else cout<<", ";

    }

}