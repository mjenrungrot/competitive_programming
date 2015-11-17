#include <cstdio>
#include <cstring>

char str[1005][105],str2[105];
int M,Q,len[1005],len_now;

int test(int id,int start){
	int ans = 0;
	for(int i=start,j=1;i<start+len_now;i++,j++){
		if(str[id][i] != str2[j]) ans++;
	}
	return ans;
}

int main(){
	// freopen("in","r",stdin);
	scanf("%d %d",&M,&Q);
	for(int i=1;i<=M;i++){
		scanf("%s",&str[i][1]);
		len[i] = strlen(&str[i][1]);
	}

	for(int i=1;i<=Q;i++){
		int val = 1e9,idx = 1;
		scanf("%s",&str2[1]);

		len_now = strlen(&str2[1]);
		for(int j=1;j<=M;j++){
			if(len[j] < len_now) continue;
			for(int k=1;k<=len[j]-len_now+1;k++){
				if(test(j,k) < val){
					val = test(j,k);
					idx = j;
				}
			}
		}
		printf("%d\n",idx);
	}
	return 0;
}