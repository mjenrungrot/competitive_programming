#include <bits/stdc++.h>
using namespace std;

long long L, R;

int main()
{
    int n_case = 0;
    while (cin >> L >> R)
    {
        long long limit = min(R, 1005LL);
        int ans = 0;
        for (long long a = L; a <= limit; a++)
        {
            for (long long b = L; b <= limit; b++)
            {
                long long tmp = (a * a * a + b * b * b);
                if (tmp % 10 != 3)
                    continue;

                long long c = tmp / 10;
                if (L <= c and c <= R)
                    ans++;
            }
        }
        cout << "Case " << ++n_case << ": " << ans << endl;
    }
    return 0;
}