#include <cstdio>

int N,a,b,c,d;
int main(){
	freopen("4-sided-figures_InputForSubmission_1.txt","r",stdin);
	freopen("4-sided-figures_InputForSubmission_1.out","w",stdout);
	scanf("%d",&N);
	for(int i=1;i<=N;i++){
		scanf("%d %d %d %d",&a,&b,&c,&d);
		bool fuck = false;
		if(a + b + c < d) fuck = true;
		if(a + c + d < b) fuck = true;
		if(a + b + d < c) fuck = true;
		if(b + c + d < a) fuck = true;
		printf("%s\n",fuck ? "Impossible" : "Possible");
	}
	return 0;
}