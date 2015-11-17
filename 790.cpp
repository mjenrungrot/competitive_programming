#include <cstdio>
#include <vector>
#include <cstring>
#include <algorithm>
using namespace std;

typedef pair<int,int> ii;
vector <ii> V[30][10];

int isParticipate[30];
struct contestant{
	contestant(){}
	contestant(int score,int consumed_time,int id):score(score),consumed_time(consumed_time),id(id){}
	int score, consumed_time, id;

	void init(){
		score = consumed_time = id = 0;
	}

	bool operator < (struct contestant x) const {
		if(isParticipate[id] != isParticipate[x.id]) return isParticipate[id] > isParticipate[x.id];
		if(score != x.score) return score > x.score;
		if(consumed_time != x.consumed_time) return consumed_time < x.consumed_time;
		return id < x.id;
	}
}A[30];
char str[400];

int main(){
	// freopen("in","r",stdin);
	// freopen("out","w",stdout);
	int id,hh,mm;
	char prob[5],judge[5];
	int maxval = 0;
	int TT; scanf("%d",&TT);
	fgets(str,sizeof(str),stdin);
	fgets(str,sizeof(str),stdin);
	while(TT--){
		maxval = 0;
		while(fgets(str,sizeof(str),stdin)){
			if(str[0] == '\n') break;
			sscanf(str,"%d %s %d:%d %s",&id,prob,&hh,&mm,judge);
			V[id][prob[0]-'A'].push_back(ii(60*hh+mm,judge[0]=='Y'));
			isParticipate[id] = true;
			maxval = max(maxval,id);
		}
		for(int i=0;i<30;i++) A[i].init();
		for(int i=1;i<=25;i++) A[i].id = i, A[i].consumed_time = A[i].score = 0;
		memset(isParticipate,0,sizeof isParticipate);
		for(int i=1;i<=maxval;i++) isParticipate[i] = true;

		for(int i=1;i<=25;i++) for(int j=0;j<=7;j++){
			sort(V[i][j].begin(),V[i][j].end());

			bool isSolved = false;
			int count_no = 0,tt;
			for(int k=0;k<V[i][j].size();k++){
				if(V[i][j][k].second == 0) count_no++;
				else{
					tt = V[i][j][k].first;
					isSolved = true;
					break;
				}
			}
			if(isSolved){
				A[i].consumed_time += 20*count_no + tt;
				A[i].score++;
			}
			V[i][j].clear();
		}
		sort(&A[1],&A[30]);

		printf("RANK TEAM PRO/SOLVED TIME\n");
		int rank = 1;
		for(int i=1;i<=29;i++){
			if(not isParticipate[A[i].id]) continue;
			if(i > 1 and (A[i].score != A[i-1].score or A[i].consumed_time != A[i-1].consumed_time)) rank = i;
			if(A[i].score) printf("%4d %4d %4d %10d\n",rank,A[i].id,A[i].score,A[i].consumed_time);
			else printf("%4d %4d\n",rank,A[i].id);
		}
		if(TT) printf("\n");
	}
	return 0;
}