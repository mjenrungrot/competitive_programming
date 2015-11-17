#include <cstdio>
#include <string>
#include <algorithm>
using namespace std;

const int dify[] = {-1,0,1,0};
const int difx[] = {0,-1,0,1};

char str[50],T[300][300];
int R,C;

void flood(int y,int x,int now){
	if(T[y][x] == str[0]) return ; 
	T[y][x] = str[0];
	for(int k=0;k<4;k++) if(T[y+dify[k]][x+difx[k]] == now) flood(y+dify[k],x+difx[k],now);
}

int main(){
	// freopen("in","r",stdin);
	while(scanf("%s",str) == 1){
		if(str[0] == 'I'){
			scanf("%d %d",&C,&R);
			for(int i=1;i<=R;i++) for(int j=1;j<=C;j++) T[i][j] = 'O';
		}else if(str[0] == 'C'){
			for(int i=1;i<=R;i++) for(int j=1;j<=C;j++) T[i][j] = 'O';
		}else if(str[0] == 'L'){
			int x,y;
			scanf("%d %d %s",&x,&y,str);
			T[y][x] = str[0];
		}else if(str[0] == 'V'){
			int x,y1,y2;
			scanf("%d %d %d %s",&x,&y1,&y2,str);
			for(int i=min(y1,y2);i<=max(y1,y2);i++) T[i][x] = str[0];
		}else if(str[0] == 'H'){
			int x1,x2,y;
			scanf("%d %d %d %s",&x1,&x2,&y,str);
			for(int i=min(x1,x2);i<=max(x1,x2);i++) T[y][i] = str[0];
		}else if(str[0] =='K'){
			int x1,x2,y1,y2;
			scanf("%d %d %d %d %s",&x1,&y1,&x2,&y2,str);
			for(int i=min(y1,y2);i<=max(y1,y2);i++) for(int j=min(x1,x2);j<=max(x1,x2);j++) T[i][j] = str[0];
		}else if(str[0] == 'F'){
			int x,y;
			scanf("%d %d %s",&x,&y,str);
			flood(y,x,T[y][x]);
		}else if(str[0] == 'S'){
			scanf("%s",str);
			printf("%s\n",str);
			for(int i=1;i<=R;i++){
				for(int j=1;j<=C;j++) printf("%c",T[i][j]);
				printf("\n");
			}
		}else if(str[0] == 'X') break;
		else{
			fgets(str,sizeof(str),stdin);
		}
	}
	return 0;
}