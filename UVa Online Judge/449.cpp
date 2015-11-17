#include <cstdio>	
#include <cstring>
#include <cassert>
#include <string>
#include <vector>
#include <iostream>
using namespace std;

string key;
char str[10000],*p;

int back(string ss){
	if(ss == "C") return 0;
	if(ss == "B#") return 0;
	if(ss == "C#") return 1;
	if(ss == "Db") return 1;
	if(ss == "D") return 2;
	if(ss == "D#") return 3;
	if(ss == "Eb") return 3;
	if(ss == "E") return 4;
	if(ss == "F") return 5;
	if(ss == "E#") return 5;
	if(ss == "F#") return 6;
	if(ss == "Gb") return 6;
	if(ss == "G") return 7;
	if(ss == "G#") return 8;
	if(ss == "Ab") return 8;
	if(ss == "A") return 9;
	if(ss == "A#") return 10;
	if(ss == "Bb") return 10;
	if(ss == "B") return 11;
	return -1;
}
int findnum(string ss){
	if(ss == "SECOND") return 1;
	if(ss == "THIRD") return 2;
	if(ss == "FOURTH") return 3;
	if(ss == "FIFTH") return 4;
	if(ss == "SIXTH") return 5;
	if(ss == "SEVENTH") return 6;
	if(ss == "OCTAVE") return 0;
	return -1;
}

vector <int> possible;
const int dif[] = {2,2,1,2,2,2,1};
vector <string> V;

string answer[10],tmp[10];
bool pass_gen_ans,sharp,flat;
void gen_ans(int now,int a,int b,int c,int d,int e,int f,int g){
	if(now == 7){
		if(a == b and b == c and c == d and d == e and e == f and f == g and g == 1){
			if(flat) for(int i=0;i<=7;i++) if(tmp[i][1] == '#') return ;
			if(sharp) for(int i=0;i<=7;i++) if(tmp[i][1] == 'b') return ;

			pass_gen_ans = true;
			for(int i=0;i<=7;i++) answer[i] = tmp[i];
		}
		return ;
	}

	if(possible[now] == 0){
		if(pass_gen_ans) return ;
		tmp[now] = "C";
		gen_ans(now+1,a,b,c+1,d,e,f,g);

		if(pass_gen_ans) return ;
		tmp[now] = "B#";
		gen_ans(now+1,a,b+1,c,d,e,f,g);
	}else if(possible[now] == 1){
		if(pass_gen_ans) return ;
		tmp[now] = "C#";
		gen_ans(now+1,a,b,c+1,d,e,f,g);

		if(pass_gen_ans) return ;
		tmp[now] = "Db";
		gen_ans(now+1,a,b,c,d+1,e,f,g);
	}else if(possible[now] == 2){
		if(pass_gen_ans) return ;
		tmp[now] = "D";
		gen_ans(now+1,a,b,c,d+1,e,f,g);
	}else if(possible[now] == 3){
		if(pass_gen_ans) return ;
		tmp[now] = "D#";
		gen_ans(now+1,a,b,c,d+1,e,f,g);

		if(pass_gen_ans) return ;
		tmp[now] = "Eb";
		gen_ans(now+1,a,b,c,d,e+1,f,g);
	}else if(possible[now] == 4){
		if(pass_gen_ans) return ;
		tmp[now] = "E";
		gen_ans(now+1,a,b,c,d,e+1,f,g);

		if(pass_gen_ans) return ;
		tmp[now] = "Fb";
		gen_ans(now+1,a,b,c,d,e,f+1,g);
	}else if(possible[now] == 5){
		if(pass_gen_ans) return ;
		tmp[now] = "F";
		gen_ans(now+1,a,b,c,d,e,f+1,g);

		if(pass_gen_ans) return ;
		tmp[now] = "E#";
		gen_ans(now+1,a,b,c,d,e+1,f,g);
	}else if(possible[now] == 6){
		if(pass_gen_ans) return ;
		tmp[now] = "F#";
		gen_ans(now+1,a,b,c,d,e,f+1,g);

		if(pass_gen_ans) return ;
		tmp[now] = "Gb";
		gen_ans(now+1,a,b,c,d,e,f,g+1);
	}else if(possible[now] == 7){
		if(pass_gen_ans) return ;
		tmp[now] = "G";
		gen_ans(now+1,a,b,c,d,e,f,g+1);
	}else if(possible[now] == 8){
		if(pass_gen_ans) return ;
		tmp[now] = "G#";
		gen_ans(now+1,a,b,c,d,e,f,g+1);

		if(pass_gen_ans) return ;
		tmp[now] = "Ab";
		gen_ans(now+1,a+1,b,c,d,e,f,g);
	}else if(possible[now] == 9){
		if(pass_gen_ans) return ;
		tmp[now] = "A";
		gen_ans(now+1,a+1,b,c,d,e,f,g);
	}else if(possible[now] == 10){
		if(pass_gen_ans) return ;
		tmp[now] = "A#";
		gen_ans(now+1,a+1,b,c,d,e,f,g);

		if(pass_gen_ans) return ;
		tmp[now] = "Bb";
		gen_ans(now+1,a,b+1,c,d,e,f,g);
	}else if(possible[now] == 11){
		if(pass_gen_ans) return ;
		tmp[now] = "B";
		gen_ans(now+1,a,b+1,c,d,e,f,g);

		if(pass_gen_ans) return ;
		tmp[now] = "Cb";
		gen_ans(now+1,a,b,c+1,d,e,f,g);
	}
}

int isPossible(string val){
	for(int i=0;i<=7;i++) if(val == answer[i]) return i;
	return -1;
}


void f(){
	sharp = (key[1] == '#');
	flat = (key[1] == 'b');
	pass_gen_ans = false;
	gen_ans(0,0,0,0,0,0,0,0);

	for(int i=0;i<V.size();i++){
		int times = 0,now,to;
		strcpy(str,V[i].c_str());

		vector <string> VV;
		char *pp = strtok(str," \n");
		while(pp != NULL){
			VV.push_back(pp);
			pp = strtok(NULL," \n");	
		}
		printf("%s: ",VV[0].c_str());
		now = back(VV[0]);

		int at = isPossible(VV[0]);
		if(at == -1){
			printf("invalid note for this key\n");
			continue;
		}

		if(VV[1] == "DOWN") times = -1;
		else if(VV[1] == "UP") times = 1;
		printf("%s ",VV[1].c_str());
		// assert(VV.size() >= 3);
		printf("%s",VV[2].c_str());

		int len = findnum(VV[2]);	
		assert(len >= 0);
		to = at + times*len;
		to = (to+7)%7;

		printf(" > ");
		printf("%s",answer[to].c_str());
		printf("\n");
	}
}

int main(){
	// freopen("in","r",stdin);
	// freopen("out","w",stdout);

	bool line = false;
	while(cin >> key){
		if(line) printf("\n");
		line = true;

		printf("Key of %s\n",key.c_str());
		fgets(str,sizeof(str),stdin);	// the first line of each testcase 
		
		possible.clear();
		possible.push_back(back(key));
		for(int i=1;i<=7;i++) possible.push_back((possible[i-1] + dif[i-1])%12);

		fgets(str,sizeof(str),stdin);	
		p = strtok(str,";\n");
		V.clear();
		string ss;
		while(p != NULL){
			V.push_back(p);
			p = strtok(NULL,";\n");
		}
		f();
	}
	printf("\n");
	return 0;
}