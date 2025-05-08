//  B. Bear and Different Names
#include <bits/stdc++.h>

using i64 = long long int;
using i32 = long long int;
using __i_know_i_need_int = int;
constexpr __i_know_i_need_int mod = 1e9 + 7;
#define int __i_cannot_use_int
#define IOS std::ios::sync_with_stdio(false); std::cin.tie(nullptr); std::cout.tie(nullptr);
#define endl '\n'
std::string name[] = {
    "Tomori", "Anon", "Raana", "Soyo", "Taki",
    "Sakiko", "Mutsumi", "Uika", "Mana", "Umiri",
    "Tohka", "Kurumi", "Yoshino", "Kotori", "Origami",
    "Miku", "Nia", "Mayuri", "Rinne", "Shiori",
    "Nina", "Momoka", "Subaru", "Tomo", "Rupa",
    "Asuna", "Yui", "Alice", "Sinon", "Leafa",
    "Mikasa", "Armin", "Historia", "Ymir", "Annie",
    "Emilia", "Rem", "Beatrice", "Ram", "Felt",
    "Yukino", "Iroha", "Sae", "Komachi", "Yuii",
    "Nezuko", "Shinobu", "Kanao", "Mitsuri", "Tengen",
    "Sakura", "Hinata", "Tsunade", "Temari", "Ino"
};


void nhir() {
    i32 n, k;
    std::cin >> n >> k;
    for (i32 i = k - 1; i < n; i++) {
        std::string s;
        std::cin >> s;
        // if (s == "YES") {
        //     if (i == k - 1) continue;
        //     else {
        //         //name[i] = name[i-k];
        //     }
        // } else
        if (s == "NO") name[i] = name[i - k + 1];
    }
    for (i32 i = 0; i < n; i++) {
        std::cout << name[i] << ' ';
    }
    // std::vector<std::string> ans;
    // std::vector<i32> tg(n,0),fg(n,1);
    // for (i32 i = k-1;i<n;i++) {
    //     std::string s;
    //     std::cin>>s;
    //     if (s == "YES") {
    //         for (i32 j = i-k+1;j<=i;j++) tg[j]++;
    //     }
    //     else fg[i] = 0;
    // }
    // i32 now = 0;
    // for (i32 i = 0;i<n;i++) {
    //     if ((tg[i] || i<k-1) && fg[i]) {
    //         ans.push_back(name[now++]);
    //     }
    //     else ans.push_back(ans[i-k+1]);
    // }
    // for (auto &i:ans) {
    //     std::cout<<i<<' ';
    // }
}

signed main() {
    IOS;
    __i_know_i_need_int T = 1;
    while (T--) nhir();
    return 0;
}
