#include <bits/stdc++.h>
using namespace std;

const int N = 4;
int perm[4];
string lines[4];

int main(){
    ios::sync_with_stdio(false);


    while(cin >> lines[0]){
        if(lines[0] == "Q") break;
        cin >> lines[1] >> lines[2] >> lines[3];
        for(int i=0;i<N;i++) perm[i] = i;

        int ans = 0;
        do{
            // 0-top 1-left 2-right 3-bottom
            for(int tl0=1;tl0<lines[perm[0]].length()-1;tl0++) for(int tl1=1;tl1<lines[perm[1]].length()-1;tl1++){
                if(lines[perm[0]][tl0] != lines[perm[1]][tl1]) continue;
                for(int tr0=tl0+1;tr0<lines[perm[0]].length()-1;tr0++) for(int tr2=1;tr2<lines[perm[2]].length()-1;tr2++){
                    if(lines[perm[0]][tr0] != lines[perm[2]][tr2]) continue;
                    for(int bl1=tl1+1;bl1<lines[perm[1]].length()-1;bl1++) for(int bl3=1;bl3<lines[perm[3]].length()-1;bl3++){
                        if(lines[perm[1]][bl1] != lines[perm[3]][bl3]) continue;
                        int width = tr0-tl0;
                        int height = bl1-tl1;
                        int br2 = tr2 + height;
                        int br3 = bl3 + width;
                        if(br2 >= lines[perm[2]].length()-1) continue;
                        if(br3 >= lines[perm[3]].length()-1) continue;
                        if(lines[perm[2]][br2] != lines[perm[3]][br3]) continue;

                        int rect = (width-1) * (height-1);
                        ans = max(ans, rect);
                    }
                }
            }
        }while(next_permutation(perm, perm+N));
        cout << ans << endl;
    }
    return 0;
}