#include <cstdio>
#include <algorithm>
#include <vector>
using namespace std;

typedef pair<int,int> ii;
vector <ii> V;

vector <int> candidate;
int C,R;

int main(){
	// freopen("in","r",stdin);
	int N; scanf("%d",&N);
	for(int i=1;i<=N;i++){
		printf("Case #%d:",i);
		scanf("%d %d",&C,&R);

		int val = C-R;
		candidate.clear();
		if(C == R) candidate.push_back(0);

		for(int i=1;i*i<=val;i++){
			if(val%i == 0){
				if(i > R) candidate.push_back(i);
				if(val/i > R) candidate.push_back(val/i); 
			}
		}

		sort(candidate.begin(),candidate.end());
		candidate.erase(unique(candidate.begin(),candidate.end()),candidate.end());
		for(int j=0;j<candidate.size();j++) printf(" %d",candidate[j]);
		printf("\n");
	}
	return 0;
}