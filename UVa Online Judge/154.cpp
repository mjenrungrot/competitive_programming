#include <cstdio>
#include <cstring>
#include <vector>
using namespace std;

char str[100];
vector <char> V[10000];

vector <char> parse(){
	vector <char> ans;
	for(int k=1;k<=5;k++){
		for(int i=1;i<=5 and (int)ans.size() < k;i++){
			int pos1 = 0 + (i-1)*4;
			int pos2 = 2 + (i-1)*4;

			if(k == 1 and str[pos2] == 'P') ans.push_back(str[pos1]);
			if(k == 2 and str[pos2] == 'G') ans.push_back(str[pos1]);
			if(k == 3 and str[pos2] == 'A') ans.push_back(str[pos1]);
			if(k == 4 and str[pos2] == 'S') ans.push_back(str[pos1]);
			if(k == 5 and str[pos2] == 'N') ans.push_back(str[pos1]);
		}
	}
	return ans;
}

int change(vector <char> cc, vector <char> original){
	int ans = 0;
	for(int i=0;i<5;i++) if(cc[i] != original[i]) ans++;
	return ans;
}


int main(){
	// freopen("in","r",stdin);
	while(true){
		int counter = 0;
		while(scanf("%s",str) == 1){
			if(str[0] == '#') goto end;
			if(str[0] == 'e') break;
			V[++counter] = parse();
		}

		int min_change = 1e9,minidx = 1;
		for(int i=1;i<=counter;i++){
			int tmp = 0;
			for(int j=1;j<=counter;j++){
				if(j == i) continue;
				tmp += change(V[j],V[i]);
			}
			if(tmp < min_change){
				min_change = tmp;
				minidx = i;
			}
		}
		printf("%d\n",minidx);
	}
	end:
	return 0;
}