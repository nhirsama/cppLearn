#include <bits/stdc++.h>
using namespace std;

int main() {
    string s;
    set<string> m, b;
    while (cin >> s) {
        if ('0' <= s[0] && s[0] <= '9') {
            break;
        }
        if ('A' <= s[0] && s[0] <= 'Z') {
            s[0] = s[0] - ('A' - 'a');
        }
        if (s.back() == ',' || s.back() == '.' || s.back() == '!' || s.back() == '?') {
            s.pop_back();
        }
        b.insert(s);
    }
    int n = 0;
    for (auto i: s) {
        n = n * 10 + (i - '0');
    }
    for (int i = 0; i < n; i++) {
        string t;
        std::cin >> t;
        if (b.find(t) != b.end()) {
            b.erase(b.find(t));
        }
    }
    std::cout << b.size();
}
