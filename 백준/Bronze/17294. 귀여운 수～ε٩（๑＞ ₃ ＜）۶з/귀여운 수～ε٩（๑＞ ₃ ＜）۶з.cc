#include <iostream>
using namespace std;

int map[20];

int main(){
	long long k;
	cin >> k;
	int t = 0;
	int n=0;
	
	while(k>0){
		t = k%10;
		k = k/10;
		map[n] = t;
		n++;
	}
	
	int a = map[0]-map[1];
	
	for(int i=1; i<n; i++){
		if(map[i-1]-map[i] != a){
			cout << "흥칫뿡!! <(￣ ﹌ ￣)>";	
			return 0;
		}
	}
	
	cout << "◝(⑅•ᴗ•⑅)◜..°♡ 뀌요미!!";
		
	return 0;
}