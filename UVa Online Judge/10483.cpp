#include <cstdio>
#include <vector>
using namespace std;

struct data{
	data(){}
	data(int a,int b,int c):a(a),b(b),c(c){}
	int a,b,c;
};

vector <struct data> ans[30000];

int get(){
	int x,y;
	scanf("%d.%d",&x,&y);
	return 100*x + y;
}

void gen(){
	for(int i=1;i<=25599;i++) for(int j=25599;j>=i;j--){
		if(i + j > 25599) continue;
		if(i * j > 2559900) continue;

		int v1 = (i+j) * 10000;
		int v2 = (i*j) - 10000;
		if(v2 <= 0) break;
		if(v1 % v2) continue;
		int k = v1/v2;
		if(i+j+k < 25600 and k >= j){
			ans[i+j+k].push_back(data(i,j,k));
		}
	}
}

int main(){
	// freopen("in","r",stdin);
	gen();

	int v1,v2;
	v1 = get();
	v2 = get();
	for(int i=v1;i<=v2;i++) for(int j=0;j<(int)ans[i].size();j++){
		printf("%d.%02d = %d.%02d + %d.%02d + %d.%02d = %d.%02d * %d.%02d * %d.%02d\n",i/100,i%100,ans[i][j].a/100,ans[i][j].a%100,ans[i][j].b/100,ans[i][j].b%100,ans[i][j].c/100,ans[i][j].c%100,ans[i][j].a/100,ans[i][j].a%100,ans[i][j].b/100,ans[i][j].b%100,ans[i][j].c/100,ans[i][j].c%100);
	}
	return 0;
}