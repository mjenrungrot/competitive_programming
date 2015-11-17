#include <cstdio>
char str[300];

int main(){
	// freopen("in","r",stdin);
	int test = 0;
	while(fgets(str,sizeof(str),stdin)){
		int a=0,b=0,c=0,d=0,e=0,f=0,g=0,h=0,i=0;
		for(int ii=0;str[ii];ii++){
			if(str[ii] == 'a') a++;
			if(str[ii] == 'b') b++;
			if(str[ii] == 'c') c++;
			if(str[ii] == 'd') d++;
			if(str[ii] == 'e') e++;
			if(str[ii] == 'f') f++;
			if(str[ii] == 'g') g++;
			if(str[ii] == 'h') h++;
			if(str[ii] == 'i') i++;
		}
		printf("Case #%d:\n",++test);
		printf("%d %d %d\n",(a+b+d)%10,(a+b+c+e)%10,(b+c+f)%10);
		printf("%d %d %d\n",(a+d+e+g)%10,(b+d+e+f+h)%10,(c+e+f+i)%10);
		printf("%d %d %d\n",(d+g+h)%10,(e+g+h+i)%10,(f+h+i)%10);
	}
	return 0;
}