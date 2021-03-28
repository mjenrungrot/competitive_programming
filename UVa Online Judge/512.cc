#include <bits/stdc++.h>
using namespace std;

typedef pair<int,int> ii;

ii table[100][100];
int nr, nc, nop, nq, nt;

string operations[1000];
int tmp_n, tmp;
vector <int> operation_params[1000];


int main(){
    while(scanf("%d %d", &nr, &nc) != EOF){
        if(nr == 0 and nc == 0) break;
        for(int i=0;i<100;i++) for(int j=0;j<100;j++) table[i][j] = ii(0,0);
        for(int i=1;i<=nr;i++) for(int j=1;j<=nc;j++){
            table[i][j] = ii(i,j);
        }
        nr = 50;
        nc = 50;

        scanf("%d", &nop);
        for(int i=1;i<=nop;i++){
            cin >> operations[i];
            operation_params[i].clear();
            if(operations[i] != "EX") cin >> tmp_n;
            else tmp_n = 4;
            for(int j=1;j<=tmp_n;j++){
                scanf("%d", &tmp);
                operation_params[i].push_back(tmp);
            }


            if(operations[i] == "DR"){
                sort(operation_params[i].begin(), operation_params[i].end());
                int curr_param = 0;
                for(int ti=1, curr_row=1; ti<=nr; ti++, curr_row++){
                    while(curr_param < operation_params[i].size() and operation_params[i][curr_param] == curr_row) curr_row++, curr_param++;
                    for(int tj=1; tj<=nc; tj++){
                        table[ti][tj] = table[curr_row][tj];
                    }
                }
            }else if(operations[i] == "DC"){
                sort(operation_params[i].begin(), operation_params[i].end());
                int curr_param = 0;
                for(int tj=1, curr_col=1; tj<=nc; tj++, curr_col++){
                    while(curr_param < operation_params[i].size() and operation_params[i][curr_param] == curr_col) curr_col++, curr_param++;
                    for(int ti=1; ti<=nr; ti++){
                        table[ti][tj] = table[ti][curr_col];
                    }
                }
            }else if(operations[i] == "IR"){
                sort(operation_params[i].begin(), operation_params[i].end(), [](int a, int b){ return a > b; });
                int curr_param = 0;
                for(int ti=nr, curr_row=nr-operation_params[i].size(); ti>=0; ti--, curr_row--){
                    if(curr_param < operation_params[i].size() and operation_params[i][curr_param]-1 == curr_row){
                        for(int tj=1; tj<=nc; tj++) table[ti][tj] = ii(-1, -1);
                        curr_param++;
                        curr_row++;
                        continue;
                    }
                    for(int tj=1; tj<=nc; tj++){
                        table[ti][tj] = table[curr_row][tj];
                    }
                }
            }else if(operations[i] == "IC"){
                sort(operation_params[i].begin(), operation_params[i].end(), [](int a, int b){ return a > b; });
                int curr_param = 0;
                for(int tj=nc, curr_col=nc-operation_params[i].size(); tj>=0; tj--, curr_col--){
                    if(curr_param < operation_params[i].size() and operation_params[i][curr_param]-1 == curr_col){
                        for(int ti=1; ti<=nr; ti++) table[ti][tj] = ii(-1, -1);
                        curr_param++;
                        curr_col++;
                        continue;
                    }
                    for(int ti=1; ti<=nr; ti++){
                        table[ti][tj] = table[ti][curr_col];
                    }
                }
            }else if(operations[i] == "EX"){
                ii tmp = table[operation_params[i][0]][operation_params[i][1]];
                table[operation_params[i][0]][operation_params[i][1]] = table[operation_params[i][2]][operation_params[i][3]];
                table[operation_params[i][2]][operation_params[i][3]] = tmp;
            }

            // for(int ti=1;ti<=10;ti++){
            //     for(int tj=1;tj<=10;tj++) printf("[%2d,%2d]", table[ti][tj].first, table[ti][tj].second);
            //     printf("\n");
            // }
            // printf("\n"); 
        }

        map<ii,ii> ans;
        for(int ti=1;ti<=nr;ti++) for(int tj=1;tj<=nc;tj++){
            // printf("adding (%d,%d)\n", table[ti][tj].first, table[ti][tj].second);
            ans[table[ti][tj]] = ii(ti, tj);
        }

        if(nt) printf("\n");
        printf("Spreadsheet #%d\n", ++nt);
        scanf("%d", &nq);

        for(int i=1; i<=nq; i++){
            int r, c;
            scanf("%d %d", &r, &c);
            if(ans.count(ii(r,c))){
                ii new_pos = ans[ii(r,c)];
                printf("Cell data in (%d,%d) moved to (%d,%d)\n", r, c, new_pos.first, new_pos.second);
            }else{
                printf("Cell data in (%d,%d) GONE\n", r, c);
            }
        }
    }
    return 0;
}