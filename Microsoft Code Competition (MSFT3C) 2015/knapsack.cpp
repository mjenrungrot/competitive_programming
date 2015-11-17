#include <cstdio>
#include <cmath>
#include <vector>
#include <algorithm>
using namespace std;

const double EPS = 1e-9;

struct duck{
	int id;
	int score,dura;
	
	double score_per_min;
	bool operator < (struct duck _x) const {
		if(fabs(score_per_min - _x.score_per_min) < EPS){
			if(dura != _x.dura) return dura < _x.dura;
			return id < _x.id;
		}
		return score_per_min > _x.score_per_min;
	}
}A[100];

double T;
int a,b,c,N;

int partial[10000];
vector <int> V;

int main(){
	freopen("Pick-your-problems_InputForSubmission_1.txt","r",stdin);
	freopen("Pick-your-problems_InputForSubmission_1.out","w",stdout);
	
	scanf("%lf",&T);
	while(scanf("%d,%d,%d",&a,&b,&c) == 3){
		++N;
		A[N].id = a;
		A[N].score = b;
		A[N].dura = c;
		A[N].score_per_min = (double)A[N].score / (double)A[N].dura;
	}
	sort(&A[1],&A[N+1]);
	// for(int i=1;i<=N;i++) printf("[%d] %d %d\n",A[i].id,A[i].score,A[i].dura);

	double now_time = 0.0, score = 0.0;
	for(int i=1;i<=N;i++){
		if(fabs(now_time - T) < EPS) break;
		if(now_time + (double)A[i].dura <= T){
			score += (double)A[i].score;
			now_time += (double)A[i].dura;
			V.push_back(A[i].id);
		}else{
			score += (T-now_time) * (double)(A[i].score_per_min);
			now_time = T;
			V.push_back(A[i].id);
			partial[A[i].id] = true;
		}
	}
	sort(V.begin(),V.end());
	printf("%.0lf\n",floor(score));
	for(int i=0;i<(int)V.size();i++){
		if(i) printf(",");
		printf("%d",V[i]);
		if(partial[V[i]]) printf("*");
	}
	printf("\n");
	return 0;
}