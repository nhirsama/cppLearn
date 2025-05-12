//  A. Nephren gives a riddle
#include <bits/stdc++.h>

using i64 = long long int;
using i32 = long long int;
using __i_know_i_need_int = int;
constexpr __i_know_i_need_int mod = 1e9 + 7;
#define int __i_cannot_use_int
#define IOS std::ios::sync_with_stdio(false); std::cin.tie(nullptr); std::cout.tie(nullptr);
#define endl '\n'
using u32 = unsigned long long;
std::string base0 = "What are you doing at the end of the world? Are you busy? Will you save us?";
std::string base1 = "What are you doing while sending \"";
std::string base2 = "\"? Are you busy? Will you send \"", base3 = "\"?";
std::vector<u32> arr(1e5 + 50);

bool dfs(i32 n, i32 &k) {
    if (n == 0) {
        if (0 < k && k <= base0.size()) {
            std::cout << base0[k - 1];
            return true;
        }
        k -= base0.size();
        return false;
    }
    if (0 < k && k <= base1.size()) {
        std::cout << base1[k - 1];
        return true;
    }
    k -= base1.size();
    if (0 < k && k <= arr[n - 1]) {
        if (dfs(n - 1, k)) {
            return true;
        }
    }
    k -= arr[n - 1];
    if (0 < k && k <= base2.size()) {
        std::cout << base2[k - 1];
        return true;
    }
    k -= base2.size();
    if (0 < k && k <= arr[n - 1]) {
        if (dfs(n - 1, k)) {
            return true;
        }
    }
    k -= arr[n - 1];
    if (0 < k && k <= base3.size()) {
        std::cout << base3[k - 1];
        return true;
    };
    k -= arr[n - 1];
    //std::cout << '.';
    return false;
}

void nhir() {
    i32 n, k;
    std::cin >> n >> k;
    if (!dfs(n, k)) {
        std::cout << '.';
    }
}

signed main() {
    IOS;
    __i_know_i_need_int T = 1;
    arr[0] = base0.size();
    for (i32 i = 1; i <= 1e5 + 30; i++) {
        arr[i] = base1.size() + base2.size() + base3.size() + (2 * arr[i - 1]);
        if (arr[i] >= 2e18) {
            arr[i] = 2e18;
        }
    }
    std::cin >> T;
    while (T--) nhir();
    return 0;
}
