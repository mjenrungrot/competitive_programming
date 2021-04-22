/*=============================================================================
#  Author:          Teerapat Jenrungrot - https://github.com/mjenrungrot/
#  FileName:        10961.cpp
#  Description:     UVa Online Judge - 10961
=============================================================================*/
#include <algorithm>
#include <cmath>
#include <cstdio>
#include <vector>
using namespace std;

struct point {
    point() {}
    point(int x, int y) : x(x), y(y) {}
    int x, y;
} A, B;

int N, M;
vector<point> V1, V2;

int abs(int x) { return x < 0 ? -x : x; }

bool hori(point A1, point A2) { return A1.y == A2.y; }
bool vert(point A1, point A2) { return A1.x == A2.x; }

int dif(point x, point y) {
    if (vert(x, y))
        return abs(x.y - y.y);
    else if (hori(x, y))
        return abs(x.x - y.x);
    return -10000;
}

bool cut(int t1, point A1, point A2, int t2, point B1, point B2) {
    if (hori(A1, A2) and vert(B1, B2)) {
        if (min(A1.x, A2.x) <= B1.x and B1.x <= max(A1.x, A2.x) and
            min(B1.y, B2.y) <= A1.y and A1.y <= max(B1.y, B2.y)) {
            // cut point
            point at = point(B1.x, A1.y);
            int dif1 = dif(A1, at);
            int dif2 = dif(B1, at);

            if (at.x == V1[N - 1].x and at.y == V1[N - 1].y) return false;

            if (t1 + dif1 == t2 + dif2)
                return true;
            else
                return false;
        }
        return false;
    } else if (vert(A1, A2) and hori(B1, B2)) {
        if (min(A1.y, A2.y) <= B1.y and B1.y <= max(A1.y, A2.y) and
            min(B1.x, B2.x) <= A1.x and A1.x <= max(B1.x, B2.x)) {
            // cut point
            point at = point(A1.x, B1.y);
            int dif1 = dif(A1, at);
            int dif2 = dif(B1, at);

            if (at.x == V1[N - 1].x and at.y == V1[N - 1].y) return false;

            if (t1 + dif1 == t2 + dif2)
                return true;
            else
                return false;
        }
        return false;
    } else if (hori(A1, A2) and hori(B1, B2) and A1.y == B1.y) {
        if ((min(A1.x, A2.x) <= min(B1.x, B2.x) and
             min(B1.x, B2.x) <= max(A1.x, A2.x)) or
            (min(A1.x, A2.x) <= max(B1.x, B2.x) and
             max(B1.x, B2.x) <= max(A1.x, A2.x))) {
            if ((A1.x < A2.x and B1.x > B2.x) or
                (A1.x > A2.x and B1.x < B2.x)) {
                //
                point at = point((A1.x + B1.x) / 2, A1.y);
                if ((A1.x + B1.x) % 2 != 0) return true;
                if (at.x == V1[N - 1].x and at.y == V1[N - 1].y) return false;
                return true;
            }
            return false;
        }
        return false;
    } else if (vert(A1, A2) and vert(B1, B2) and A1.x == B1.x) {
        if ((min(A1.y, A2.y) <= min(B1.y, B2.y) and
             min(B1.y, B2.y) <= max(A1.y, A2.y)) or
            (min(A1.y, A2.y) <= max(B1.y, B2.y) and
             max(B1.y, B2.y) <= max(A1.y, A2.y))) {
            if ((A1.y < A2.y and B1.y > B2.y) or
                (A1.y > A2.y and B1.y < B2.y)) {
                //
                point at = point(A1.x, (A1.y + B1.y) / 2);
                if ((A1.y + B1.y) % 2 != 0) return true;
                if (at.x == V1[N - 1].x and at.y == V1[N - 1].y) return false;
                return true;
            }
            return false;
        }
        return false;
    }
    return false;
}

void run() {
    int x, y;
    scanf("%d %d", &x, &y);
    A = point(x, y);
    scanf("%d %d", &x, &y);
    B = point(x, y);
    V1.clear();
    V2.clear();

    scanf("%d", &N);
    V1.push_back(B);
    for (int i = 1; i <= N; i++) {
        scanf("%d %d", &x, &y);
        V1.push_back(point(x, y));
    }
    N++;
    scanf("%d", &M);
    V2.push_back(A);
    for (int i = 1; i <= M; i++) {
        scanf("%d %d", &x, &y);
        V2.push_back(point(x, y));
    }
    M++;

    int t1 = 0, t2 = 0, id1 = 1, id2 = 1;
    // A follow V2
    // B follow V1
    while (id1 < M and id2 < N) {
        int len1 = dif(V2[id1], V2[id1 - 1]);
        int len2 = dif(V1[id2], V1[id2 - 1]);
        // printf("[%d] (%d,%d) > (%d,%d) || [%d] (%d,%d) >
        // (%d,%d)\t",t1,V2[id1-1].x,V2[id1-1].y,V2[id1].x,V2[id1].y,t2,V1[id2-1].x,V1[id2-1].y,V1[id2].x,V1[id2].y);

        // check cut
        if (cut(t1, V2[id1 - 1], V2[id1], t2, V1[id2 - 1], V1[id2])) {
            printf("No\n");
            return;
        }
        // printf("PASS\n");
        if (t1 + len1 < t2 + len2) {
            id1++;
            t1 += len1;
        } else if (t1 + len1 > t2 + len2) {
            id2++;
            t2 += len2;
        } else {
            id1++;
            id2++;
            t1 += len1;
            t2 += len2;
        }
    }
    printf("Yes\n");
}

int main() {
    // freopen("in","r",stdin);
    // freopen("out","w",stdout);
    int T;
    scanf("%d", &T);
    while (T--) {
        run();
        if (T) printf("\n");
    }
    return 0;
}