#include <bits/stdc++.h>
using namespace std;

int N, M;
vector <int> V[200005];
vector <int> order;
int tick, ticks[200005], dp_forward[200005], dp_backward[200005];
int cycle, n_universal;

void dfs(int u){
    ticks[u] = 1;
    for(auto v: V[u]){
        if(ticks[v] == 0) dfs(v);
        else if(ticks[v] == 1){
            cycle = true;
        }
    }
    ticks[u] = 2;
    order.push_back(u);
}

int main(){
    cin >> N >> M;
    for(int i=1;i<=M;i++){
        int x, y;
        cin >> x >> y;
        V[x].push_back(y);
    }

    for(int i=1;i<=N;i++){
        tick++;
        if(not ticks[i]) dfs(i);
    }
    assert((int)order.size() == N);   
    // for(auto u: order) printf("[%d]", u);

    if(cycle){
        printf("-1");
        return 0;
    }                 

    for(int i=1;i<=N;i++) dp_forward[i] = dp_backward[i] = i;
    
    int u;
    for(int i=0;i<N;i++){
        u = order[i];
        for(auto v: V[u]){
            dp_backward[u] = min(dp_backward[u], dp_backward[v]);
        }

        u = order[N-i-1];
        for(auto v: V[u]){
            dp_forward[v] = min(dp_forward[v], dp_forward[u]);
        }
    }

    for(int i=1;i<=N;i++) if(dp_backward[i] == i and dp_forward[i] == i) n_universal++;
    
    printf("%d\n", n_universal);
    for(int i=1;i<=N;i++){
        if(dp_backward[i] == i and dp_forward[i] == i) printf("A");
        else printf("E");
    }
    printf("\n");
    return 0;
}