#include <bits/stdc++.h>
using namespace std;

const int MAX_N = 100;

int t[MAX_N], lo[MAX_N], hi[MAX_N];

int main()
{
    int tc;
    cin >> tc;
    while (tc--)
    {
        int n, m, i;
        cin >> n >> m;
        for (i = 0; i < n; i++)
            cin >> t[i] >> lo[i] >> hi[i];
        int prev = 0;
        int mn = m, mx = m;
        bool flag = true;
        for (i = 0; i < n; i++)
        {
            mx += t[i] - prev;
            mn -= t[i] - prev;
            if (mx < lo[i] || mn > hi[i])
            {
                flag = false;
                break;
            }
            mx = min(mx, hi[i]);
            mn = max(mn, lo[i]);
            prev = t[i];
        }
        if (flag)
            cout << "YES\n";
        else
            cout << "NO\n";
    }
}