#include <cstdio>
#include <cstring>
#include <vector>
using namespace std;

typedef pair<int,int> ii;
typedef pair<ii,int> iii;

int A[105][105],N;
vector <iii> V;

int main(){
	// freopen("in","r",stdin);
	while(scanf("%d",&N) == 1){
		V.clear();
		for(int i=1;i<=N;i++) for(int j=1;j<=N;j++) scanf("%d",&A[i][j]);

		int ans = 0;
		for(int i=1;i<=N;i++) for(int j=1;j<=N;j++) for(int k=1;k<=N;k++){
			if(i == j or i == k or j == k) continue;
			if(i < j and j > k) continue;
			if(i > j and j < k) continue;

			if(!A[i][j] and !A[j][i] and !A[k][j] and !A[j][k] and !A[k][i] and !A[i][k]){
				if(i > j or i > k) continue;
				V.push_back(iii(ii(i,j),k));
				ans++;
			}else if(A[i][j] and A[j][k] and A[k][i]){
				V.push_back(iii(ii(i,j),k));
				ans++;
			}
		}
		printf("%d\n",ans);
		for(int i=0;i<(int)V.size();i++) printf("%d %d %d\n",V[i].first.first,V[i].first.second,V[i].second);
	}

	return 0;
}