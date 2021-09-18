/*=============================================================================
#  Author:          Teerapat Jenrungrot - https://github.com/mjenrungrot/
#  FileName:        230.cpp
#  Description:     UVa Online Judge - 230
=============================================================================*/
#include <algorithm>
#include <cstdio>
#include <cstring>
#include <string>
#include <vector>
using namespace std;
char str[200];

struct book {
    book() {}
    book(string author, string title) : author(author), title(title) {}
    string author, title;

    bool operator<(struct book x) const {
        if (author != x.author) return author < x.author;
        return title < x.title;
    }
};

vector<book> V, Q;
vector<int> available;
string S;

book f() {
    book answer("", "");

    bool type = 1;
    for (int i = 1; str[i]; i++) {
        if (type) {
            if (str[i] == '\"') {
                type = false;
                i += 4;
                continue;
            }
            answer.title += str[i];
        } else {
            if (str[i] == '\n') break;
            answer.author += str[i];
        }
    }
    return answer;
}

int main() {
    // freopen("in","r",stdin);
    // freopen("out","w",stdout);
    while (fgets(str, sizeof(str), stdin)) {
        if (strcmp(str, "END\n") == 0) break;
        V.push_back(f());
        available.push_back(true);
    }
    sort(V.begin(), V.end());

    while (scanf("%s ", str) == 1) {
        if (strcmp(str, "END") == 0) break;
        if (strcmp(str, "BORROW") == 0) {
            fgets(str, sizeof(str), stdin);
            book xx = f();
            for (int i = 0; i < V.size(); i++) {
                if (V[i].title == xx.title) {
                    available[i] = false;
                    break;
                }
            }
        } else if (strcmp(str, "RETURN") == 0) {
            fgets(str, sizeof(str), stdin);
            book xx = f();
            for (int i = 0; i < V.size(); i++)
                if (xx.title == V[i].title) {
                    xx.author = V[i].author;
                    break;
                }
            Q.push_back(xx);
        } else if (strcmp(str, "SHELVE") == 0) {
            sort(Q.begin(), Q.end());
            for (int i = 0; i < Q.size(); i++) {
                for (int j = 0; j < V.size(); j++) {
                    if (V[j].title == Q[i].title) {
                        bool found = false;
                        for (int k = j - 1; k >= 0; k--)
                            if (available[k]) {
                                found = true;
                                printf("Put \"%s\" after \"%s\"\n",
                                       Q[i].title.c_str(), V[k].title.c_str());
                                break;
                            }
                        if (not found)
                            printf("Put \"%s\" first\n", Q[i].title.c_str());
                        available[j] = true;
                        break;
                    }
                }
            }
            Q.clear();
            printf("END\n");
        }
    }
    return 0;
}