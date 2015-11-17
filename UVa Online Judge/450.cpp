#include <cstdio>
#include <string>
#include <cstring>
#include <vector>
#include <algorithm>
using namespace std;

struct user{
	string title,first,last,address,dept,home,work,campus;
	bool operator < (struct user x) const {
		return last < x.last;
	}
}vv;

vector <string> add;
vector <struct user> V;
string S,dept;
char str[200];

int main(){
	// freopen("in","r",stdin);
	int T; scanf("%d",&T);
	fgets(str,sizeof(str),stdin);
	while(T--){
		fgets(str,sizeof str,stdin);
		str[strlen(str)-1] = 0;
		dept = str;

		while(fgets(str,sizeof(str),stdin)){
			if(str[0] == '\n') break;
			char *p = strtok(str,",\n");
			while(p != NULL){
				add.push_back(S = p);
				p = strtok(NULL,",\n");
			}
			vv.title = add[0];
			vv.first = add[1];
			vv.last = add[2];
			vv.address = add[3];
			vv.dept = dept;
			vv.home = add[4];
			vv.work = add[5];
			vv.campus = add[6];
			add.clear();
			V.push_back(vv);
		}
	}

	sort(V.begin(),V.end());
	for(int i=0;i<V.size();i++){
		printf("----------------------------------------\n");
		printf("%s %s %s\n",V[i].title.c_str(),V[i].first.c_str(),V[i].last.c_str());
		printf("%s\n",V[i].address.c_str());
		printf("Department: %s\n",V[i].dept.c_str());
		printf("Home Phone: %s\n",V[i].home.c_str());
		printf("Work Phone: %s\n",V[i].work.c_str());
		printf("Campus Box: %s\n",V[i].campus.c_str());
	}
	return 0;
}