#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

int main(){
    ios::sync_with_stdio(false);
    cin.tie(0);

    int T, n_case = 0;
    cin >> T;
    while(T--){
        int N, M;
        cin >> N >> M;

        if(N == 0){
            cout << "Case #" << ++n_case << ": 0" << endl;
            cout << endl;
            for(int i=1;i<=M;i++){
                int u, v;
                cin >> u >> v;
            }
            continue;
        }

        vector < vector<int> > V(N+5), other_V(N+5), original(N+5, vector<int>(N+5, 0));
        vector <int> gone(N+5), ans;

        for(int i=1;i<=M;i++){
            int u, v;
            cin >> u >> v;
            V[u].push_back(v);
            V[v].push_back(u);
            original[u][v]++;
            original[v][u]++;
        }

        bool possible = false;
        for(int t=1;t<=N;t++){
            int n_pairs = 0;
            int n_other_pairs = 0;
            for(int u=1;u<=N;u++){
                if(gone[u]){
                    n_other_pairs += other_V[u].size();
                }else{
                    n_pairs += V[u].size();
                }
            }
            n_pairs /= 2;
            n_other_pairs /= 2;

            if(n_pairs + n_other_pairs <= M/2){
                possible = true;
                break;
            }

            int max_degree = -1;
            int max_degree_node = -1;
            for(int u=1;u<=N;u++){
                if(gone[u]) continue;
                if((int)V[u].size() > max_degree){
                    max_degree = V[u].size();
                    max_degree_node = u;
                }
            }

            // remove max_degree_node
            for(int u=1;u<=N;u++){
                if(gone[u]) continue;
                if(u == max_degree_node) continue;
                auto pos = find(V[u].begin(), V[u].end(), max_degree_node);
                if(pos != V[u].end()){
                    V[u].erase(pos);
                }
            }
            
            V[max_degree_node].clear();
            gone[max_degree_node] = true;
            for(int v=1;v<=N;v++){
                if(original[max_degree_node][v] and gone[v]){
                    other_V[max_degree_node].push_back(v);
                    other_V[v].push_back(max_degree_node);
                }
            }
            ans.push_back(max_degree_node);
        }

        if(possible){
            cout << "Case #" << ++n_case << ": " << ans.size() << endl;
            bool space = false;
            for(auto node: ans){
                if(space) cout << " ";
                space = true;
                cout << node;
            }
            cout << endl;
        }else{
            cout << "Case #" << ++n_case << ": Impossible." << endl;
            cout << endl;
        }
    }
    return 0;
}