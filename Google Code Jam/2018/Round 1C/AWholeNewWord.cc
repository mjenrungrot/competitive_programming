/*
 * Problem: A Whole New Word
 * Link: https://codejam.withgoogle.com/2018/challenges/0000000000007765/dashboard
 * Source: Google Codejam 2018 Round 1C
 */

#include <cstdio>
#include <cstring>
#include <string>
#include <set>
using namespace std;

int N, L;
char str[2005][15];
string words[2005];
set <string> S;
int possible[15][30];

char answer[15];
bool found;

int f(int idx){
	if(idx == L+1){
		answer[idx] = 0;
		string test = &answer[1];
		if(S.count(test)) return false;
		return true;
	}

	int valid;
	for(int i=1;i<=26;i++){
		if(not possible[idx][i]) continue;
		answer[idx] = 'A' + i - 1;
		valid = f(idx+1);
		if(valid) return true;
	}
	return false;
}

void runTest(int testId){
	memset(possible, 0, sizeof possible);
	memset(answer, 0, sizeof answer);

	scanf("%d %d",&N, &L);
	S.clear();
	for(int i=1;i<=N;i++){
		scanf("%s", &str[i][1]);
		words[i] = &str[i][1];
		S.insert(words[i]);
		for(int j=1;j<=L;j++) possible[j][str[i][j] - 'A' + 1] = true;
	}

	found = f(1);
	printf("Case #%d: ", testId);
	if(found == false) printf("-\n");
	else{
		for(int i=1;i<=L;i++) printf("%c",answer[i]);
		printf("\n");
	}
}

int main(){
	int T;
	scanf("%d", &T);
	for(int i=1;i<=T;i++) runTest(i);
	return 0;
}
