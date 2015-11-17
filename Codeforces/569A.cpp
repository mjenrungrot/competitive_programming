#include <iostream>
using namespace std;
long long T,S,q;

int main(){
	cin >> T >> S >> q;
	int ans = 0;
	while (S < T){
		S = q * S;
		ans++;
	}
	cout << ans;
	return 0;
}