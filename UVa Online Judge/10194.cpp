#include <cstdio>
#include <cstring>
#include <algorithm>
#include <vector>
#include <string>
#include <map>
using namespace std;

const int WIN = 3;
const int TIE = 1;
const int LOS = 0;
char str[300];
int N,M;

string f(string word){
	for(int i=0;i<word.length();i++) word[i] = toupper(word[i]);
	return word;
}

struct team{
	int point,n_game,win,tie,loss,goal_dif,goal_score,goal_against;
	string name;

	void clear(){
		point = n_game = win = tie = loss = goal_dif = goal_score = goal_against = 0;
		name = "";
	}

	bool operator < (struct team x) const {
		if(point != x.point) return point > x.point;
		if(win != x.win) return win > x.win;
		if(goal_dif != x.goal_dif) return goal_dif > x.goal_dif;
		if(goal_score != x.goal_score) return goal_score > x.goal_score;
		if(n_game != x.n_game) return n_game < x.n_game;
		return f(name) < f(x.name);
	}
}A[1005];


map <string,int> name_to_id;

int main(){
	// freopen("in","r",stdin);
	int tt; scanf("%d ",&tt);
	while(tt--){
		name_to_id.clear();
		for(int i=0;i<1000;i++) A[i].clear();

		fgets(str,sizeof(str),stdin);
		printf("%s",str);

		scanf("%d ",&N);
		for(int i=1;i<=N;i++){
			fgets(str,sizeof(str),stdin);
			strtok(str,"\n");
			A[i].name = str;
			name_to_id[A[i].name] = i;
		}

		scanf("%d ",&M);
		for(int i=1;i<=M;i++){
			fgets(str,sizeof(str),stdin);

			vector <string> partition;
			string S;
			char *p = strtok(str,"#@\n");
			while(p != NULL){
				partition.push_back(S = p);
				p = strtok(NULL,"#@\n");
			}

			string team1 = partition[0];
			int score1 = stoi(partition[1].c_str());
			int score2 = stoi(partition[2].c_str());
			string team2 = partition[3];

			int id1 = name_to_id[team1];
			int id2 = name_to_id[team2];

			A[id1].n_game++;
			A[id1].goal_dif += score1-score2;
			A[id1].goal_score += score1;
			A[id1].goal_against += score2;

			A[id2].n_game++;
			A[id2].goal_dif += score2-score1;
			A[id2].goal_score += score2;
			A[id2].goal_against += score1;

			if(score1 > score2){
				A[id1].point += WIN;
				A[id1].win++;
				A[id2].point += LOS;
				A[id2].loss++;
			}else if(score1 == score2){
				A[id1].point += TIE;
				A[id1].tie++;
				A[id2].point += TIE;
				A[id2].tie++;
			}else{
				A[id1].point += LOS;
				A[id1].loss++;
				A[id2].point += WIN;
				A[id2].win++;
			}
		}
		sort(&A[1],&A[N+1]);
		for(int i=1;i<=N;i++) printf("%d) %s %dp, %dg (%d-%d-%d), %dgd (%d-%d)\n",i,A[i].name.c_str(),A[i].point,A[i].n_game,A[i].win,A[i].tie,A[i].loss,A[i].goal_dif,A[i].goal_score,A[i].goal_against);
		if(tt) printf("\n");
	}
	return 0;
}