#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;
int N;
vector<int> arr;

int main()
{
    cin.sync_with_stdio(0);
    cin.tie(0);
    //freopen("input.txt","r",stdin);
    cin >> N;
    arr.push_back(0);
    
    for (int i = 0; i < N; i++)
    {
        int num;
        cin >> num;
        if (num > arr.back())
        {
            arr.push_back(num);
        }
        else
        {
            int idx = lower_bound(arr.begin(), arr.end(), num) - arr.begin();
            arr[idx] = num;
        }
    }
    cout << N - arr.size() + 1<<'\n';
}
