#include <cstdio>

int a1,a2,a3,a4,a5,a6;

int main(){
	// freopen("in","r",stdin);
	scanf("%d %d %d %d %d %d",&a1,&a2,&a3,&a4,&a5,&a6);
	printf("%d\n",(a1+a2+a3)*(a1+a2+a3)-a1*a1-a3*a3-a5*a5);
	return 0;
}
/*
2 4 5 3 3 6

	  _____
     /     \ 
    /       \
   /		 \
  /			  \
 /			  /
/  			 /
\ 	 	    /
 \	 	   /
  \_______/
*/