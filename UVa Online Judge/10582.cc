#include <iostream>
#include <cstring>
#include <string>
using namespace std;

typedef pair<int,int> ii;

int R, C, n_answer;
int table[80][80], visited[80][80];
string tmp, raw_table[300];

int readCell(int c_row, int c_col){
    // empty
    if(raw_table[c_row][c_col] == ' ') return 0;
    // top-bottom
    if(raw_table[c_row-1][c_col] == raw_table[c_row+1][c_col] and raw_table[c_row-1][c_col] == '*') return 1;
    // left-right
    if(raw_table[c_row][c_col-1] == raw_table[c_row][c_col+1] and raw_table[c_row][c_col-1] == '*') return 2;
    // top-right
    if(raw_table[c_row-1][c_col] == raw_table[c_row][c_col+1] and raw_table[c_row-1][c_col] == '*') return 3;
    // right-bottom
    if(raw_table[c_row][c_col+1] == raw_table[c_row+1][c_col] and raw_table[c_row][c_col+1] == '*') return 4;
    // bottom-left
    if(raw_table[c_row+1][c_col] == raw_table[c_row][c_col-1] and raw_table[c_row+1][c_col] == '*') return 5;
    // left-top
    if(raw_table[c_row][c_col-1] == raw_table[c_row-1][c_col] and raw_table[c_row][c_col-1] == '*') return 6;
}

ii move(ii curr, ii cell, int cell_type){
    if(cell_type == 1){
        if(curr == ii(cell.first-1, cell.second))      return ii(cell.first+1, cell.second);
        else if(curr == ii(cell.first+1, cell.second)) return ii(cell.first-1, cell.second); 
    }else if(cell_type == 2){
        if(curr == ii(cell.first, cell.second-1))      return ii(cell.first, cell.second+1);
        else if(curr == ii(cell.first, cell.second+1)) return ii(cell.first, cell.second-1);
    }else if(cell_type == 3){
        if(curr == ii(cell.first-1, cell.second))      return ii(cell.first, cell.second+1);
        else if(curr == ii(cell.first, cell.second+1)) return ii(cell.first-1, cell.second);
    }else if(cell_type == 4){
        if(curr == ii(cell.first, cell.second+1))      return ii(cell.first+1, cell.second);
        else if(curr == ii(cell.first+1, cell.second)) return ii(cell.first, cell.second+1);
    }else if(cell_type == 5){
        if(curr == ii(cell.first+1, cell.second))      return ii(cell.first, cell.second-1);
        else if(curr == ii(cell.first, cell.second-1)) return ii(cell.first+1, cell.second);
    }else if(cell_type == 6){
        if(curr == ii(cell.first, cell.second-1))      return ii(cell.first-1, cell.second);
        else if(curr == ii(cell.first-1, cell.second)) return ii(cell.first, cell.second-1);
    }
    return ii(-1, -1);
}

void f(ii curr, ii cell){
    if(cell.first == R and cell.second == C+1){
        n_answer++;
        return;
    }
    if(cell.first == R+1 and cell.second == C){
        n_answer++;
        return;
    }
    if(cell.first > R or cell.second > C or cell.first <= 0 or cell.second <= 0){
        return;
    }
    if(visited[cell.first][cell.second]) return;


    if(1 <= table[cell.first][cell.second] and table[cell.first][cell.second] <= 2){
        for(int i=1;i<=2;i++){
            ii next = move(curr, cell, i);
            if(next.first == -1) continue;
            table[cell.first][cell.second] = i;
            visited[cell.first][cell.second] = true;
            f(cell, next);
            visited[cell.first][cell.second] = false;
        }
    }else if(3 <= table[cell.first][cell.second] and table[cell.first][cell.second] <= 6){
        for(int i=3;i<=6;i++){
            ii next = move(curr, cell, i);
            if(next.first == -1) continue;
            table[cell.first][cell.second] = i;
            visited[cell.first][cell.second] = true;
            f(cell, next);
            visited[cell.first][cell.second] = false;
        }
    }else{
        return ;
    }
}

void run(){
    cin >> R >> C;
    getline(cin, tmp);
    for(int i=0;i<4*R+1;i++) getline(cin, raw_table[i]);
    for(int i=1,raw_i=2;i<=R;i++,raw_i+=4) for(int j=1,raw_j=2;j<=C;j++,raw_j+=4){
        table[i][j] = readCell(raw_i, raw_j);
    }

    n_answer = 0;
    memset(visited, 0, sizeof(visited));
    f(ii(0,1), ii(1,1));
    memset(visited, 0, sizeof(visited));
    f(ii(1,0), ii(1,1));
    cout << "Number of solutions: " << n_answer << endl;

    // for(int i=0;i<4*R+1;i++) cout << "[" << raw_table[i] << "]" << endl;
}

int main(){
    ios::sync_with_stdio(false);
    cin.tie(0);

    int T;
    cin >> T;
    while(T--) run();
    return 0;
}