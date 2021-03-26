#include <bits/stdc++.h>
using namespace std;

const long long MOD = 100000007;
long long S;

int main()
{
    ios::sync_with_stdio(false);
    while (cin >> S)
    {
        if (S == 0)
        {
            break;
        }

        bool has_answer = false;
        for (long long x = 1; 6 * x * x < S; x++)
        {
            long long tmp = S - 6 * x * x;
            if (tmp < 7 * x)
                continue;
            if (tmp % (7 * x))
                continue;

            long long d = (S - 6 * x * x) / (7 * x);
            has_answer = true;
            cout << "Possible Missing Soldiers = " << (2 * ((d % MOD) * (d % MOD)) % MOD) % MOD << endl;
        }
        if (not has_answer)
            cout << "No Solution Possible" << endl;
        cout << endl;
    }

    return 0;
}