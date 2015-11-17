#include <cstdio>
#include <cstring>
#include <cstdlib>
#include <vector>
#include <string>
using namespace std;

int N,NN,now;
char name[30][400],str[400];
int A[1005][30],isAlive[30],val[30];

void vote(){
	for(int i=1;i<=N;i++) val[i] = 0;
	for(int i=1;i<=NN;i++){
		for(int j=1;j<=N;j++){
			if(isAlive[A[i][j]]){
				val[A[i][j]]++;
				break;
			}
		}
	}
}
int have50(){
	int maxval = -1,maxidx;
	for(int i=1;i<=N;i++) if(isAlive[i] and val[i] > maxval) maxval = val[i], maxidx = i;

	if(maxval > NN/2) return maxidx;
	return -1;
}
void elim(){
	int minval = 1e9;
	for(int i=1;i<=N;i++) if(isAlive[i] and val[i] < minval) minval = val[i];

	int cc = 0;
	for(int i=1;i<=N;i++) if(isAlive[i] and val[i] == minval) cc++;

	if(cc == now) return;
	for(int i=1;i<=N;i++) if(isAlive[i] and val[i] == minval) isAlive[i] = false, now--;
}
bool AllTie(){
	int v;
	for(int i=1;i<=N;i++) if(isAlive[i]){
		v = val[i];
		break; 
	}
	for(int i=1;i<=N;i++) if(isAlive[i] and v != val[i]) return false;
	return true;
}

void run(){
	scanf("%d",&N);
	// printf("N = %d\n",N);
	fgets(name[0],sizeof(name[0]),stdin);
	for(int i=1;i<=N;i++){
		fgets(name[i],sizeof(name[i]),stdin);
		isAlive[i] = true;
		// printf("[%s]\n",name[i]);
	}
	// return ;

	NN = 0;
	while(fgets(str,sizeof(str),stdin)){
		if(str[0] == ' ' or str[0] == '\n') break;
		NN++;
		
		char *p = strtok(str," \n");
		for(int i=1;i<=N;i++){
			A[NN][i] = atoi(p);
			p = strtok(NULL," \n");
		}

		// for(int i=1;i<=N;i++) printf("[%d]",A[NN][i]);
		// printf("\n");
	}

	int vv;
	now = N;
	while(now >= 1){
		vote();

		vv = have50();
		if(vv != -1){
			printf("%s",name[vv]);
			break;
		}

		if(AllTie()){
			for(int i=1;i<=N;i++) if(isAlive[i]) printf("%s",name[i]);
			break;
		}

		elim();
	}
}

int main(){
	// freopen("in","r",stdin);
	// freopen("out","w",stdout);
	int T; scanf("%d",&T);
	while(T--){
		run();
		if(T) printf("\n");
	}
	return 0;
}