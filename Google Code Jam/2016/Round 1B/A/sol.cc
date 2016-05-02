#include <cstdio>
#include <cstring>
#include <string>
#include <iostream>
using namespace std;

string str;
int cc1[30],cc2[20];

void run(){
	cin >> str;
	memset(cc1,0,sizeof cc1);
	memset(cc2,0,sizeof cc2);

	for(int i=0;i< str.length();i++) cc1[str[i]-'A']++;

	// Z
	if(cc1['Z'-'A']){
		int nn = cc1['Z'-'A'];
		cc2[0] += nn;
		cc1['Z'-'A'] -= nn;
		cc1['E'-'A'] -= nn;
		cc1['R'-'A'] -= nn;
		cc1['O'-'A'] -= nn;
	}

	// X
	if(cc1['X'-'A']){
		int nn = cc1['X'-'A'];
		cc2[6] += nn;
		cc1['S'-'A'] -= nn;
		cc1['I'-'A'] -= nn;
		cc1['X'-'A'] -= nn;
	}

	// G
	if(cc1['G'-'A']){
		int nn = cc1['G'-'A'];
		cc2[8] += nn;
		cc1['E'-'A'] -= nn;
		cc1['I'-'A'] -= nn;
		cc1['G'-'A'] -= nn;
		cc1['H'-'A'] -= nn;
		cc1['T'-'A'] -= nn;
	}

	// W 
	if(cc1['W'-'A']){
		int nn = cc1['W'-'A'];
		cc2[2] += nn;
		cc1['T'-'A'] -= nn;
		cc1['W'-'A'] -= nn;
		cc1['O'-'A'] -= nn;
	}

	// T
	if(cc1['T'-'A']){
		int nn = cc1['T'-'A'];
		cc2[3] += nn;
		cc1['T'-'A'] -= nn;
		cc1['H'-'A'] -= nn;
		cc1['R'-'A'] -= nn;
		cc1['E'-'A'] -= nn;
		cc1['E'-'A'] -= nn;
	}

	// S
	if(cc1['S'-'A']){
		int nn = cc1['S'-'A'];
		cc2[7] += nn;
		cc1['S'-'A'] -= nn;
		cc1['E'-'A'] -= nn;
		cc1['V'-'A'] -= nn;
		cc1['E'-'A'] -= nn;
		cc1['N'-'A'] -= nn;
	}

	// V
	if(cc1['V'-'A']){
		int nn = cc1['V'-'A'];
		cc2[5] += nn;
		cc1['F'-'A'] -= nn;
		cc1['I'-'A'] -= nn;
		cc1['V'-'A'] -= nn;
		cc1['E'-'A'] -= nn;
	}

	// F
	if(cc1['F'-'A']){
		int nn = cc1['F'-'A'];
		cc2[4] += nn;
		cc1['F'-'A'] -= nn;
		cc1['O'-'A'] -= nn;
		cc1['U'-'A'] -= nn;
		cc1['R'-'A'] -= nn;
	}

	// O
	if(cc1['O'-'A']){
		int nn = cc1['O'-'A'];
		cc2[1] += nn;
		cc1['O'-'A'] -= nn;
		cc1['N'-'A'] -= nn;
		cc1['E'-'A'] -= nn;
	}

	// I
	if(cc1['I'-'A']){
		int nn = cc1['I'-'A'];
		cc2[9] += nn;
		cc1['N'-'A'] -= nn;
		cc1['I'-'A'] -= nn;
		cc1['N'-'A'] -= nn;
		cc1['E'-'A'] -= nn;
	}

	for(int i=0;i<=9;i++) for(int j=1;j<=cc2[i];j++) printf("%d",i);
	printf("\n");
}

int main(){
	freopen("A-large.in","r",stdin);
	freopen("A-large.out","w",stdout);
	int T;
	scanf("%d",&T);
	for(int i=1;i<=T;i++){
		printf("Case #%d: ",i);
		run();
	}
	return 0;
}

/*
Z -> ZERO
X -> SIX
G -> EIGHT
W -> TWO
T -> THREE
S -> SEVEN
V -> FIVE
F -> FOUR
O -> ONE
I -> NINE
*/