#include <cstdio>
#include <cstdlib>
#include <ctime>

int N,J;
int tmp[40];
int ans[15];
int A[50],B[50],C[50];

void swap(int &a,int &b){
	int x = a;
	a = b;
	b = x;
}

void Multiply11(){
	for(int i=0;i<=N-2;i++){
		B[i] = A[i];
	}
	B[N-1] = 0;

	// reverse A
	// printf("\n");
	for(int i=0,j=N-2;i<j;i++,j--) swap(A[i],A[j]);
	A[N-1] = 0;
	// for(int i=0;i<=N-1;i++) printf("%d",A[i]);
	// printf("\n");

	// reverse B
	for(int i=0,j=N-1;i<j;i++,j--) swap(B[i],B[j]);		
	// for(int i=0;i<=N-1;i++) printf("%d",B[i]);
	// printf("\n");

	int carry = 0;
	int len_c = N-1;
	for(int i=0;i<=N-1;i++){
		C[i] = (A[i] + B[i] + carry) % 2;
		carry = (A[i] + B[i] + carry ) / 2;
	}
	// for(int i=0;i<=N-1;i++) printf("%d",C[i]);
	// printf("\n");
	for(int i=0,j=N-1;i<j;i++,j--) swap(C[i],C[j]);
}


int cc = 0;

void f(int id){
	if(cc == J) return ; 
	if(id == N - 1){
		++cc;
		for(int i=0;i<N-1;i++) A[i] = tmp[i];
		// printf("[%d]:", cc);
		// printf("(11)");
		// printf("("); 
		// for(int i=0;i<N-1;i++) printf("%d",A[i]);
		// printf("\n");

		Multiply11();
		for(int i=0;i<N;i++) printf("%d",C[i]);
		for(int i=2;i<=10;i++) printf(" %d",ans[i]);
		printf("\n");
		return ;
	}

	if(id == N - 2){
		tmp[id] = 1;
		f(id+1);
		return;
	}

	if(id+2 <= N-2){
		tmp[id] = 1;
		tmp[id+1] = 0;
		f(id+2);
		for(int i=id+2;i <= N-3;i++){
			tmp[i] = 0;
			f(i+1);
		}
	}
	
}

int main(){
	ans[2] = 3;
	ans[3] = 2;
	ans[4] = 5;
	ans[5] = 2;
	ans[6] = 7;
	ans[7] = 2;
	ans[8] = 3;
	ans[9] = 2;
	ans[10] = 11;

	freopen("input","r",stdin);
	freopen("output-large","w",stdout);

	int T;
	scanf("%d",&T);
	scanf("%d %d",&N,&J);
	printf("Case #1:\n");

	f(0);
	return 0;
}