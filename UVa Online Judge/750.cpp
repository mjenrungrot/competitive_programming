#include <cstdio>
#include <algorithm>
using namespace std;

int test,r,c,B[10];
const int OK = (1<<9) - 2;

void f(int now,int L,int M,int R){
	if(now == 9){
		printf("%2d     ",++test);
		for(int i=1;i<=8;i++) printf(" %d",B[i]);
		printf("\n");
		return ;
	}
	int pos = OK & (~(L|M|R));


	if(now == c){
		if((1<<r)&pos){
			B[now] = r;
			f(now+1,(L|(1<<r))<<1,(M|(1<<r)),(R|(1<<r))>>1);
		}
		return;
	}  

	for(int i=1;i<=8;i++){
		if((1<<i)&pos){
			B[now] = i;
			f(now+1,(L|(1<<i))<<1,(M|(1<<i)),(R|(1<<i))>>1);
		}
	}
}

int main(){
	// freopen("in","r",stdin);
	// freopen("out","w",stdout);
	int T;
	scanf("%d",&T);
	while(T--){
		scanf("%d %d",&r,&c);
		test = 0;
		printf("SOLN       COLUMN\n");
		printf(" #      1 2 3 4 5 6 7 8\n\n");

		f(1,0,0,0);
		if(T) printf("\n");
	}
	return 0;
}