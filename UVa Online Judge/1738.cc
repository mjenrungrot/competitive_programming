#include <iostream>
#include <cstdlib> 
#include <vector>
using namespace std;

struct node {
    int val;
    struct node *left, *right;
};

int N, K;
struct node *root[100];

void add(struct node *&u, int val){
    if(u == NULL){
        u = (struct node*)malloc(sizeof(struct node));
        u->val = val;
        u->left = NULL;
        u->right = NULL;
        return;
    }

    if(val < (u->val)) add(u->left, val);
    else               add(u->right, val);
}

bool same(struct node *root1, struct node *root2){
    if(root1 == NULL xor root2 == NULL) return false;
    if(root1 == NULL and root2 == NULL) return true;
    if(same(root1->left, root2->left)) return same(root1->right, root2->right);
    return false;
}

int main(){
    ios::sync_with_stdio(false);
    cin.tie(0);

    while(cin >> N >> K){
        for(int i=1;i<=N;i++){
            root[i] = NULL;
            for(int j=1;j<=K;j++){
                int tmp;
                cin >> tmp;
                add(root[i], tmp);
            }
        }

        int ans = 0;
        for(int i=1;i<=N;i++){
            bool found = false;
            for(int j=1;j<i;j++){
                if(same(root[i], root[j])){
                    found = true;
                    break;
                }   
            }
            if(not found) ans++;
        }
        cout << ans << endl;
    }
    return 0;
}