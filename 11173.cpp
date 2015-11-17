#include <cstdio>
int main(){
	// freopen("in","r",stdin);
	int T; scanf("%d",&T);
	while(T--){
		int n,k;
		scanf("%d %d",&n,&k);

		int ans = 0;
		bool swap = false;
		for(int i=30;i>=0;i--){
			if(not swap){
				if((1<<i)&k){
					ans += (1<<i);
					swap = true;
				}
			}else{
				if(!((1<<i)&k)){
					ans += (1<<i);
					swap = false;
				}else{
					swap = true;
				}
			}
		}
		printf("%d\n",ans);
	}
	return 0;
}