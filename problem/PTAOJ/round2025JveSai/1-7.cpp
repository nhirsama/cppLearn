#include <bits/stdc++.h>

int qpow(int a, int b) {
    int res = 1;
    while (b) {
        if (b & 1) res *= a;
        a *= a;
        b >>= 1;
    }
    return res;
}

int main() {
    int n;
    std::cin >> n;
    if (n>2147483600) {
        std::cout << "Impossible for " << n << '.' << std::endl;
        return 0;
    }
    // int m = std::sqrt(n * 2 - 1);
    // while ((m + 1) * (m + 1) < n * 2 - 1)m++;
    // while ((m) * (m) > n * 2 - 1)m--;
    if (true) {
        int maxpow = 0;
        while (n >> (maxpow + 1)) maxpow++;
        for (int t = maxpow; t; t--) {
            int cnt = 1, sum = 0;
            for (; sum < n; cnt++) {
                sum += qpow(cnt, t);
            }
            if (sum == n) {
                for (int k = 1; k < cnt; k++) {
                    std::cout << k << "^" << t << "+\n"[k == cnt-1];
                }
                return 0;
            }
            sum = 0;
        }
    } else {
        std::cout << "Impossible for " << n << '.' << std::endl;
    }
}
