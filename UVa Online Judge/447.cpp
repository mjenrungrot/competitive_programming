#include <cstdio>

const int dify[] = {-1,-1,-1,0,0,1,1,1};
const int difx[] = {-1,0,1,-1,1,-1,0,1};
const int MAXD = 20;
int T[50][50],newT[50][50];
int Y;

void print(){
	for(int i=1;i<=20;i++){
		for(int j=1;j<=20;j++) printf("%c",T[i][j]?'O':' ');
		printf("\n");
	}
}
void printline(){
	for(int i=1;i<=MAXD;i++) printf("*");
	printf("\n");
}

int neighbour(int y,int x){
	int ans = 0;
	for(int k=0;k<8;k++) ans += (T[y+dify[k]][x+difx[k]] > 0);
	return ans;
}
void init(){
	for(int i=1;i<=20;i++) for(int j=1;j<=20;j++) T[i][j] = newT[i][j] = false;
}

int main(){
	// freopen("in","r",stdin);
	// freopen("out","w",stdout);

	int TT; scanf("%d",&TT);
	bool line = false;
	while(TT--){
		if(line) printf("\n");
		line = true;

		init();
		scanf("%d",&Y);
		int y,x;
		char str[100];
		fgets(str,sizeof(str),stdin); // blank after the number of years
		while(fgets(str,sizeof(str),stdin)){
			if(str[0] == '\n') break;
			sscanf(str,"%d %d",&y,&x);
			T[y][x] = true;	
			// printf("[%s] %d %d\n",str,y,x);
		}	

		for(int i=1;i<=Y;i++){
			printline();
			print();
			for(int i=1;i<=20;i++) for(int j=1;j<=20;j++){
				if(T[i][j]){
					int xx = neighbour(i,j);
					if(xx >= 2 and xx <= 3) newT[i][j] = true;
					else if(xx >= 4 or xx <= 1) newT[i][j] = false;
				}else{
					if(neighbour(i,j) == 3) newT[i][j] = true;
				}
			}

			for(int i=1;i<=20;i++) for(int j=1;j<=20;j++){
				T[i][j] = newT[i][j];
				newT[i][j] = false;
			}
		}
		printline();
	}
	return 0;
}