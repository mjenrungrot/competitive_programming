#include <cstdio>
#include <cstring>
#include <algorithm>
using namespace std;

int pass[1005][1005];

int A,B,N,minlen,len;
bool found;
int xx;
int ans[1000005];

void f(int aa,int bb){
	if(bb == N){
		found = true;
		minlen = min(minlen,len);
		return ;
	}
	if(len == minlen) return ;

	if(pass[aa][bb]) return ;
	pass[aa][bb] = true;
	// if(xx) printf("[%d] %d %d\n",len,aa,bb);

	len++;
	ans[len] = 1;
	f(A,bb);
	if(xx and found) return ;
	len--;

	len++;
	ans[len] = 2;
	f(aa,B);
	if(xx and found) return ;
	len--;

	if(aa and bb < B){
		int val = B-bb;
		val = min(val, aa);
		len++;
		ans[len] = 3;
		f(aa-val,bb+val);
		if(xx and found) return ;
		len--;
	}
	if(bb and aa < A){
		int val = A-aa;
		val = min(val, bb);
		len++;
		ans[len] = 4;
		f(aa+val,bb-val);
		if(xx and found) return ;
		len--;
	}
	if(aa){
		len++;
		ans[len] = 5;
		f(0,bb);
		if(xx and found) return ;
		len--;
	}
	if(bb){
		len++;
		ans[len] = 6;
		f(aa,0);
		if(xx and found) return ;
		len--;
	}

	pass[aa][bb] = false;
}

int main(){
	// freopen("in","r",stdin);
	while(scanf("%d %d %d",&A,&B,&N) == 3){
		found = false;
		len = 0; minlen = 1e9;
		memset(pass,0,sizeof pass);
		memset(ans,0,sizeof ans);

		xx = 0;
		f(0,0);
		xx = 1, found = false;
		f(0,0);
		// printf("minlen = %d\n",minlen);

		for(int i=1;i<=minlen;i++){
			if(ans[i] == 1) printf("fill A\n");
			else if(ans[i] == 2) printf("fill B\n");
			else if(ans[i] == 3) printf("pour A B\n");
			else if(ans[i] == 4) printf("pour B A\n");
			else if(ans[i] == 5) printf("empty A\n");
			else if(ans[i] == 6) printf("empty B\n");
			else printf("a[%d] = %d\n",i,ans[i]);
		}
		printf("success\n");
	}
	return 0;
}