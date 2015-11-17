#include <cstdio>
#include <vector>
#include <algorithm>
using namespace std;

vector <int> container[15],unused;
int n_container,max_weight[15],sum[15],sum_unused;
int n_package;

void print(){
	int max_height = 0;
	for(int i=1;i<=n_container;i++) max_height = max(max_height,(int)container[i].size());
	for(int i=max_height;i>=1;i--){
		for(int j=1;j<=n_container;j++){
			if(j > 1) printf(" ");

			if((int)container[j].size() >= i) printf("%d",container[j][i-1]);
			else printf(":");
		}
		printf("\n");
	}
	for(int i=1;i<=n_container*2 - 1;i++) printf("="); printf("\n"); 
	for(int i=1;i<=n_container;i++){
		if(i > 1) printf(" ");
		printf("%d",i);
	}
	printf("\n\n");

	int cargo_weight = 0, unused_weight = 0, unloaded_weight = 0;
	for(int i=1;i<=n_container;i++){
		cargo_weight += sum[i];
		unused_weight += max_weight[i] - sum[i];
	}
	for(int i=0;i<unused.size();i++) unloaded_weight += unused[i];
	printf("cargo weight: %d\n",cargo_weight);
	printf("unused weight: %d\n",unused_weight);
	printf("unloaded weight: %d\n",unloaded_weight);
}

int main(){
	// freopen("in","r",stdin);
	// freopen("out","w",stdout);
	bool line = false;
	while(scanf("%d",&n_container) == 1){
		if(line) printf("\n");
		line = true;

		for(int i=1;i<=n_container;i++){
			scanf("%d",&max_weight[i]);
			container[i].clear();
			sum[i] = 0;
		}
		scanf("%d",&n_package);
		unused.clear();
		sum_unused = 0;
		while(n_package--){
			int xx; scanf("%d",&xx);

			int min_package = 1e9;
			for(int i=1;i<=n_container;i++) if(sum[i] < max_weight[i]) min_package = min(min_package,(int)container[i].size());

			int capacity = -1,idx = -1;
			for(int i=1;i<=n_container;i++) if((int)container[i].size() == min_package and max_weight[i] - sum[i] > capacity){
				idx = i;
				capacity = max_weight[i] - sum[i];
			}

			if(idx != -1 and capacity > 0 and sum[idx] + xx <= max_weight[idx]){
				// printf("push %d at %d\n",xx,idx);
				sum[idx] += xx;
				container[idx].push_back(xx);
			}else{
				unused.push_back(xx);
				sum_unused += xx;
			}
		}
		print();
	}
	return 0;
}