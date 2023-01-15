#include <iostream>
using namespace std;

int main() {
	int N,ma=-1000001,mi=1000001;
	cin>>N;
	for(int i=0;i<N;i++){
		int a;
		cin>>a;
		if(a>ma) ma=a;
		if(a<mi) mi=a; 
	}
	cout<<mi<<" "<<ma;
	return 0;
}