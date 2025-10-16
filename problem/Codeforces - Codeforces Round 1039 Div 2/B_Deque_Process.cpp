//  B. Deque Process
//  下午10:42
#include <bits/stdc++.h>

using int64 = int64_t;
using i32 = int64_t;
constexpr int mod = 1e9 + 7;
constexpr char endl = '\n';
constexpr char enld = '\n';
constexpr int64 inf_i64 = 0x3f3f3f3f3f3f3f3f;
constexpr std::string OJ_NAME{"Codeforces"};

void nhir() {
    int n;
    std::cin >> n;
    std::deque<int> q;
    for (int i = 0; i < n; i++) {
        int t;
        std::cin >> t;
        q.push_back(t);
    }
    bool less = false;
    std::queue<int> del;
    while (!q.empty()) {
        if (del.size() < 2) {
            if (del.size() == 1) {
                if (del.back() > q.front()) less = true;
            }
            del.push(q.front());
            std::cout << 'L';
            q.pop_front();
        } else {
            if (q.size() == 1) {
                std::cout << 'L';
                q.pop_front();
            } else if (less) {
                if (q.front() > q.back()) {
                    del.push(q.back());
                    del.push(q.front());
                    q.pop_front();
                    q.pop_back();
                    std::cout << "RL";

                } else {
                    del.push(q.front());
                    del.push(q.back());
                    q.pop_front();
                    q.pop_back();
                    std::cout << "LR";
                }
                less = false;
            } else {
                if (q.front() > q.back()) {
                    del.push(q.front());
                    del.push(q.back());
                    q.pop_front();
                    q.pop_back();
                    std::cout << "LR";
                } else {
                    del.push(q.back());
                    del.push(q.front());
                    q.pop_front();
                    q.pop_back();
                    std::cout << "RL";
                }
                less = true;
            }
        }
    }
    std::cout << endl;
}

signed main() {
    std::ios::sync_with_stdio(false);
    std::cin.tie(nullptr);
    int T = 1;
    if (OJ_NAME != "AtCoder")
        std::cin >> T;
    while (T--) nhir();
    return 0;
}