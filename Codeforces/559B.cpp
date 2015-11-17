#include <iostream>
#include <string>
#include <cstdio>
using namespace std;

string f(string xx){
	if(xx.length() % 2) return xx;
	string aa = f(xx.substr(0,xx.length()/2));
	string bb = f(xx.substr(xx.length()/2,xx.length()/2));
	return aa < bb ? aa + bb : bb + aa;
}

int main(){
	// freopen("in","r",stdin);
	string A,B;
	cin >> A >> B;
	printf("%s\n", f(A) == f(B) ? "YES" : "NO");
	return 0;
}