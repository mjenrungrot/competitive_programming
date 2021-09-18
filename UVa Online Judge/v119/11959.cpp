/*=============================================================================
#  Author:          Teerapat Jenrungrot - https://github.com/mjenrungrot/
#  FileName:        11959.cpp
#  Description:     UVa Online Judge - 11959
=============================================================================*/
#include <cstdio>

/*
1 = top
2 = bottom
3 = front
4 = left
5 = back
6 = right

clockwise
123456 => 126345

intothepage
123456 => 352416
*/

char str1[20], str2[20], tmp[20];

void cw() {
    for (int i = 1; i <= 6; i++) tmp[i] = str1[i];
    str1[1] = tmp[1];
    str1[2] = tmp[2];
    str1[3] = tmp[6];
    str1[4] = tmp[3];
    str1[5] = tmp[4];
    str1[6] = tmp[5];
}

void into() {
    for (int i = 1; i <= 6; i++) tmp[i] = str1[i];
    str1[1] = tmp[3];
    str1[2] = tmp[5];
    str1[3] = tmp[2];
    str1[4] = tmp[4];
    str1[5] = tmp[1];
    str1[6] = tmp[6];
}

bool check() {
    for (int i = 1; i <= 6; i++)
        if (str1[i] != str2[i]) return false;
    return true;
}

int main() {
    // freopen("in","r",stdin);
    int T;
    scanf("%d", &T);
    while (scanf("%s %s", &str1[1], &str2[1]) == 2) {
        // 1
        if (check()) goto end;
        cw();
        if (check()) goto end;
        cw();
        if (check()) goto end;
        cw();
        if (check()) goto end;
        cw();

        // 2
        into();
        if (check()) goto end;
        cw();
        if (check()) goto end;
        cw();
        if (check()) goto end;
        cw();
        if (check()) goto end;
        cw();
        into();
        into();
        into();

        // 4
        cw();
        into();
        if (check()) goto end;
        cw();
        if (check()) goto end;
        cw();
        if (check()) goto end;
        cw();
        if (check()) goto end;
        cw();
        into();
        into();
        into();

        // 5
        cw();
        into();
        if (check()) goto end;
        cw();
        if (check()) goto end;
        cw();
        if (check()) goto end;
        cw();
        if (check()) goto end;
        cw();
        into();
        into();
        into();

        // 3
        cw();
        into();
        if (check()) goto end;
        cw();
        if (check()) goto end;
        cw();
        if (check()) goto end;
        cw();
        if (check()) goto end;
        cw();
        into();
        into();
        into();

        // 6
        cw();
        into();
        into();
        if (check()) goto end;
        cw();
        if (check()) goto end;
        cw();
        if (check()) goto end;
        cw();
        if (check()) goto end;

        printf("Not Equal\n");
        continue;

    end:
        printf("Equal\n");
    }
    return 0;
}