#include <cstdio>
#include <cstring>
#include <algorithm>
#include <cstdlib>
using namespace std;

struct matrix{
	int A[30][30],R,C;
}A,B,C;

matrix multi(matrix x, matrix y){
	matrix z;
	z.R = x.R;
	z.C = y.C;
	for(int i=1;i<=z.R;i++) for(int j=1;j<=z.C;j++) z.A[i][j] = 0;
	for(int i=1;i<=z.R;i++) for(int j=1;j<=z.C;j++) for(int k=1;k<=x.C;k++){
		z.A[i][j] += (x.A[i][k] * y.A[k][j]);
	}
	return z;
}
int N;
char str[1000];
char tmp[100];

int main(){

	freopen("Matrix-multiplication_InputForSubmission_1.txt","r",stdin);
	freopen("Matrix-multiplication_InputForSubmission_1.out","w",stdout);
	int now_row = 0,now_col = 0;
	while(fgets(str,sizeof str,stdin)){
		now_row++;
		now_col = 0;

		char *p = strtok(str," \n");
		int cc = 0;
		while(p != NULL){
			if(strcmp(p,"|") == 0){
				cc++;
				if(cc == 3) now_col = 0;
			}else{
				if(cc == 1 and strcmp(p,"|") != 0 and str[0] == '|'){
					now_col++;
					A.R = now_row;
					A.C = now_col;
					A.A[now_row][now_col] = atoi(p);
				}else if(cc == 1 and strcmp(p,"|") != 0 and str[0] == ' '){
					now_col++;
					B.R = now_row;
					B.C = now_col;
					B.A[now_row][now_col] = atoi(p);

				}else if(cc == 3 and strcmp(p,"|") != 0){
					now_col++;
					B.R = now_row;
					B.C = now_col;
					B.A[now_row][now_col] = atoi(p);
				}
			}
			p = strtok(NULL," \n");
		}
	}
	// for(int i=1;i<=A.R;i++){
	// 	for(int j=1;j<=A.C;j++) printf("[%d]",A.A[i][j]);
	// 	printf("\n");
	// }
	// for(int i=1;i<=B.R;i++){
	// 	for(int j=1;j<=B.C;j++) printf("[%d]",B.A[i][j]);
	// 	printf("\n");
	// }
	C = multi(A,B);
	int maxlen = 0;
	for(int i=1;i<=C.R;i++){
		for(int j=1;j<=C.C;j++){
			sprintf(tmp,"%d",C.A[i][j]);
			maxlen = max(maxlen,(int)strlen(tmp));
			// printf("[%d = %d]",C.A[i][j],(int)strlen(tmp));
		}
		// printf("\n");
	}
	for(int i=1;i<=C.R;i++){
		printf("|");
		for(int j=1;j<=C.C;j++){
			printf(" ");
			sprintf(tmp,"%d",C.A[i][j]);
			
			int now_len = strlen(tmp);
			for(int k=now_len+1;k<=maxlen;k++) printf(" ");
			printf("%d",C.A[i][j]);
		}
		printf(" |\n");
	}
	return 0;
}

/*
|  -447  -198 |
| -1071  -653 |
|   -39   -29 |

|  -67 |
| -103 |


*/