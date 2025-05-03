#include <bits/stdc++.h>

using i64 = long long int;
using i32 = long long int;
using __i_know_i_need_int = int;
constexpr __i_know_i_need_int mod = 1e9 + 7;
#define int __i_cannot_use_int
#define IOS std::ios::sync_with_stdio(false); std::cin.tie(nullptr); std::cout.tie(nullptr);
#define endl '\n'
using pii = std::pair<__i_know_i_need_int, __i_know_i_need_int>;

void nhir() {
    i32 n;
    std::cin >> n;
    std::vector<i32> arr(n), brr(n);
    for (auto &i: arr) std::cin >> i;
    for (auto &i: brr) std::cin >> i;

    i32 k = 0;
    std::vector<pii> op;
    auto swap1 = [&](i32 i, i32 j) {
        op.emplace_back(i + 1, j + 1);
        op.emplace_back(j + 1, i + 1);
        op.emplace_back(i + 1, j + 1);
    };

    auto swap = [&](i32 i, i32 j) {
        if (i > j) i ^= j ^= i ^= j;
        for (i32 ii = i; ii < j; ii++) {
            swap1(ii, ii + 1);
        }
        for (i32 ii = j - 2; ii >= i; ii--) {
            swap1(ii, ii + 1);
        }
        std::swap(arr[j], arr[i]);
    };

    auto doXor = [&](i32 j, i32 k) {
        if (std::abs(j - k) == 1) {
            op.emplace_back(j + 1, k + 1);
            arr[j] ^= arr[k];
            return;
        }
        if (j < k) {
            for (i32 t = k; t > j + 1; t--) {
                swap1(t - 1, t);
                std::swap(arr[t - 1], arr[t]);
            }
            op.emplace_back(j + 1, j + 2);
            arr[j] ^= arr[j + 1];
            for (i32 t = j + 1; t < k; t++) {
                swap1(t, t + 1);
                std::swap(arr[t], arr[t + 1]);
            }
        } else {
            for (i32 t = k; t < j - 1; t++) {
                swap1(t, t + 1);
                std::swap(arr[t], arr[t + 1]);
            }
            op.emplace_back(j + 1, j);
            arr[j] ^= arr[j - 1];
            for (i32 t = j - 1; t > k; t--) {
                swap1(t - 1, t);
                std::swap(arr[t - 1], arr[t]);
            }
        }
    };
    for (i32 i = 20; ~i; i--) {
        for (i32 j = k; j < n; j++) {
            if (arr[j] >> i & 1) {
                swap(j, k);
                break;
            }
        }
        if ((arr[k] >> i & 1) == 0) continue;
        for (i32 j = 0; j < n; j++) {
            if (j != k && (arr[j] >> i & 1)) {
                doXor(j, k);
            }
        }
        k++;
        if (k == n) break;
    }
    for (i32 i = k; i < n; i++) {
        while (arr[i] != brr[i]) {
            bool flag = false;
            for (i32 b = 20; b >= 0; b--) {
                if ((arr[i] ^ brr[i]) >> b & 1) {
                    i32 tt = -1, res = 0x3f3f3f3f;
                    for (i32 p = 0; p < k; p++) {
                        if (arr[p] >> b & 1) {
                            if (std::abs(i - p) < res) {
                                res = std::abs(i - p);
                                tt = p;
                            }
                        }
                    }
                    if (tt != -1) {
                        doXor(i, tt);
                        flag = true;
                    }
                    if (flag) break;
                }
            }
        }
    }

    std::cout << op.size() << endl;
    for (auto [x, y]: op) {
        std::cout << x << ' ' << y << '\n';
    }
}

signed main() {
    IOS;
    __i_know_i_need_int T = 1;
    while (T--) nhir();
    return 0;
}
