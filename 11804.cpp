#include <cstdio>
#include <vector>
#include <cstring>
#include <string>
#include <algorithm>
using namespace std;

char name[20][50],earliest[50],tmp[50];
int A[20],B[20];

int cmp(vector <string> V1, vector <string> V2){
	for(int i=0;i<5;i++){
		if(V1[i] == V2[i]) continue;
		else if(V1[i] > V2[i]) return 1;
		else if(V1[i] < V2[i]) return -1;
	}
	return 0;
}

int main(){
	// freopen("in","r",stdin);
	int T,test = 0;
	scanf("%d",&T);
	while(T--){
		printf("Case %d:\n",++test);

		int sumB = 0;
		for(int i=1;i<=10;i++){
			scanf("%s %d %d",name[i],&A[i],&B[i]);
			sumB += B[i];
		}

		vector <string> tmpV;
		vector <string> V;

		int max_attack = 0, max_defend = 0,v1,v2,v3,v4,v5;
		for(int i=1;i<=6;i++) for(int j=i+1;j<=7;j++) for(int k=j+1;k<=8;k++) for(int m=k+1;m<=9;m++) for(int n=m+1;n<=10;n++){
			int sum1 = A[i] + A[j] + A[k] + A[m] + A[n];
			int sum2 = sumB - (B[i] + B[j] + B[k] + B[m] + B[n]);

			tmpV.clear();
			tmpV.push_back(name[i]);
			tmpV.push_back(name[j]);
			tmpV.push_back(name[k]);
			tmpV.push_back(name[m]);
			tmpV.push_back(name[n]);
			sort(tmpV.begin(),tmpV.end());
			
			if(sum1 > max_attack){
				max_attack = sum1;
				max_defend = sum2;
				V = tmpV;
				v1 = i, v2 = j, v3 = k, v4 = m, v5 = n;
			}else if(sum1 == max_attack and sum2 > max_defend){
				max_attack = sum1;
				max_defend = sum2;
				V = tmpV;
				v1 = i, v2 = j, v3 = k, v4 = m, v5 = n;
			}else if(sum1 == max_attack and sum2 == max_defend and cmp(tmpV,V) < 0){
				max_attack = sum1;
				max_defend = sum2;
				V = tmpV;
				v1 = i, v2 = j, v3 = k, v4 = m, v5 = n;
			}
		}

		printf("(");
		for(int i=0;i<(int)V.size();i++){
			if(i) printf(", ");
			printf("%s",V[i].c_str());
		}
		printf(")\n(");

		V.clear();
		for(int i=1;i<=10;i++) if(i != v1 and i != v2 and i != v3 and i != v4 and i != v5) V.push_back(name[i]);
	 	sort(V.begin(),V.end());
	 	for(int i=0;i<(int)V.size();i++){
			if(i) printf(", ");
			printf("%s",V[i].c_str());
		}
		printf(")\n");
	}
	return 0;
}