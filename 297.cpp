#include <cstdio>
#include <cstring>

char S1[4000],S2[4000];
int A[50][50];
int id;

void f(char *str,int y1,int x1,int y2,int x2){
	if(str[id] == 'p'){
		id++;
		f(str,y1,(x1+x2)/2+1,(y1+y2)/2,x2);
		id++;
		f(str,y1,x1,(y1+y2)/2,(x1+x2)/2);
		id++;
		f(str,(y1+y2)/2+1,x1,y2,(x1+x2)/2);
		id++;
		f(str,(y1+y2)/2+1,(x1+x2)/2+1,y2,x2);
	}else if(str[id] == 'e'){
	}else if(str[id] == 'f'){
		for(int i=y1;i<=y2;i++) for(int j=x1;j<=x2;j++) A[i][j] = 1;
	}
}

int main(){
	// freopen("in","r",stdin);
	int T;
	scanf("%d",&T);
	while(T--){
		memset(A,0,sizeof A);

		scanf("%s %s",S1,S2);
		id = 0;
		f(S1,1,1,32,32);
		id = 0;
		f(S2,1,1,32,32);

		int ans = 0;
		for(int i=1;i<=32;i++) for(int j=1;j<=32;j++) ans += A[i][j];
		printf("There are %d black pixels.\n",ans);
	}


	return 0;
}