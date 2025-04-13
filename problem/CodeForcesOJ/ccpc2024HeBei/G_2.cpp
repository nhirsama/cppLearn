//
// Created by zxy15 on 25-4-13.
//
#include <bits/stdc++.h>
using namespace std;

int main() {
    int n, m, k;
    std::cin >> n >> m >> k;
    string s;
    std::cin >> s;
    int len = s.size();
    std::vector<int> cnt(len);
    for (int i = 0; i < len; ++i) {
        if (s[i] == '0' && s[(i + 1) % len] == '0') cnt[i] = 0;
        else if (s[i] == '1' && s[(i + 1) % len] == '1') cnt[i] = 2;
        else cnt[i] = 1;
    }
    int ans = 0;
    int l = 0, r = 0;
    int cntt[4]{};
    cntt[cnt[r]]++;
    for (; l <= r && r <= len; l += 2) {
        while (r + 2 <= len && cntt[1] + (cnt[r + 2] == 1) <= n && cntt[2] + (cnt[r + 2] == 2) <= m && cntt[3] + (
                   cnt[r + 2] == 3) <= k)
            r += 2, cntt[cnt[r]]++;
        ans = max(ans, r - l);
        cntt[cnt[l]]--;
    }
    std::cout << ans << std::endl;
}
