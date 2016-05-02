#include <cstdio>
#include <cstring>
#include <string>
#include <map>
using namespace std;

int N; 
char str[1050];

map < pair<int,int>, string> MM;

string f(int l, int r){
	if(MM.count(pair<int,int>(l,r))){
		return MM[pair<int,int>(l,r)];
	}

	if(l == r){
		// printf("%c",str[l]);
		string x;
		x += str[l];
		return x;
	}
	if(l > r) return "";

	int vv = 0, vv_idx = 0;
	for(int i=l;i<=r;i++){
		if(str[i] > vv){
			vv = str[i];
			vv_idx = i;
		}
	}
	// printf("%c",vv);
	string ans = "";
	for(int i=l;i<=r;i++){
		if(str[i] == vv){
			string tmp;
			tmp += vv;
			tmp += f(l, i - 1);
			for(int j=i+1;j<=r;j++) tmp += str[j];
			if(tmp > ans or ans == ""){
				ans = tmp;
			}
		}
	}
	MM[pair<int,int>(l,r)] = ans;
	return ans;
}

void run(){
	scanf("%s",&str[1]);
	MM.clear();
	N = strlen(&str[1]);
	string ans = f(1,N);
	printf("%s",ans.c_str());
	printf("\n");
}

int main(){
	freopen("A-large.in","r",stdin);
	freopen("A-large.out","w",stdout);
	int NN;
	scanf("%d",&NN);
	for(int _i=1;_i<=NN;_i++){
		printf("Case #%d: ",_i);
		run();
	}
	return 0;
}