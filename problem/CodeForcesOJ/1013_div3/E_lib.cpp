#include <bits/stdc++.h>
using namespace std;

typedef long long ll;
vector<int> minp, primes;

void sieve(int n) {
    minp.assign(n + 1, 0);
    primes.clear();

    for (int i = 2; i <= n; i++) {
        if (minp[i] == 0) {
            minp[i] = i;
            primes.push_back(i);
        }

        for (auto p: primes) {
            if (i * p > n) {
                break;
            }
            minp[i * p] = p;
            if (p == minp[i]) {
                break;
            }
        }
    }
}

bool isprime(int n) {
    return minp[n] == n;
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    sieve(10000);
    int t;
    cin >> t;
    while (t--) {
        int n;
        cin>>n;
        for (int i = 1; i <= n; i++) {
            for (int j = i + 1; j <= n; j++) {
                int gcdd = gcd(i, j);
                if (i * j / (gcdd * gcdd) && (i * j % (gcdd * gcdd) == 0)) {
                    if (isprime(i * j / (gcdd * gcdd))) {
                        cout << i << ' ' << j << endl;
                    }
                }
            }
        }
    }
    return 0;
}
