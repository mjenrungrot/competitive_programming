#include <cstdio>
#include <cstring>
#include <string>
#include <vector>
#include <stack>
using namespace std;

char s[6000];
int len;

int priority(char xx){
	if(xx == '+') return 1;
	if(xx == '*') return 2;
	if(xx == '(') return 0;
	return -1;
}

string conv(string ss){
	string ans = "";
	stack <char> S;
	for(int i=0;i<ss.length();i++){
		if(ss[i] >= '0' and s[i] <= '9') ans += ss[i];
		else if(ss[i] == '+' or ss[i] == '*'){
			while(!S.empty() and priority(ss[i]) <= priority(S.top())){
				ans += S.top();
				S.pop();
			}
			S.push(ss[i]);
		}else if(ss[i] == '('){
			S.push(ss[i]);
		}else if(ss[i] == ')'){
			while(!S.empty() and S.top() != '('){
				ans += S.top();
				S.pop();
			}
			S.pop();
		}
	}
	while(!S.empty()){
		ans += S.top();
		S.pop();
	}
	return ans;
}
long long f(string ss){
	stack <long long> S;
	for(int i=0;i<ss.length();i++){
		if(ss[i] >= '0' and ss[i] <= '9'){
			S.push(ss[i] - '0');
			// printf("push [%lld]\n",S.top());
		}else if(ss[i] == '+' or ss[i] == '*'){
			long long s2 = S.top(); S.pop();
			long long s1 = S.top(); S.pop();
			if(ss[i] == '+') S.push(s1+s2);
			else S.push(s1*s2);
			// printf("push [%lld]\n",S.top());
		}
	}
	return S.top();
}	

long long findans(){
	vector <int> V;
	for(int i=0;s[i]!=0;i++) if(s[i] == '*') V.push_back(i);

	long long ans = 0LL;
	for(int i=0;i<V.size();i++) for(int j=i+1;j<V.size();j++){
		// a[0]..a[V[i]-1]*(a[V[i]+1]...a[V[j]-1])*a[V[j]+1]...a[len-1]
		string ss = "";
		for(int k=0;k<=V[i]-1;k++) ss += s[k];
		ss += "*(";
		for(int k=V[i]+1;k<=V[j]-1;k++) ss += s[k];
		ss += ")*";
		for(int k=V[j]+1;k<=len-1;k++) ss += s[k];

		// printf("[%s] = %d [%s]\n",ss.c_str(),f(conv(ss)),conv(ss).c_str());
		ans = max(ans,f(conv(ss)));
	}
	return ans;
}

int main(){
	// freopen("in","r",stdin);
	scanf("%s",&s[2]);
	s[0] = '1';
	s[1] = '*';
	len = strlen(s);
	s[len] = '*';
	s[len+1] = '1';
	len += 2;
	printf("%lld\n",findans());
	return 0;
}