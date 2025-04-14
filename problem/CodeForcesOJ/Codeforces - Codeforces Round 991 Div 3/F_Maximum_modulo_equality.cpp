//  F. Maximum modulo equality
#include <bits/stdc++.h>
using namespace std;
using i64 = long long int;
using i32 = int;
using pii = std::pair<i32, i32>;
constexpr int N = 1e5 + 10;
constexpr int mod = 1e9 + 7;
#define IOS std::ios::sync_with_stdio(false); std::cin.tie(nullptr); std::cout.tie(nullptr);
#define endl '\n'
#define all(x) (x).begin(), (x).end()

struct ST {
    const int n, k;
    vector<int> in1;
    vector<vector<int> > Max, Gcd;

    ST(int n) : n(n), in1(n + 1), k(__lg(n)) {
        Max.resize(k + 1, vector<int>(n + 1));
        Gcd.resize(k + 1, vector<int>(n + 1));
    }

    void init() {
        for (int i = 1; i <= n; i++) {
            Max[0][i] = in1[i];
            Gcd[0][i] = in1[i];
        }
        for (int i = 0, t = 1; i < k; i++, t <<= 1) {
            const int T = n - (t << 1) + 1;
            for (int j = 1; j <= T; j++) {
                Max[i + 1][j] = max(Max[i][j], Max[i][j + t]);
                Gcd[i + 1][j] = gcd(Gcd[i][j], Gcd[i][j + t]);
            }
        }
    }

    int getMax(int l, int r) {
        if (l > r) {
            swap(l, r);
        }
        int k = __lg(r - l + 1);
        return max(Max[k][l], Max[k][r - (1 << k) + 1]);
    }

    int getgcd(int l, int r) {
        if (l > r) {
            swap(l, r);
        }
        int k = __lg(r - l + 1);
        return gcd(Gcd[k][l], Gcd[k][r - (1 << k) + 1]);
    }
};

void nhir() {
    i32 n, q;
    std::cin >> n >> q;
    std::vector<i32> arr(n);
    for (auto &i: arr) std::cin >> i;
    ST st(n - 1);
    for (i32 i = 0; i < n - 1; i++) {
        st.in1[i + 1] = std::abs(arr[i] - arr[i + 1]);
    }
    st.init();
    while (q--) {
        i32 l, r;
        std::cin >> l >> r;
        if (l == r || (l < r && st.getMax(l, r - 1) == 0)) {
            std::cout << 0 << ' ';
            continue;
        }
        i32 gcd = st.getgcd(l, r - 1);
        std::cout << gcd << ' ';
    }
    std::cout << endl;
}

signed main() {
    IOS;
    i32 T = 1;
    std::cin >> T;
    while (T--) nhir();
    return 0;
}
