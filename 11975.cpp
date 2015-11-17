#include <cstdio>
#include <cstring>

int N,A[100],L;
int v1,v2,v3,v4;

int TT[10][10];
int blank[10][10];

void fill(int n){
	memset(blank,0,sizeof blank);
	for(int i=1;i<=n and i<=N;i++){
		int vv = A[i];
		bool found = false;
		for(int r=1;r<=5 and !found;r++) for(int c=1;c<=5 and !found;c++) if(TT[r][c] == vv){
			blank[r][c] = 1;
			found = true;
		}
	}
}

bool check1(){
	if(blank[1][1] and blank[1][5] and blank[5][1] and blank[5][5]) return true;
	return false;
}
bool check2(){
	if(blank[3][1] and blank[3][2] and blank[3][3] and blank[3][4] and blank[3][5]) return true;
	return false;
}
bool check3(){
	for(int i=1,j=5;i<=5;i++,j--){
		if(!blank[i][i]) return false;
		if(!blank[i][j]) return false;
	}
	return true;
}
bool check4(){
	for(int i=1;i<=5;i++) for(int j=1;j<=5;j++) if(!blank[i][j]) return false;
	return true;
}

int main(){
	// freopen("in","r",stdin);
	int T,test = 0;
	scanf("%d",&T);
	while(T--){
		printf("Case %d:\n",++test);

		scanf("%d %d",&N,&L);
		for(int i=1;i<=N;i++) scanf("%d",&A[i]);
		scanf("%d %d %d %d",&v1,&v2,&v3,&v4);

		int ans = 0;
		while(L--){
			ans = 0;
			for(int i=1;i<=5;i++) for(int j=1;j<=5;j++) scanf("%d",&TT[i][j]);
			fill(35);
			if(check1()) ans += v1;
			fill(40);
			if(check2()) ans += v2;
			fill(45);
			if(check3()) ans += v3;
			fill(N);
			if(check4()) ans += v4;
			printf("%d\n",ans);
		}
		if(T) printf("\n");
	}
	return 0;
}