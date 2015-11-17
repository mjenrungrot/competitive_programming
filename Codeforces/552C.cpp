#include <cstdio>

int M,W,A[200];
int n_base = 0;

bool f(){
	bool pass1 = true;
	if(W > 2){
		for(int i=0;i<n_base;i++) if(A[i] > 1) pass1 = false;
		if(pass1) return true;
	}


	int carry = 0;
	for(int i=0;i<n_base;i++){
		if(carry) A[i]++, carry = 0;
		if(A[i] == W){ A[i] = 0, carry = 1;}
		if(A[i] == 1 or A[i] == 0) continue;
		
		A[i]++;
		if(A[i] == W){
			A[i] = 0;
			carry = 1;
		}

		if(A[i] > 1) return false;
	}
	return true;
}

int main(){
	// freopen("in","r",stdin);
	scanf("%d %d",&W,&M);

	int tmpM = M;
	while(tmpM){
		A[n_base++] = tmpM % W;
		tmpM /= W;
	}

	int ans = f();
	if(ans) printf("YES\n");
	else printf("NO\n");
	// for(int i=0;i<n_base;i++) printf("A[%d] = %d\n",i,A[i]);

	return 0;
}