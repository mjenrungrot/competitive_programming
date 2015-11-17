#include <cstdio>
#include <cstring>
#include <algorithm>
using namespace std;

const int MAXN = 1e5+100;
int S,B,left[MAXN],right[MAXN],isdead[MAXN];

int goleft(int id){
	if(id <= 0) return -1;
	if(not isdead[id]) return id;
	else return left[id] = goleft(left[id]);
}
int goright(int id){
	if(id >= S+1) return -1;
	if(not isdead[id]) return id;
	else return right[id] = goright(right[id]);
}

int main(){
	// freopen("in","r",stdin);
	while(scanf("%d %d",&S,&B) == 2){
		if(S + B == 0) break;

		memset(isdead,0,sizeof isdead);
		for(int i=1;i<=S;i++) left[i] = i-1, right[i] = i+1;
		isdead[0] = isdead[S+1] = true;
		left[1] = -1;
		right[S] = -1;

		int ll,rr,ans1,ans2;
		for(int i=1;i<=B;i++){
			scanf("%d %d",&ll,&rr);
			for(int j=ll;j<=rr;j++){
				isdead[j] = true;
				left[j] = goleft(j);
				right[j] = goright(j);
			}

			// for(int k=1;k<=S;k++) printf("[%d]",left[k]); printf("\n");
			// for(int k=1;k<=S;k++) printf("[%d]",right[k]); printf("\n");

			if(left[ll] == -1) printf("*");
			else printf("%d",left[ll]);
			if(right[rr] == -1) printf(" *\n");
			else printf(" %d\n",right[rr]);
		}
		printf("-\n");
	}
	return 0;
}