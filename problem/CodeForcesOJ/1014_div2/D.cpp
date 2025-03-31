//D
#include <bits/stdc++.h>
using i128 = __int128;
using i64 = long long int;
using i32 = int;
typedef std::pair<i32, i32> pii;
constexpr int N = 1e5 + 10;
constexpr int mod = 1e9 + 7;
#define IOS std::ios::sync_with_stdio(false); std::cin.tie(nullptr); std::cout.tie(nullptr);
#define endl '\n'
#define all(x) (x).begin(), (x).end()

void nhir() {
    //std::map<char, i32> m{{'L', 0}, {'I', 0}, {'T', 0}};
    i32 n;
    std::string s;
    std::cin >> n >> s;
    if (std::count(all(s), s[0]) == n) {
        std::cout << -1 << endl;
        return;
    }
    std::vector<i32> a(n);
    i32 cnt[3]{};
    char cc[] = "TLI";
    for (i32 i = 0; i < n; i++) {
        for (i32 j = 0; j < 3; j++) if (s[i] == cc[j]) a[i] = j;
        cnt[a[i]]++;
    }
    std::vector<i32> ans;
    i32 min = *std::min_element(cnt, cnt + 3);
    for (i32 x = 0; x < 3; x++) {
        if (cnt[x] == min) {
            continue;
        }
        int p = 1;
        while ((a[p] == x) == (a[p - 1] == x)) {
            p++;
        }
        while (cnt[x] > min) {
            if (a[p] == x) {
                int y = a[p - 1];
                a.insert(a.begin() + p, 3 - x - y);
                ans.push_back(p);
                a.insert(a.begin() + p + 1, y);
                ans.push_back(p + 1);
                p += 2;
            } else {
                int y = a[p];
                a.insert(a.begin() + p, 3 - x - y);
                ans.push_back(p);
                a.insert(a.begin() + p, y);
                ans.push_back(p);
            }
            cnt[x]--;
        }
    }
    std::cout << ans.size() << "\n";
    for (auto x: ans) {
        std::cout << x << "\n";
    }
    // for (auto i: s) m[i]++;
    // if (m['T'] == n || m['I'] == n || m['L'] == n) {
    //     std::cout << -1 << endl;
    //     return;
    // }
    // std::vector<i32> ans;
    // char cc[] = "TLI";
    // while ((m['T'] != m['L']) || (m['I'] != m['L']) || (m['T'] != m['I'])) {
    //     for (i32 i = 0; i < s.size() - 1; i++) {
    //         i32 hou = 0, qian = 2, cha = 1;
    //         if (s[i] == cc[hou] && s[i + 1] == cc[qian] && (m[cc[cha]] < m[cc[hou]] || m[cc[cha]] < m[cc[qian]])) {
    //             ans.push_back(i + 1);
    //             s.insert(i + 1, 1, cc[cha]);
    //             m[cc[cha]]++;
    //             break;
    //         }
    //         hou = 0, qian = 1, cha = 2;
    //         if (s[i] == cc[hou] && s[i + 1] == cc[qian] && (m[cc[cha]] < m[cc[hou]] || m[cc[cha]] < m[cc[qian]])) {
    //             ans.push_back(i + 1);
    //             s.insert(i + 1, 1, cc[cha]);
    //             m[cc[cha]]++;
    //             break;
    //         }
    //         hou = 1, qian = 0, cha = 2;
    //         if (s[i] == cc[hou] && s[i + 1] == cc[qian] && (m[cc[cha]] < m[cc[hou]] || m[cc[cha]] < m[cc[qian]])) {
    //             ans.push_back(i + 1);
    //             s.insert(i + 1, 1, cc[cha]);
    //             m[cc[cha]]++;
    //             break;
    //         }
    //         hou = 1, qian = 2, cha = 0;
    //         if (s[i] == cc[hou] && s[i + 1] == cc[qian] && (m[cc[cha]] < m[cc[hou]] || m[cc[cha]] < m[cc[qian]])) {
    //             ans.push_back(i + 1);
    //             s.insert(i + 1, 1, cc[cha]);
    //             m[cc[cha]]++;
    //             break;
    //         }
    //         hou = 2, qian = 1, cha = 0;
    //         if (s[i] == cc[hou] && s[i + 1] == cc[qian] && (m[cc[cha]] < m[cc[hou]] || m[cc[cha]] < m[cc[qian]])) {
    //             ans.push_back(i + 1);
    //             s.insert(i + 1, 1, cc[cha]);
    //             m[cc[cha]]++;
    //             break;
    //         }
    //         hou = 2, qian = 0, cha = 1;
    //         if (s[i] == cc[hou] && s[i + 1] == cc[qian] && (m[cc[cha]] < m[cc[hou]] || m[cc[cha]] < m[cc[qian]])) {
    //             ans.push_back(i + 1);
    //             s.insert(i + 1, 1, cc[cha]);
    //             m[cc[cha]]++;
    //             break;
    //         }
    //     }
    // }
    // std::cout << ans.size() << endl;
    // for (auto i: ans) {
    //     std::cout << i << endl;
    // }
    //std::cout<<s<<endl;
}

signed main() {
    IOS;
    i32 T = 1;
    if (getenv("LOCAL") != nullptr) {
        freopen("Testlib.in", "r", stdin);
        // freopen("Code.out", "w", stdout);
    }
    std::cin >> T;
    while (T--) nhir();
    return 0;
}
