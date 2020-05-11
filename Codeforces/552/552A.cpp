#include <cstdio>
int N;
int main(){
	scanf("%d",&N);
	int ans = 0;
	for(int i=1;i<=N;i++){
		int x1,x2,y1,y2;
		scanf("%d %d %d %d",&x1,&y1,&x2,&y2);
		ans += (x2-x1+1) * (y2-y1+1);
	}
	printf("%d\n",ans);
	return 0;
}