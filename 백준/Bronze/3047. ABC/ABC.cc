#include <bits/stdc++.h>
using namespace std;
int a,b,c;
int A,B,C;
string s;
int main()
{
	cin>>a>>b>>c;
	cin>>s;
	A=min(a,min(b,c));
	C=max(a,max(b,c));
	B=a+b+c-A-C;
	for(int i=0;i<3;i++){
		if(s[i]=='A') cout<<A<<" ";
		if(s[i]=='B') cout<<B<<" ";
		if(s[i]=='C') cout<<C<<" ";
	}
}