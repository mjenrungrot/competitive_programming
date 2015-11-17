#include <cstdio>
#include <cstring>
#include <vector>
#include <algorithm>
using namespace std;

struct data{
	data(){}
	data(int code,int note,int m,int b,int t):code(code),note(note),m(m),b(b),t(t){}
	int code,note,m,b,t;
};

int N,pass[3000],n_del;

int main(){
	// freopen("in","r",stdin);
	while(scanf("%d",&N) == 1){
		if(N == -1){
			printf("-1\n");
			break;
		}

		memset(pass,0,sizeof pass);
		n_del = 0;
		vector <struct data> V1;
		for(int i=1;i<=N;i++){
			int code,note,m,b,t;
			scanf("%d %d %d %d %d",&code,&note,&m,&b,&t);

			if(t <= 29) t = 0;
			else if(t <= 89) t = 60;
			else if(t <= 149) t = 120;
			else if(t <= 209) t = 180;
			else if(t <= 269) t = 240;
			else if(t <= 329) t = 300;
			else if(t <= 389) t = 360;
			else if(t <= 449) t = 420;
			else{
				t = 0;
				b++;
				if(b > 4) b = 1, m++;
			}

			V1.push_back(data(code,note,m,b,t));
		}

		for(int i=0;i<V1.size();i++){
			for(int j=i+1;j<V1.size();j++){
				if(V1[i].code == true and V1[j].code == false and V1[i].note == V1[j].note and V1[i].m == V1[j].m and V1[i].b == V1[j].b and V1[i].t == V1[j].t){
					pass[i] = pass[j] = true;
					n_del += 2;
					break;
				}
			}
		}
		printf("%d\n",N-n_del);
		for(int i=0;i<V1.size();i++){
			if(pass[i]) continue;
			printf("%d %d %d %d %d\n",V1[i].code,V1[i].note,V1[i].m,V1[i].b,V1[i].t);
		}
	}
	return 0;
}