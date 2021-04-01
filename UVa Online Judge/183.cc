#include <iostream>
#include <iomanip>
#include <string>
#include <vector>
#include <sstream>
using namespace std;

const int STEP_SIZE = 50;

int to_pos(int rr, int cc, int R, int C){
    return rr * C + cc;
}

string decompose(string encoding, int R, int C){
    bool check0 = true, check1 = true;
    for(int i=0;i<encoding.length();i++){
        if(encoding[i] == '0') check1 = false;
        if(encoding[i] == '1') check0 = false;
        if(!check0 and !check1) break;
    }

    string output = "";
    if(check0){
        output.push_back('0');
        return output;
    }
    if(check1){
        output.push_back('1');
        return output;
    }

    output.push_back('D');

    string top_left, top_right, bottom_left, bottom_right;
    for(int rr=0;rr<(R+1)/2;rr++) for(int cc=0;cc<(C+1)/2;cc++) top_left += encoding[to_pos(rr, cc, R, C)];
    output += decompose(top_left, (R+1)/2, (C+1)/2);

    for(int rr=0;rr<(R+1)/2;rr++) for(int cc=(C+1)/2;cc<C;cc++) top_right += encoding[to_pos(rr, cc, R, C)];
    if(C>1) output += decompose(top_right, (R+1)/2, C-(C+1)/2);

    for(int rr=(R+1)/2;rr<R;rr++) for(int cc=0;cc<(C+1)/2;cc++) bottom_left += encoding[to_pos(rr, cc, R, C)];
    if(R>1) output += decompose(bottom_left, R-(R+1)/2, (C+1)/2);

    for(int rr=(R+1)/2;rr<R;rr++) for(int cc=(C+1)/2;cc<C;cc++) bottom_right += encoding[to_pos(rr, cc, R, C)];
    if(R>1 and C>1) output += decompose(bottom_right, R-(R+1)/2, C-(C+1)/2);

    return output;
}

int expand(string &encoding, int idx, int currR, int endR, int currC, int endC, vector< vector<char> > &table){
    if(encoding[idx] == 'D'){
        int nextidx = idx+1;
        nextidx = expand(encoding, nextidx, currR, (currR+endR)/2, currC, (currC+endC)/2, table); // topleft
        if(endC > currC) nextidx = expand(encoding, nextidx, currR, (currR+endR)/2, (currC+endC)/2+1, endC, table);
        if(endR > currR) nextidx = expand(encoding, nextidx, (currR+endR)/2+1, endR, currC, (currC+endC)/2, table); 
        if(endR > currR and endC > currC) nextidx = expand(encoding, nextidx, (currR+endR)/2+1, endR, (currC+endC)/2+1, endC, table);
        return nextidx;
    }else if(encoding[idx] == '0'){
        for(int r=currR; r<=endR; r++) for(int c=currC; c<=endC; c++) table[r][c] = '0';
        return idx+1;
    }else if(encoding[idx] == '1'){
        for(int r=currR; r<=endR; r++) for(int c=currC; c<=endC; c++) table[r][c] = '1';
        return idx+1;
    }
    return idx;
}

int main(){
    ios::sync_with_stdio(false);
    cin.tie(0);

    string type;
    string tmp;
    int R, C;
    cin >> type;
    if(type == "#") return 0;;
    cin >> R >> C;
    getline(cin, tmp);
    while(true){
        string encoding = "";
        while(true){
            getline(cin, tmp);
            if(tmp[0] == '#' or tmp[1] == ' ') break;
            encoding += tmp;
        }
        string output = "";
        if(type == "B"){
            cout << "D" << setw(4) << R << setw(4) << C << endl;
            output = decompose(encoding, R, C);
        }else{
            vector< vector<char> > table;
            for(int i=0;i<R;i++){
                vector<char> tmp;
                for(int j=0;j<C;j++) tmp.push_back('?');
                table.push_back(tmp);
            }

            cout << "B" << setw(4) << R << setw(4) << C << endl;
            expand(encoding, 0, 0, R-1, 0, C-1, table);

            for(int i=0;i<R;i++) for(int j=0;j<C;j++) output += table[i][j];
        }

        for(int curr=0; curr<output.length(); curr+=STEP_SIZE){
            for(int i=curr; i<min(curr+STEP_SIZE, (int)output.length()); i++) cout << output[i];
            cout << endl;
        }

        istringstream iss(tmp);
        iss >> type;
        if(type == "#") break;
        iss >> R >> C;
    }
    return 0;
}