#include <cstdio>
#include <cstring>
#include <cmath>
#include <algorithm>
using namespace std;

const int INF = 1e9;

char str1[20];
char str2[20];
int len1,len2;

int best1, best2, min_dist;

int abs(int x){ return x < 0 ? -x: x;}

void g(int id2, int val1, int val2){
	if(id2 == len2){
		if(abs(val1 - val2) < min_dist){
			min_dist = abs(val1 - val2);
			best1 = val1;
			best2 = val2;
		}else if(abs(val1 - val2) == min_dist and val1 < best1){
			best1 = val1;
			best2 = val2;
		}else if(abs(val1 - val2) == min_dist and val1 == best1 and val2 < best2){
			best2 = val2;
		}
		return ;
	}

	if(str2[id2] != '?'){
		g(id2+1, val1, 10*val2 + str2[id2]-'0');
	}else{
		for(int i=0;i<10;i++) g(id2+1, val1, 10*val2 + i);
	}
}

void f(int id1,int val){
	if(id1 == len1){
		g(0,val,0);
		return ;
	}

	if(str1[id1] != '?'){
		f(id1+1, 10*val + str1[id1]-'0');
	}else{
		for(int i=0;i<10;i++) f(id1+1, 10*val + i);
	}
}

void run(){
	scanf("%s %s",str1,str2);
	len1 = strlen(str1);
	len2 = strlen(str2);

	min_dist = INF;
	f(0,0);

	if(len1 == 1){
		printf(" %01d", best1);
	}else if(len1 == 2){
		printf(" %02d", best1);
	}else if(len1 == 3){
		printf(" %03d", best1);
	}

	if(len2 == 1){
		printf(" %01d", best2);
	}else if(len2 == 2){
		printf(" %02d", best2);
	}else if(len2 == 3){
		printf(" %03d", best2);
	}

	printf("\n");
}

int main(){
	freopen("B-small-attempt0.in","r",stdin);
	// freopen("B-small-attempt0.out","w",stdout);
	int T;
	scanf("%d",&T);
	for(int i=1;i<=T;i++){
		printf("Case #%d:",i);
		run();
	}
	return 0;
}