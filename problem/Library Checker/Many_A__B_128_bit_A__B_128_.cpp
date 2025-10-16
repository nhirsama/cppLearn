//  Many A + B (128 bit)许多 A + B (128 位)
//  上午3:22
#include <bits/stdc++.h>

using int64 = int64_t;
using i32 = int64_t;
constexpr int mod = 1e9 + 7;
constexpr char endl = '\n';
constexpr char enld = '\n';
constexpr int64 inf_i64 = 0x3f3f3f3f3f3f3f3f;
constexpr std::string OJ_NAME{"Library Checker"};

struct int128 {
private:
    __int128 value;
public:
    int128() {
        this->value = 0;
    }

    template<typename T>
    int128(const T &t) {
        this->value = t;
    }

    friend std::istream &operator>>(std::istream &is, int128 &x) {
        std::string val;
        is >> val;
        bool neg = false;
        if (!val.empty() && val[0] == '-') {
            neg = true;
            val.erase(val.begin());
        }
        x.value = 0;
        for (char c: val) {
            if (c < '0' || c > '9') continue;
            x.value = x.value * 10 + (c - '0');
        }
        if (neg) x.value = -x.value;
        return is;
    }

    friend std::ostream &operator<<(std::ostream &os, const int128 &x) {
        if (x.value == 0) return os << '0';
        __int128 tmp = x.value;
        if (tmp < 0) {
            os << '-';
            tmp = -tmp;
        }
        std::string s;
        while (tmp > 0) {
            s.push_back(char('0' + tmp % 10));
            tmp /= 10;
        }
        std::reverse(s.begin(), s.end());
        return os << s;
    }

    int128 operator+(const int128 &b) const {
        return this->value + b.value;
    }

    int128 operator-(const int128 &b) const {
        return this->value - b.value;
    }

    int128 operator*(const int128 &b) const {
        return this->value * b.value;
    }

    int128 operator/(const int128 &b) const {
        assert(b.value != 0); //除零
        return this->value / b.value;
    }

    auto operator<=>(const int128 &b) const -> std::strong_ordering = default;

};

void nhir() {
    int128 a, b;
    std::cin >> a >> b;
    std::cout << a + b << endl;
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