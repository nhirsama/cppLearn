#include <bits/stdc++.h>
using namespace std;
const int N = 2e5+10;
typedef long long ll;
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
void Func(){
    high_int num;
    num = read();
    cin>>s;
    int ans = 7;
    bool flag = true;
    if (s[0] != '8')flag = false;
    for(int i=1;i<s.length()-1;i++) {
        if (s[i] != '0') flag = false;
    }
    if (flag == true) {ans = 1+s[s.length()-1]^'0';}
    for(int i=s.length()-1;~i;i--){
        if(s[i] == '7'){
            puts("0");
            return;
        }

        int n = s[i]^'0';
        if (i<s.length()-1) {
            if (7-n>0) {
                int bb = s[i+1]^'0';
                if (bb>=7-n) ans = min(ans, 7-n);
                else ans = min(ans, 7-n+1);
            }
            else {
                int bb = s[i+1]^'0';
                if (bb>=7-n) ans = min(ans, 7-n+10);
                else ans = min(ans, 7-n+10-1);
            }
        }
        else {
            if(n-7>0) ans = min(ans,n-7);
            else if(n-7<0) ans = min(ans,n-7+10);
        }
    }
    cout<<ans<<endl;
}
int main() {
    #ifdef LOCAL
    freopen("Testlib.in", "r", stdin);
    //freopen("Code.out", "w", stdout);
    #endif
    int T;
    cin >> T;
    while (T--) {
        Func();
    }
    return 0;
}
