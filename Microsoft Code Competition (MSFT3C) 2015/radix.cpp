#include <cstdio>
#include <cstring>
#include <cstdlib>

char *p = "0123456789abcdefghijklmnopqrstuvwxyz";
char str[10000],aa[10000];

int a,b,xx = 0;
int val(char ch){
	if(ch >= '0' and ch <= '9') return ch-'0';
	else return ch-'a'+10;
}

void print(int val){
	if(val <= 0) return ;
	int yy = val%b;
	print(val/b);
	printf("%c",p[yy]);
}

int main(){
	freopen("Radix-conversion_InputForSubmission_2.txt","r",stdin);
	freopen("Radix-conversion_InputForSubmission_2.out","w",stdout);
	while(scanf("%s",str) == 1){
		char *p = strtok(str,",");
		xx = 0;
		while(p != NULL){
			if(xx == 0){
				strcpy(aa,p);
			}if(xx == 1){
				a = atoi(p);
			}else if(xx == 2){
				b = atoi(p);
			}
			xx++;
			p = strtok(NULL,",");
		}

		bool fuck = false;
		for(int i=0;i<strlen(aa);i++){
			if(not ((aa[i] >= '0' and aa[i] <= '9') or (aa[i] >= 'a' and aa[i] <= 'z'))) fuck = true;
			if(val(aa[i]) >= a){
				// printf("val[%c] = %d\n",aa[i],val(aa[i]));
				fuck = true;
			}
		}
		if(fuck or a <= 1 or b <= 1 or a >= 37 or b >= 37){
			printf("Invalid Input\n");
			continue;
		}

		// printf("aa = %s \n",aa);
		// continue;
		// printf("[%s] from %d to %d\n",aa,a,b);

		int val_10 = 0;
		for(int i=0;i<strlen(aa);i++){
			val_10 *= a;
			val_10 += val(aa[i]);
		}
		print(val_10);
		printf("\n");
		// printf("%d\n",val_10);
	}
	printf("\n");
	return 0;
}