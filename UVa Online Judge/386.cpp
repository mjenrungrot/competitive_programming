#include <cstdio>

int main(){
	// freopen("out","w",stdout);
	int A,B,C,D;
	for(int a=1;a<=200;a++){
		A = a*a*a;
		for(int b=2;b<=a;b++){
			B = b*b*b;
			for(int c=b;c<=a;c++){
				C = c*c*c;
				if(B+C >= A) break;
				for(int d=c;d<=a;d++){
					D = d*d*d;
					if(D+B+C > A)  break;
					if(D+B+C == A){
						printf("Cube = %d, Triple = (%d,%d,%d)\n",a,b,c,d);
						break;
					}
				}
			}
		}
	}
	return 0;
}