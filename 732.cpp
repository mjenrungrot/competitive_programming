#include <cstdio>
#include <stack>
#include <string>
#include <cassert>
#include <vector>
#include <algorithm>
#include <iostream>
using namespace std;

string S1,S2;
vector <string> ans;

string print(stack <char> S){
	string ss = "";
	while(!S.empty()){
		ss += S.top();
		S.pop();
	}
	return ss;
}
void f(string now,stack <char> S, int id1,int id2){
	// printf("[%s] %s\n",now.c_str(),print(S).c_str());
	if(id1 == S1.length()){
		if(id2 == S2.length()){
			ans.push_back(now);
			return ;
		}else{
			if(!S.empty() and S.top() == S2[id2]){
				S.pop();
				f(now+"o",S,id1,id2+1);
			}
		}
	}else{
		S.push(S1[id1]);
		f(now+"i",S,id1+1,id2);	
		S.pop();
		if(!S.empty() and S.top() == S2[id2]){
			S.pop();
			f(now+"o",S,id1,id2+1);
		}
	}
}

int main(){
	// freopen("in","r",stdin);
	while(cin >> S1 >> S2){
		ans.clear();
		if(S1.size() == S2.size()){
			string now = "";
			stack <char> S;
			f("",S,0,0);
		}
		sort(ans.begin(),ans.end());
		printf("[\n");
		for(int i=0;i<ans.size();i++){
			for(int j=0;j<ans[i].length();j++){
				if(j) printf(" ");
				printf("%c",ans[i][j]);
			}
			printf("\n");
		}
		printf("]\n");
	}
	return 0;
}