#include <bits/stdc++.h>
bool flag = false;
int n;
long long a, b;

long long qpow(int a, int b) {
    long res = 1;
    while (b) {
        if (b & 1) res *= a;
        a *= a;
        b >>= 1;
    }
    return res;
}

void dfs(int t, long long sum) {
    if (n == t) {
        // long long tenn = 1;
        // int cnt = 0;
        // for (int i = n-1;~i;i--) {
        //     if ((sum/tenn)%n) return;
        //     tenn*=10;
        // }
        if (sum%n)return;
        if (a <= sum && sum <= b) {
            flag = true;

            std::cout << sum << std::endl;
        }
        return;
    }
    for (int i = 0; i <= 9; i++) {
        long long ten = qpow(10, n - t - 1);
        long long tsum = (sum * 10 + i);
        //std::cout<<tsum<<std::endl;
        if (a / ten <= tsum && tsum <= b / ten) {
            if (tsum % (t + 1) == 0) dfs(t + 1, tsum);
        }
    }
}

int main() {
    std::cin >> n >> a >> b;
    dfs(0, 0);
    if (!flag) {
        std::cout << "No Solution\n";
    }
}
