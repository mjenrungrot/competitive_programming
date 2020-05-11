#include <cstdio>
#include <cstring>
#include <algorithm>
using namespace std;

const int MAXN = 100005;
const int MAXNODE = 800005;
struct segment_tree{
	int A[MAXNODE],flag[MAXNODE];

	void kick(int node,int L,int R){
		if(L != R) flag[2*node] = flag[2*node+1] = flag[node];
		A[node] = (flag[node] == 1 ? R-L+1 : 0);
		flag[node] = 0;
	}
	void set(int node,int L,int R,int wantL,int wantR,int val){
		if(flag[node]) kick(node,L,R);
		if(wantL > R or wantR < L) return;
		if(wantL <= L and R <= wantR){
			if(val == 0){
				if(R != L) flag[node] = -1;
				A[node] = 0;
			}else{
				if(R != L) flag[node] = 1;
				A[node] = R-L+1;
			}
			return ;
		}
		set(2*node,L,(L+R)/2,wantL,wantR,val);
		set(2*node+1,(L+R)/2+1,R,wantL,wantR,val);
		A[node] = A[2*node] + A[2*node+1];
	}
	int sum(int node,int L,int R,int wantL,int wantR){
		if(flag[node]) kick(node,L,R);
		if(wantL > R or wantR < L) return 0;
		if(wantL <= L and R <= wantR) return A[node];
		int valL = sum(2*node,L,(L+R)/2,wantL,wantR);
		int valR = sum(2*node+1,(L+R)/2+1,R,wantL,wantR);
		return valL+valR;
	}
	void print(int node,int L,int R){
		printf("[%d-%d] [%d][%d]\n",L,R,A[node],flag[node]);
		if(L == R) return;
		print(2*node,L,(L+R)/2);
		print(2*node+1,(L+R)/2+1,R);
	}
}S[30];

int N,Q;
char str[MAXN];
int cc[30];

int main(){
	// freopen("in","r",stdin);
	scanf("%d %d",&N,&Q);
	scanf("%s",&str[1]);
	for(int i=1;i<=N;i++) S[str[i]-'a'].set(1,1,N,i,i,1);
	for(int i=1;i<=Q;i++){
		int l,r,k;
		scanf("%d %d %d",&l,&r,&k);
		
		memset(cc,0,sizeof cc);
		for(int x=0;x<26;x++){
			cc[x] = S[x].sum(1,1,N,l,r);
			S[x].set(1,1,N,l,r,0);
		}

		if(k == 1){
			int now = l,end;
			for(int x=0;x<26;x++){
				end = now + cc[x] - 1;
				S[x].set(1,1,N,now,end,1);
				now = end+1;
				if(now > N) break;
			}
		}else{
			int now = l,end;
			for(int x=25;x>=0;x--){
				end = now + cc[x] - 1;
				S[x].set(1,1,N,now,end,1);
				now = end+1;
				if(now > N) break;
			}
		}
	}

	for(int i=0;i<26;i++) for(int j=1;j<=N;j++){
		if(S[i].sum(1,1,N,j,j) == 1){
			str[j] = 'a'+i;
		}else if(S[i].sum(1,1,N,j,j) > 1) printf("KUY\n");
	}
	printf("%s\n",&str[1]);
	return 0;
}