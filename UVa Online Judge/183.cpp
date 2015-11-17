#include <cstdio>
#include <cstring>

int R,C,A[300][300],qs[300][300];
char str[50000],tmp[50000],tt[5];
int univ_id;

int ask(int r1,int r2,int c1,int c2){
	return qs[r2][c2] - qs[r1-1][c2] - qs[r2][c1-1] + qs[r1-1][c1-1];
}

void f(int R,int C,int r1,int r2,int c1,int c2){
	if(str[univ_id++] == 'D'){
		if(R == 1 or C == 1){
			if(R == 1){
				f(R,(C+1)/2,r1,r2,c1,c2-C/2);
				f(R,C-(C+1)/2,r1,r2,c1+(C+1)/2,c2);
			}else{
				f((R+1)/2,C,r1,r2-R/2,c1,c2);
				f(R-(R+1)/2,C,r1+(R+1)/2,r2,c1,c2);
			}
		}else{
			f((R+1)/2,(C+1)/2,r1,r2-R/2,c1,c2-C/2);
			f((R+1)/2,C-(C+1)/2,r1,r2-R/2,c1+(C+1)/2,c2);
			f(R-(R+1)/2,(C+1)/2,r1+(R+1)/2,r2,c1,c2-C/2);
			f(R-(R+1)/2,C-(C+1)/2,r1+(R+1)/2,r2,c1+(C+1)/2,c2);
		}
	}else{
		for(int i=r1;i<=r2;i++) for(int j=c1;j<=c2;j++) A[i][j] = str[univ_id-1]-'0';
	}
}

void g(int R,int C,int r1,int r2,int c1,int c2){
	if(R == 0 or C == 0) return ;

	if(ask(r1,r2,c1,c2) == R*C){
		printf("1");
		univ_id++;
		if(univ_id%50 == 0) printf("\n");
		return ;
	}
	if(ask(r1,r2,c1,c2) == 0){
		printf("0");
		univ_id++;
		if(univ_id%50 == 0) printf("\n");
		return ;
	}

	printf("D");
	univ_id++;
	if(univ_id%50 == 0) printf("\n");	
	if(R == 1 or C == 1){
		if(R == 1){
			g(R,(C+1)/2,r1,r2,c1,c2-C/2);
			g(R,C-(C+1)/2,r1,r2,c1+(C+1)/2,c2);
		}else{
			g((R+1)/2,C,r1,r2-R/2,c1,c2);
			g(R-(R+1)/2,C,r1+(R+1)/2,r2,c1,c2);
		}
	}else{
		g((R+1)/2,(C+1)/2,r1,r2-R/2,c1,c2-C/2);
		g((R+1)/2,C-(C+1)/2,r1,r2-R/2,c1+(C+1)/2,c2);
		g(R-(R+1)/2,(C+1)/2,r1+(R+1)/2,r2,c1,c2-C/2);
		g(R-(R+1)/2,C-(C+1)/2,r1+(R+1)/2,r2,c1+(C+1)/2,c2);
	}
}

void getstr(){
	memset(str,0,sizeof str);
	while(scanf("%s",tmp) == 1){	
		if(strlen(tmp) == 1 and (tmp[0] == '#' or tmp[0] == 'B' or tmp[0] == 'D')){
			strcpy(tt,tmp);
			break;
		}
		strcat(str,tmp);
	}
}

int main(){
	// freopen("in","r",stdin);
	// freopen("out","w",stdout);
	scanf("%s",tt);
	while(scanf("%d %d",&R,&C) == 2){
		if(tt[0] == '#') break;
		memset(qs,0,sizeof qs);
		memset(A,0,sizeof A);
		char tmp_tt = tt[0];

		getstr();
		if(tmp_tt == 'D'){
			univ_id = 0;
			f(R,C,1,R,1,C);
			printf("B%4d%4d\n",R,C);

			univ_id = 0;
			for(int i=1;i<=R;i++) for(int j=1;j<=C;j++){
				printf("%d",A[i][j]);
				univ_id++;
				if(univ_id%50 == 0) printf("\n");
			}
			printf("\n");
		}else if(tmp_tt == 'B'){
			univ_id = 0;
			for(int i=1;i<=R;i++) for(int j=1;j<=C;j++){
				qs[i][j] = A[i][j] = str[univ_id++] - '0';
				qs[i][j] += qs[i-1][j] + qs[i][j-1] - qs[i-1][j-1];
			}
			printf("D%4d%4d\n",R,C);
			univ_id = 0;
			g(R,C,1,R,1,C);
			printf("\n");
		}
	}
	return 0;
}