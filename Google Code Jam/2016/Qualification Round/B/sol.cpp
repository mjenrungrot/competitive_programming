#include <cstdio>

char str[105];

void run(){
	int ans = 0;
	scanf("%s",str);

	while(true){
		bool check = true;
		for(int i=0;str[i]!=0;++i){
			if(str[i] == '-'){
				check = false;
				break;
			}
		}

		if(check){
			printf("%d\n",ans);
			return ;
		}

		int id = 0;
		while(str[id+1] != 0 and str[id] == str[id+1]) id++;
		for(int i=0;i<=id;i++) str[i] = (str[i] == '+' ? '-' : '+');
		++ans;
	}
}

int main(){
	freopen("B-large.in","r",stdin);
	freopen("B-large.out","w",stdout);

	int T;
	scanf("%d",&T);
	int test = 0;
	while(T--){
		printf("Case #%d: ",++test);
		run();
	}
	return 0;
}