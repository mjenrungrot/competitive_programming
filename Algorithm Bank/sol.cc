#include "foo.h"

string S[1005][2];
int N;

void run(){
	map<string,int> M1,M2;
	scanf("%d",&N);


	for(int i=1;i<=N;i++){
		cin >> S[i][0] >> S[i][1];
		if(not M1.count(S[i][0])) M1[S[i][0]] = (int)M1.size();
		if(not M2.count(S[i][1])) M2[S[i][1]] = (int)M2.size();
	}

	vector< vector<int> > w((int)M1.size(), vector<int>((int)M2.size(),0));
	vector<int> mr((int)M1.size());
	vector<int> mc((int)M2.size());


	for(int i=1;i<=N;i++){
		w[M1[S[i][0]]][M2[S[i][1]]] = 1;
	}

	// printf("%d x %d\n",w.size(),w[0].size());
	// for(size_t i=0;i<w.size();i++){
	// 	for(size_t j=0;j<w[i].size();j++){
	// 		printf("[%d]",w[i][j]);
	// 	}
	// 	printf("\n");
	// }

	int n_bipartite = BipartiteMatching(w, mr, mc);
	// printf("%d\n",n_bipartite);
	// for(int i=0;i<mr.size();i++) printf("mr[%d] = %d\n",i,mr[i]);
	// for(int i=0;i<mc.size();i++) printf("mc[%d] = %d\n",i,mc[i]);

	int n_edge_dont_match = 0;
	for(size_t i=0;i<mr.size();i++) n_edge_dont_match += (mr[i] == -1);
	for(size_t i=0;i<mc.size();i++) n_edge_dont_match += (mc[i] == -1);

	int answer = N - n_bipartite - n_edge_dont_match;
	printf("%d\n",answer);
}

int main(){
	freopen("C-small-practice.in","r",stdin);
	freopen("C-small-practice.out","w",stdout);
	int T;
	scanf("%d",&T);
	for(int i=1;i<=T;i++){
		printf("Case #%d: ",i);
		run();
	}
	return 0;
}

/*
		CODE	----- JAM
				   /
		SPACE	--/ 
				 / 
				/
		PEARL  /
*/