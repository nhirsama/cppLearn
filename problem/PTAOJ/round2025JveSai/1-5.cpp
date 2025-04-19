#include <bits/stdc++.h>

int main() {
    std::string s;
    std::cin >> s;
    std::vector<int> cnt(26);
    for (auto i: s) cnt[i - 'a']++;
    std::vector<int> w(26);
    for (auto &i: w) std::cin >> i;
    long long ans = 0;
    for (int i = 0; i < 26; i++) {
        ans += w[i] * cnt[i];
    }
    for (int i = 0; i < 26; i++) {
        std::cout << cnt[i] << " \n"[i == 25];
    }
    std::cout << ans << std::endl;
}
