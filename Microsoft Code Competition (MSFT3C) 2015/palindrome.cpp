#include <cstdio>
#include <cstring>
#include <algorithm>
using namespace std;
int cc[30];
char str[200];

int ff(int x){
	int xx = 1;
	for(int i=1;i<=x;i++) xx *= i;
	return xx;
}

int main(){
	freopen("Palindromic-anagrams_InputForSubmission_1.txt","r",stdin);
	freopen("Palindromic-anagrams_InputForSubmission_1.out","w",stdout);

	while(scanf("%s",str) == 1){
		memset(cc,0,sizeof cc);
		for(int i=0;str[i];i++) cc[str[i]-'a']++;
		sort(&cc[0],&cc[26]);

		bool already = false;
		int n_del = 0;
		for(int i=25;i>=0;i--){
			if(cc[i]%2){
				if(not already) already = true;
				else{
					cc[i]--;
					n_del++;
				}
			}
		}

		int sum = 0;
		for(int i=25;i>=0;i--) sum += (cc[i]/2);
		sum = ff(sum);
		for(int i=25;i>=0;i--){
			if(cc[i]/2){
				sum /= ff(cc[i]/2);
			}
		}
		printf("%d,%d\n",n_del,sum);
	}

	return 0;
}
/*
abggba
agbbga
gabbag
bag
bga
*/