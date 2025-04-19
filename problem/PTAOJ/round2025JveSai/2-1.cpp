#include <bits/stdc++.h>

int main() {
    std::string s;
    std::cin >> s;
    std::stack<char> op;
    int m = 0;
    for (auto c: s) {
        if (c != ')') {
            op.push(c);
        } else {
            std::string aa;
            while (op.top() != '(') {
                aa.push_back(op.top());
                op.pop();
            }
            op.pop();
            for (int i = aa.size() - 1; ~i; i--) {
                std::cout << aa[i];
            }
            if (aa.size())std::cout << std::endl;
        }
    }
}
