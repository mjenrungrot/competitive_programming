/*=============================================================================
#  Author:          Teerapat Jenrungrot - https://github.com/mjenrungrot/
#  FileName:        10388.cc
#  Description:     UVa Online Judge - 10388
=============================================================================*/
#include <cstdio>
#include <cstdlib>
#include <cstring>
#include <deque>
using namespace std;

char stackJane[1000], stackJohn[1000];
int nJane, nJohn;

bool snap() { return random() / 141 % 2; }

int main() {
    int T;
    scanf("%d", &T);
    for (int _i = 1; _i <= T; _i++) {
        if (_i > 1) printf("\n");

        deque<char> face_up_jane, face_down_jane, face_up_john, face_down_john;
        scanf("%s", &stackJane[1]);
        scanf("%s", &stackJohn[1]);
        nJane = strlen(&stackJane[1]);
        for (int j = 1; j <= nJane; j++) {
            face_down_jane.push_back(stackJane[j]);
            face_down_john.push_back(stackJohn[j]);
        }

        bool finished = false;
        for (int j = 1; j <= 1000; j++) {
            if (face_down_jane.empty()) {
                for (int k = (int)face_up_jane.size() - 1; k >= 0; k--) {
                    face_down_jane.push_back(face_up_jane[k]);
                }
                face_up_jane.clear();
            }
            if (face_down_john.empty()) {
                for (int k = (int)face_up_john.size() - 1; k >= 0; k--) {
                    face_down_john.push_back(face_up_john[k]);
                }
                face_up_john.clear();
            }

            // printf("Step %d\n", j);
            // printf("Jane:\n");
            // printf("\tFace-down=> ");
            // for(int k=0;k<(int)face_down_jane.size();k++) printf("%c",
            // face_down_jane[k]); printf("\tFace-up=> "); for(int
            // k=0;k<(int)face_up_jane.size();k++) printf("%c",
            // face_up_jane[k]); printf("\n"); printf("John:\n");
            // printf("\tFace-down=> ");
            // for(int k=0;k<(int)face_down_john.size();k++) printf("%c",
            // face_down_john[k]); printf("\tFace-up=> "); for(int
            // k=0;k<(int)face_up_john.size();k++) printf("%c",
            // face_up_john[k]); printf("\n");

            // place card
            face_up_jane.push_front(face_down_jane[0]);
            face_down_jane.pop_front();
            face_up_john.push_front(face_down_john[0]);
            face_down_john.pop_front();

            // check snap
            if (face_up_jane[0] == face_up_john[0]) {
                if (snap() == 0) {
                    // jane
                    for (int k = face_up_john.size() - 1; k >= 0; k--) {
                        face_up_jane.push_front(face_up_john[k]);
                    }
                    face_up_john.clear();

                    printf("Snap! for Jane: ");
                    for (int k = 0; k < (int)face_up_jane.size(); k++)
                        printf("%c", face_up_jane[k]);
                    printf("\n");
                } else {
                    //  john
                    for (int k = (int)face_up_jane.size() - 1; k >= 0; k--) {
                        face_up_john.push_front(face_up_jane[k]);
                    }
                    face_up_jane.clear();

                    printf("Snap! for John: ");
                    for (int k = 0; k < (int)face_up_john.size(); k++)
                        printf("%c", face_up_john[k]);
                    printf("\n");
                }
            }

            // check win condition
            if (face_down_jane.empty() and face_up_jane.empty()) {
                printf("John wins.\n");
                finished = true;
                break;
            }
            if (face_down_john.empty() and face_up_john.empty()) {
                printf("Jane wins.\n");
                finished = true;
                break;
            }
        }

        if (not finished) {
            printf("Keeps going and going ...\n");
        }
    }
    return 0;
}