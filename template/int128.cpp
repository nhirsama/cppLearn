//
// Created by zxy15 on 25-8-14.
//
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