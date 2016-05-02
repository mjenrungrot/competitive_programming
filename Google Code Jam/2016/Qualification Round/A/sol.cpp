#include <cstdio>
#include <cstring>

int cc[20];
int T;

void run(){
	int N;
	scanf("%d",&N);

	if(N == 0){
		printf("INSOMNIA\n");
		return ;
	}
	memset(cc,0,sizeof cc);

	int cc_count = 0;
	int ans = N;
	while(true){
		int tmp = ans;
		while(tmp > 0){
			cc_count += (1 - cc[tmp%10]);
			cc[tmp%10] = true;
			tmp /= 10;
		}
		if(cc_count == 10) break;
		ans += N;
	}
	printf("%d\n",ans);
}

int main(){ 
	freopen("A-large.in","r",stdin);
	freopen("A-large.out","w",stdout);

	scanf("%d",&T);

	int test = 0;
	while(T--){
		printf("Case #%d: ",++test);
		run();
	}
	return 0;
}