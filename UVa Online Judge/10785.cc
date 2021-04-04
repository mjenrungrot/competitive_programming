#include <iostream>
#include <vector>
#include <string>
#include <algorithm>
using namespace std;

string vowels = "AUEOI";
string consonants = "JSBKTCLDMVNWFXGPYHQZR";

int main(){
    ios::sync_with_stdio(false);
    cin.tie(0);

    int T;
    cin >> T;
    for(int tt=1;tt<=T;tt++){
        int N;
        cin >> N;

        cout << "Case " << tt << ": ";
        string vowels_toprint = "";
        string consonants_toprint = "";
        for(int i=1;i<=N;i++){
            if(i&1) vowels_toprint += vowels[(i-1)/2/21];
            else consonants_toprint += consonants[(i-1)/2/5];
        }
        sort(vowels_toprint.begin(), vowels_toprint.end());
        sort(consonants_toprint.begin(), consonants_toprint.end());

        for(int i=1;i<=N;i++){
            if(i&1) cout << vowels_toprint[(i-1)/2];
            else    cout << consonants_toprint[(i-1)/2];
        }
        cout << endl;
    }

    return 0;
}