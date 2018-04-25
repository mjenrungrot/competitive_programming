#include <cstdio>
#include <cstring>

int R, C;
int Hcut, Vcut;
char A[105][105];
int dp[105][105];
int amountPerCut;

int rowCut[105], colCut[105];

int sum(int startR, int startC, int endR, int endC){
	return dp[endR][endC] - dp[startR-1][endC] - dp[endR][startC-1] + dp[startR-1][startC-1];
}

int sumrow(int startR, int endR){
	return sum(startR, 1, endR, C);
}

void f(int prevrow, int idx){
	if()

	for(int row=prevrow; row<=R; row++){
		if(sumrow(prevrow, row) == (amountPerCut * (Vcut + 1))){
			rowCut[idx] = row;
			f(row+1, idx+1);
		}
	}
}

void runTest(){
	scanf("%d %d",&R, &C, &Hcut, &Vcut);
	
	for(int i=1;i<=R;i++) scanf("%s", &A[i][1]);

	int nChips = 0;
	for(int i=1;i<=R;i++) for(int j=1;j<=C;j++) nChips += (A[i][j] == '@');

	memset(dp, 0, sizeof dp);
	for(int i=1;i<=R;i++) for(int j=1;j<=C;j++){
		dp[i][j] = dp[i-1][j] + dp[i][j-1] - dp[i-1][j-1] + (A[i][j] == '@');
	}

	amountPerCut = ((Hcut + 1) * (Vcut + 1));
	if(nChips % ((Hcut + 1) * (Vcut + 1)) != 0){
		printf("IMPOSSIBLE\n");
		return ;
	}

	f(1,1);
}

int main(){
	int T;
	scanf("%d",&T);
	for(int i=1;i<=T;i++){
		printf("Case #%d: ", i);
		runTest();
	}
	return 0;
}