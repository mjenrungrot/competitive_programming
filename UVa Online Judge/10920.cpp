#include <cstdio>
#include <algorithm>
using namespace std;

long long sq[50005];

int main(){
	// freopen("in","r",stdin);
	for(int i=1;i<=50000;i++) sq[i] = (long long)(2*i-1) * (long long)(2*i-1);

	int sz;
	long long p;
	while(scanf("%d %lld",&sz,&p) == 2){
		if(sz == 0LL) break;
		int level = lower_bound(sq,sq+50000,p) - sq;
		long long val_max = sq[level];
		long long length = 2*level - 1;
		int dify,difx;
		if(p == val_max){
			dify = level - 1;
			difx = level - 1;
		}else if(p >= val_max - length + 1LL){
			dify = p - (val_max - length/2LL);
			difx = level - 1;
		}else if(p >= val_max - length*2LL + 2LL){
			dify = -level + 1;
			difx = p - (val_max - length + 1LL - length/2LL);
		}else if(p >= val_max - length*3LL + 3LL){
			difx = -level + 1;
			dify = (val_max - length*2LL + 2LL - length/2LL) - p;
		}else{
			difx = (val_max - length*3LL + 3LL - length/2LL) - p;
			dify = level - 1;
		}
		printf("Line = %d, column = %d.\n",(sz+1)/2 + dify, (sz+1)/2 + difx);
	}
	return 0;
}