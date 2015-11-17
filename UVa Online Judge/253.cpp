#include <cstdio>

/*
clockwise
123456 => 142536

intothepage
123456 => 263415
*/


char str1[20],str2[20],tmp[20];

void cw(){
	for(int i=1;i<=6;i++) tmp[i] = str1[i];
	str1[1] = tmp[1];
	str1[2] = tmp[4];
	str1[3] = tmp[2];
	str1[4] = tmp[5];
	str1[5] = tmp[3];
	str1[6] = tmp[6];
}

void into(){
	for(int i=1;i<=6;i++) tmp[i] = str1[i];
	str1[1] = tmp[2];
	str1[2] = tmp[6];
	str1[3] = tmp[3];
	str1[4] = tmp[4];
	str1[5] = tmp[1];
	str1[6] = tmp[5];	
}

bool check(){
	for(int i=1;i<=6;i++) if(str1[i] != str2[i]) return false;
	return true;
}

int main(){
	// freopen("in","r",stdin);
	while(scanf("%s",tmp) == 1){
		for(int i=1;i<=6;i++) str1[i] = tmp[i-1], str2[i] = tmp[5+i];
		str1[7] = str2[7] = 0;

		// 1
		if(check()) goto end;
		cw(); if(check()) goto end;
		cw(); if(check()) goto end;
		cw(); if(check()) goto end;
		cw();

		// 2
		into(); 
		if(check()) goto end;
		cw(); if(check()) goto end;
		cw(); if(check()) goto end;
		cw(); if(check()) goto end;
		cw();
		into();
		into();
		into();

		// 4
		cw();
		into(); 
		if(check()) goto end;
		cw(); if(check()) goto end;
		cw(); if(check()) goto end;
		cw(); if(check()) goto end;
		cw();
		into();
		into();
		into();

		// 5
		cw();
		into(); 
		if(check()) goto end;
		cw(); if(check()) goto end;
		cw(); if(check()) goto end;
		cw(); if(check()) goto end;
		cw();
		into();
		into();
		into();

		// 3
		cw();
		into(); 
		if(check()) goto end;
		cw(); if(check()) goto end;
		cw(); if(check()) goto end;
		cw(); if(check()) goto end;
		cw();
		into();
		into();
		into();

		// 6
		cw();
		into();
		into();
		if(check()) goto end;
		cw(); if(check()) goto end;
		cw(); if(check()) goto end;
		cw(); if(check()) goto end;


		printf("FALSE\n");
		continue;

		end:
		printf("TRUE\n");
	}	
	return 0;
}