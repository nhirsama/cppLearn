#define LOCAL
//P1018 [NOIP 2000 提高组] 乘积最大
//记得把文件重定向注释掉
#include <bits/stdc++.h>
using namespace std;

struct high_int {
    std::vector<char> hint;

    high_int operator+(const high_int &rhs) {
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
    //高精乘写错了，草
    high_int operator*(const high_int &rhs) const {
        high_int ans;
        ans.hint = std::vector<char>(hint.size() + rhs.hint.size() + 1);
        int t = 0;
        for (int i = 0; i < hint.size(); i++) {
            for (int j = 0; j < rhs.hint.size(); j++) {
                ans.hint[i + j] += hint[i] * rhs.hint[j];
                t += ans.hint[i + j] / 10;
                ans.hint[i + j] %= 10;
                ans.hint[i + j + 1] += t % 10;
                t /= 10;
            }
        }
        while (ans.hint.size() > 0 && ans.hint.back() == 0) ans.hint.pop_back();
        return ans;
    }

    bool operator>(const high_int &rhs) {
        if (rhs.hint.size() == hint.size()) {
            for (int i = hint.size() - 1; ~i; i--) {
                if (rhs.hint[i] != hint[i]) { return rhs.hint[i] < hint[i]; }
            }
            return true;
        }
        return rhs.hint.size() < hint.size();
    }
    bool operator<(const high_int &rhs) {
        return !this->operator>(rhs);
    }
};

high_int read() {
    high_int num;
    char ch;
    std::stack<char> st;
    while ((ch = getchar()) < '0' || ch > '9') {
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

high_int dp[41][41], num;
high_int ans,aa,bb;
int n, k;
bool m[41];
void dfs(int a,int b) { //a是插入的乘号数，b是当前搜素到第几个数
    if (b>=n) return;
    //if (k-a > n-b) return;
    if (a == k) {
        aa = high_int();
        bb = high_int();
        aa.hint.push_back(1);
        for (int i = 0; i < n; i++) {
            bb.hint.push_back(num.hint[i]);
            if (m[i]) {
                aa = aa*bb;
                bb = high_int();
            }
        }
        aa = aa * bb;
        if (aa>ans) {
            ans = aa;
        }
        return;
    }
    m[b]=true;
    dfs(a+1, b+1);
    m[b]=false;
    dfs(a, b+1);
}
int main() {
#ifdef LOCAL
    freopen("Testlib.in", "r", stdin);
    freopen("Code.out", "w", stdout);
#endif
    cin >> n >> k;
    num = read();
    dfs(0,0);
    write(ans);
#ifdef LOCAL
    fclose(stdin);
    fclose(stdout);
#endif
    return 0;
}
