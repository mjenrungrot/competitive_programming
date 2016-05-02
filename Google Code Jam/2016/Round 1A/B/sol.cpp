#include <cstdio>
#include <deque>
#include <cstring>
#include <cassert>
using namespace std;

const int INF = 1e9;
int N;
int startD[105];
int endD[105];
deque <int> D[105];
bool usedR[105], usedC[105],used[105];

int B[60][60];

void f(int r1,int c1,int r2,int c2){
	if(r2-r1 <= 3) return;
	// printf("[%d-%d] [%d-%d]\n",r1,r2,c1,c2);
	// for(int k=1;k<=2*N-1;k++){
	// 	printf("[k = %d] start %d %d",k,startD[k], endD[k]);
	// 	if(startD[k] != endD[k]) for(int j=startD[k];j<endD[k];j++) printf("[%d]",D[k][j]);
	// 	printf("\n");
	// }
	// printf("\n\n");

	if(r1 == r2 or c1 == c2){
		// printf("go at %d %d\n",r1,r2);
		for(int i=1;i<=2*N-1;i++){
			if(startD[i] != endD[i]){
				B[r1][c1] = D[i][startD[i]];
				break;
			}
		}
		return ;
	}
	int minval = INF;
	int maxval = -INF;
	for(int i=1;i<=2*N-1;i++) for(int j=startD[i];j<endD[i];j++){
		minval = min(minval, D[i][j]);
		maxval = max(maxval, D[i][j]);
	}

	int ccmin = 0;
	int ccmax = 0;
	for(int i=1;i<=2*N-1;i++) for(int j=startD[i];j<endD[i];j++){
		if(D[i][j] == minval) ccmin++;
		if(D[i][j] == maxval) ccmax++;
	}

	// printf("ccmin = %d %d\n",ccmin,ccmax);

	if(ccmin == 2){
		B[r1][c1] = minval;
		int id1 = 0, id2 = 0;
		for(int i=1;i<=2*N-1;i++){
			if(startD[i] >=endD[i]) continue;
			if(D[i][startD[i]] == minval){
     			if(id1 == 0) id1 = i;
     			else id2 = i;
			}
		}

		bool checkLessThan = true;
		// assert(startD[id1] == startD[id2]);
		for(int i=startD[id1];i<endD[id1];i++){
			if(D[id1][i] > D[id2][i]){
				checkLessThan = false;
				break;
			}
		}

		if(checkLessThan){
			for(int i=c1,j=startD[id1];i<=c2;i++,j++){
				startD[id1]++;
				B[r1][i] = D[id1][j];
			}
			for(int i=r1,j=startD[id2];i<=r2;i++,j++){
				startD[id2]++;
				B[i][c1] = D[id2][j];
			}
		}else{
			for(int i=c1,j=startD[id2];i<=c2;i++,j++){
				startD[id2]++;
				B[r1][i] = D[id2][j];
			}
			for(int i=r1,j=startD[id1];i<=r2;i++,j++){
				startD[id1]++;
				B[i][c1] = D[id1][j];
			}
		}
		for(int k=1;k<=2*N-1;k++){
			if(startD[k] < endD[k]) startD[k]++;
		}
		f(r1+1,c1+1,r2,c2);
	}else if(ccmax == 2){
		B[r2][c2] = maxval;
		int id1 = 0, id2 = 0;
		for(int i=1;i<=2*N-1;i++){
			if(endD[i]-1 < 0) continue;
			if(startD[i] >=endD[i]) continue;
			// printf("end[%d] = %d\n",i,endD[i]);
			if(D[i][endD[i]-1] == maxval){
     			if(id1 == 0) id1 = i;
     			else id2 = i;
			}
		}
		assert(id1 != 0);
		assert(id2 != 0);
		assert(id1 != id2);
		// printf("id1 = %d %d\n",id1,id2);

		/*
		13	  14	15
		15	  17	18
		20	  23	24
		*/
		bool checkMoreThan = true;
		// // printf("")
		// printf("N = test %d\n",N);
		// assert(endD[id1] == endD[id2]);
		for(int i=endD[id1]-1;i>=startD[id1];i--){
			if(D[id1][i] < D[id2][i]){
				checkMoreThan = false;
				break;
			}
		}

		if(checkMoreThan){
			for(int i=c2,j=endD[id1]-1;i>=c1;i--,j--){
				endD[id1]--;
				B[r2][i] = D[id1][j];
			}
			for(int i=r2,j=endD[id2]-1;i>=r1;i--,j--){
				endD[id2]--;
				B[i][c2] = D[id2][j];
			}
		}else{
			for(int i=c2,j=endD[id2]-1;i>=c1;i--,j--){
				// printf("if i == 14 [%d]",id2==14);
				B[r2][i] = D[id2][j];
				endD[id2]--;
				// printf("endD[14] = %d\n",endD[14]);
			}
			for(int i=r2,j=endD[id1]-1;i>=r1;i--,j--){
				B[i][c2] = D[id1][j];
				endD[id1]--;
			}
		}

		for(int k=1;k<=2*N-1;k++){
			if(startD[k] < endD[k]) endD[k]--;
			// printf("[%d]: %d - %d\n",k,startD[k],endD[k]);
		}
		// printf("%d %d %d %d\n",r1,c1,r2,c2);
		f(r1,c1,r2-1,c2-1);
	}else{
		assert(false);
	}
}

void run(){
	scanf("%d",&N);
	for(int i=1;i<=2*N-1;i++){
		D[i].clear();
		startD[i] = 0;
		endD[i] = N;
	}
	for(int i=1;i<=2*N-1;i++) for(int j=1;j<=N;j++){
		int xx;
		scanf("%d",&xx);
		D[i].push_back(xx);
	}
	// printf("hello\n");
	f(1,1,N,N);

	for(int i=1;i<=N;i++){
		for(int j=1;j<=N;j++) printf("%d ",B[i][j]);
		printf("\n");
	}

	memset(usedR, 0, sizeof usedR);
	memset(usedC, 0, sizeof usedC);
	memset(used, 0, sizeof used);

	// row
	for(int i=1;i<=N;i++){
		for(int j=1;j<=2*N-1;j++){
			if(used[j]) continue;

			bool check = true;
			for(int k=1;k<=N;k++) if(B[i][k] != D[j][k-1]){
				check = false;
				break;
			}
			if(not check) continue;
			// printf("matchR %d with %d\n",i,j);

			usedR[i] = true;
			used[j] = true;
			break;
		}
	}

	// column
	for(int i=1;i<=N;i++){
		for(int j=1;j<=2*N-1;j++){
			if(used[j]) continue;

			bool check = true;
			for(int k=1;k<=N;k++) if(B[k][i] != D[j][k-1]){
				check = false;
				break;
			}
			if(not check) continue;

			// printf("match %d with %d\n",i,j);
			usedC[i] = true;
			used[j] = true;
			break;
		}
	}

	for(int i=1;i<=N;i++){
		// printf("usedR[%d] = %d\n",i,usedR[i]);
		if(usedR[i] == 0){
			for(int j=1;j<=N;j++) printf(" %d",B[i][j]);
			return;
		}
	}
	for(int i=1;i<=N;i++){
		// printf("usedC[%d] = %d\n",i,usedC[i]);
		if(usedC[i] == 0){
			for(int j=1;j<=N;j++) printf(" %d",B[j][i]);
			break;
		}
	}
}

int main(){
	freopen("in","r",stdin);
	// freopen("B-small-attempt1.in","r",stdin);
	// freopen("B-small-attempt1.out","w",stdout);
	int T;
	scanf("%d",&T);
	for(int i=1;i<=T;i++){
		// printf("Case #%d:",i);
		run();
		// printf("\n");
	}
	return 0;
}