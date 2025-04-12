#include <vector>
#include <cstdio>
#include <algorithm>
#include <string>
#include <stack>

struct high_int {
    std::vector<char> hint;

    high_int() {
        hint = std::vector<char>();
    }

    high_int operator+(const high_int &rhs) const {
        high_int ans;
        ans.hint = std::vector<char>(std::max(hint.size(), rhs.hint.size()) + 1);
        for (int i = 0; i < std::max(hint.size(), rhs.hint.size()); i++) {
            if (i < hint.size()) { ans.hint[i] += hint[i]; }
            if (i < rhs.hint.size()) { ans.hint[i] += rhs.hint[i]; }
            ans.hint[i + 1] += ans.hint[i] / 10;
            ans.hint[i] %= 10;
        }
        while (ans.hint.size() > 0 && ans.hint.back() == 0) ans.hint.pop_back();
        return ans;
    }

    high_int operator*(const high_int &rhs) const {
        high_int ans;
        ans.hint = std::vector<char>(hint.size() + rhs.hint.size() + 1);
        int carry = 0;
        for (int i = 0; i < hint.size(); i++) {
            for (int j = 0; j < rhs.hint.size(); j++) {
                ans.hint[i + j] += hint[i] * rhs.hint[j];
                carry += ans.hint[i + j] / 10;
                ans.hint[i + j] %= 10;
                for (int k = 1; carry; k++) {
                    ans.hint[i + j + k] += carry % 10;
                    carry /= 10;
                }
            }
        }
        while (ans.hint.size() > 0 && ans.hint.back() == 0) ans.hint.pop_back();
        return ans;
    }

    bool operator>(const high_int &rhs) {
        if (rhs.hint.size() == hint.size()) {
            for (int i = hint.size() - 1; ~i; i--) {
                if (rhs.hint[i] != hint[i]) { return hint[i] > rhs.hint[i]; }
            }
            return false;
        }
        return hint.size() > rhs.hint.size();
    }

    bool operator<(const high_int &rhs) {
        if (rhs.hint.size() == hint.size()) {
            for (int i = hint.size() - 1; ~i; i--) {
                if (rhs.hint[i] != hint[i]) { return hint[i] < rhs.hint[i]; }
            }
            return false;
        }
        return hint.size() < rhs.hint.size();
    }
};

high_int read() {
    high_int num;
    char ch;
    std::stack<char> st;
    while (((ch = getchar()) < '0' || ch > '9') || ch == EOF) {
    }
    while (ch >= '0' && ch <= '9') {
        st.push(ch ^ 48);
        ch = getchar();
    }
    while (st.empty() == 0) {
        num.hint.push_back(st.top());
        st.pop();
    }
    return num;
}

void write(high_int &num) {
    if (num.hint.empty()) {
        putchar('0');
        return;
    }
    for (int i = num.hint.size() - 1; ~i; i--) {
        printf("%c", num.hint[i] + 48);
    }
}

int main() {
    high_int a = read();
    high_int b = read();
    a = a + b;
    write(a);
    return 0;
}
