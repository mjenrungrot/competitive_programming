#include <bits/stdc++.h>
using namespace std;

struct data{
    string name;
    int t;
    int base_t;
    int priority;

    data(){}
    data(string name, int t, int base_t, int priority): name(name), t(t), base_t(base_t), priority(priority){}
};

bool operator>(const data& a, const data& b) {
    if(a.t != b.t) return a.t > b.t;
    else return a.priority > b.priority;
}

int N, K;

int main(){
    int T; scanf("%d", &T);
    while(T--){
        priority_queue <data, vector<data>, greater<data> > pq;
        scanf("%d %d", &N, &K);

        string x;
        int t;
        for(int i=1;i<=N;i++){
            cin >> x >> t;
            pq.push(data(x, t, t, i));
        }

        for(int i=1;i<=K;i++){
            data top = pq.top(); 
            pq.pop();
            printf("%d %s\n", top.t, top.name.c_str());
            pq.push(data(top.name, top.t + top.base_t, top.base_t, top.priority));
        }
    }
    return 0;
}