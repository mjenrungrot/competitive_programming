#include <cstdio>
#include <cstring>
#include <cmath>
#include <algorithm>
using namespace std;

const long long INF = 1e19;

char str1[20], tmp1[20];
char str2[20], tmp2[20];;
int len1,len2;

long long best1, best2, min_dist;
long long val1, val2;

char best_tmp1[20],best_tmp2[20];

long long abs(long long x){ return x < 0 ? -x: x;}

void f(int idx, int kuy){
	if(idx == len1){
		val1 = 0LL;
		val2 = 0LL;
		for(int i=0;i<len1;i++){
			val1 *= 10LL;
			val1 += tmp1[i] - '0';

			val2 *= 10LL;
			val2 += tmp2[i] - '0';
		}

		// printf("=> %lld %lld\n",val1,val2);

		if(abs(val1 - val2) < min_dist){
			min_dist = abs(val1 - val2);
			best1 = val1;
			best2 = val2;

			for(int i=0;i<len1;i++){
				best_tmp1[i] = tmp1[i];
				best_tmp2[i] = tmp2[i];
			}
		}else if(abs(val1 - val2) == min_dist and val1 < best1){
			best1 = val1;
			best2 = val2;

			for(int i=0;i<len1;i++){
				best_tmp1[i] = tmp1[i];
				best_tmp2[i] = tmp2[i];
			}
		}else if(abs(val1 - val2) == min_dist and val1 == best1 and val2 < best2){
			best2 = val2;
			for(int i=0;i<len1;i++){
				// best_tmp1[i] = tmp1[i];
				best_tmp2[i] = tmp2[i];
			}
		}
		return ;
	}

	if(kuy == 0){
		// undecided
		if(str1[idx] == '?' and str2[idx] == '?'){
			if(idx + 1 < len1 and str1[idx + 1] == '?' and str2[idx + 1] == '?'){
				tmp1[idx] = '0';
				tmp2[idx] = '0';
				f(idx+1, kuy);
			}else{
				// 3 subcases
				//  ????x[.....]
				//  ????x[.....]
				// printf("Case 1\n");
				tmp1[idx] = '0';
				tmp2[idx] = '0';
				f(idx+1, kuy);

				// printf("Case 2\n");
				tmp1[idx] = '0';
				tmp2[idx] = '1';
				f(idx+1, 2);


				// printf("Case 3\n");
				tmp1[idx] = '1';
				tmp2[idx] = '0';
				f(idx+1, 1);
			}
		}
		else if(str1[idx] == '?' and str2[idx] != '?'){
			// printf("Hello 1\n");
			tmp2[idx] = str2[idx];
			tmp1[idx] = tmp2[idx];
			f(idx+1, kuy);

			if(str2[idx] - 1 >= '0'){
				tmp2[idx] = str2[idx];
				tmp1[idx] = tmp2[idx] - 1;
				f(idx+1, 2);
			}

			if(str2[idx] + 1 <= '9'){
				tmp2[idx] = str2[idx];
				tmp1[idx] = tmp2[idx] + 1;
				f(idx+1, 1);
			}

		}else if(str1[idx] != '?' and str2[idx] == '?'){
			// printf("Hello 2\n");
			tmp1[idx] = str1[idx];
			tmp2[idx] = tmp1[idx]; 
			f(idx+1, kuy);


			if(str1[idx] - 1 >= '0'){
				tmp1[idx] = str1[idx];
				tmp2[idx] = tmp1[idx] - 1;
				f(idx+1, 1);
			}

			if(str1[idx] + 1 <= '9'){
				tmp1[idx] = str1[idx];
				tmp2[idx] = tmp1[idx] + 1;
				f(idx+1, 2);
			}
		}
		else{
			if(str1[idx] > str2[idx]){
				tmp1[idx] = str1[idx];
				tmp2[idx] = str2[idx];
				// printf("sub 1.1\n");
				f(idx+1, 1);
			}else if(str1[idx] < str2[idx]){
				tmp1[idx] = str1[idx];
				tmp2[idx] = str2[idx];
				// printf("sub 1.2\n");
				f(idx+1, 2);
			}else{
				tmp1[idx] = str1[idx];
				tmp2[idx] = str2[idx];
				// printf("sub 1.3\n");
				f(idx+1, kuy);
			}
		}
	}else if(kuy == 1){
		// 1 . .. .   . .
		// 0 .. . . . . . 
		for(int i=idx;i<len1;i++){
			if(str1[i] == '?' and str2[i] == '?'){
				tmp1[i] = '0';
				tmp2[i] = '9';
			}else if(str1[i] == '?'){
				tmp1[i] = '0';
				tmp2[i] = str2[i];
			}else if(str2[i] == '?'){
				tmp1[i] = str1[i];;
				tmp2[i] = '9';
			}else{
				tmp1[i] = str1[i];
				tmp2[i] = str2[i];
			}
		}
		f(len1, kuy);
	}else if(kuy == 2){
		// 0 . .. .   . .
		// 1 .. . . . . . 
		for(int i=idx;i<len1;i++){
			if(str1[i] == '?' and str2[i] == '?'){
				tmp1[i] = '9';
				tmp2[i] = '0';
			}else if(str1[i] == '?'){
				tmp1[i] = '9';
				tmp2[i] = str2[i];
			}else if(str2[i] == '?'){
				tmp1[i] = str1[i];;
				tmp2[i] = '0';
			}else{
				tmp1[i] = str1[i];
				tmp2[i] = str2[i];
			}
		}
		f(len1, kuy);

	}

}

void run(){
	scanf("%s %s",str1,str2);
	len1 = strlen(str1);
	len2 = strlen(str2);

	// for(int i=0;i<len1;i++){
	// 	if(str1[i] == '?' and str2[i] != '?'){
	// 		str1[i] = str2[i];
	// 	}else if(str1[i] != '?' and str2[i] == '?'){
	// 		str2[i] = str1[i];
	// 	}
	// }
	// printf("%s %s\n",str1, str2);

	min_dist = INF;
	f(0, 0);

	// printf(" %lld %lld\n",best1, best2);

	printf(" ");
	for(int i=0;i<len1;i++) printf("%c",best_tmp1[i]);

	printf(" ");
	for(int i=0;i<len1;i++) printf("%c",best_tmp2[i]);
	printf("\n");
}


int main(){
	// freopen("kuy.in","r",stdin);
	freopen("B-large.in","r",stdin);
	freopen("B-large.out","w",stdout);
	int T;
	scanf("%d",&T);
	for(int i=1;i<=T;i++){
		printf("Case #%d:",i);
		run();
	}
	return 0;
}