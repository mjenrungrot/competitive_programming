#include <cstdio>
#include "foo.cc"

int main(){
	vector<int> ss = generatePrime(20);
	for(size_t i=0;i<ss.size();i++){
		printf("%d\n",ss[i]);
	}
 	
 	int x = gcd(2,20);
 	printf("gcd(2,20) = %d\n",x);

 	int y = power(2, 20);
 	printf("2^20 = %d\n",y);
	return 0;
}