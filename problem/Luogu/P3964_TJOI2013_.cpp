//  P3964 [TJOI2013] 松鼠聚会
//  下午5:10
#include <bits/stdc++.h>

using int64 = int64_t;
using i32 = int64_t;
constexpr int mod = 1e9 + 7;
constexpr char endl = '\n';
constexpr char enld = '\n';
constexpr int64 inf_i64 = 0x3f3f3f3f3f3f3f3f;
constexpr std::string OJ_NAME{"Luogu"};
namespace Geometry { // 平面几何基础
    using f128 = long double;
    const f128 PI = acos(-1);
    const f128 EPS = 1e-7;
    const f128 INF = std::numeric_limits<f128>::max();

    f128 fgcd(f128 x, f128 y) { // 实数域gcd
        return abs(y) < EPS ? abs(x) : fgcd(y, fmod(x, y));
    }

    template<class T, class S>
    bool equal(T x, S y) {
        return -EPS < x - y && x - y < EPS;
    }

    template<class T>
    int sign(T x) {
        if (-EPS < x && x < EPS) return 0;
        return x < 0 ? -1 : 1;
    }

    template<class T>
    struct Point { // 在C++17下使用 emplace_back 绑定可能会导致CE！
        T x, y;

        Point(T x_ = 0, T y_ = 0) : x(x_), y(y_) {} // 初始化
        template<class U>
        operator Point<U>() { // 自动类型匹配
            return Point<U>(U(x), U(y));
        }

        Point &operator+=(Point p) &{ return x += p.x, y += p.y, *this; }

        Point &operator+=(T t) &{ return x += t, y += t, *this; }

        Point &operator-=(Point p) &{ return x -= p.x, y -= p.y, *this; }

        Point &operator-=(T t) &{ return x -= t, y -= t, *this; }

        Point &operator*=(T t) &{ return x *= t, y *= t, *this; }

        Point &operator/=(T t) &{ return x /= t, y /= t, *this; }

        Point operator-() const { return Point(-x, -y); }

        friend Point operator+(Point a, Point b) { return a += b; }

        friend Point operator+(Point a, T b) { return a += b; }

        friend Point operator-(Point a, Point b) { return a -= b; }

        friend Point operator-(Point a, T b) { return a -= b; }

        friend Point operator*(Point a, T b) { return a *= b; }

        friend Point operator*(T a, Point b) { return b *= a; }

        friend Point operator/(Point a, T b) { return a /= b; }

        friend bool operator<(Point a, Point b) {
            return equal(a.x, b.x) ? a.y < b.y - EPS : a.x < b.x - EPS;
        }

        friend bool operator>(Point a, Point b) { return b < a; }

        friend bool operator==(Point a, Point b) { return !(a < b) && !(b < a); }

        friend bool operator!=(Point a, Point b) { return a < b || b < a; }

        friend auto &operator>>(std::istream &is, Point &p) {
            return is >> p.x >> p.y;
        }

        friend auto &operator<<(std::ostream &os, Point p) {
            return os << "(" << p.x << ", " << p.y << ")";
        }
    };

    template<class T>
    struct Line {
        Point<T> a, b;

        Line(Point<T> a_ = Point<T>(), Point<T> b_ = Point<T>()) : a(a_), b(b_) {}

        template<class U>
        operator Line<U>() { // 自动类型匹配
            return Line<U>(Point<U>(a), Point<U>(b));
        }

        friend auto &operator<<(std::ostream &os, Line l) {
            return os << "<" << l.a << ", " << l.b << ">";
        }
    };

    template<class T>
    T cross(Point<T> a, Point<T> b) { // 叉乘
        return a.x * b.y - a.y * b.x;
    }

    template<class T>
    T cross(Point<T> p1, Point<T> p2, Point<T> p0) { // 叉乘 (p1 - p0) x (p2 - p0);
        return cross(p1 - p0, p2 - p0);
    }

    template<class T>
    T dot(Point<T> a, Point<T> b) { // 点乘
        return a.x * b.x + a.y * b.y;
    }

    template<class T>
    T dot(Point<T> p1, Point<T> p2, Point<T> p0) { // 点乘 (p1 - p0) * (p2 - p0);
        return dot(p1 - p0, p2 - p0);
    }

    template<class T>
    f128 dis(T x1, T y1, T x2, T y2) {
        f128 val = (x1 - x2) * (x1 - x2) + (y1 - y2) * (y1 - y2);
        return sqrt(val);
    }

    template<class T>
    f128 dis(Point<T> a, Point<T> b) {
        return dis(a.x, a.y, b.x, b.y);
    }

    template<class T>
    T dis1(Point<T> p1, Point<T> p2) { // 曼哈顿距离公式
        return abs(p1.x - p2.x) + abs(p1.y - p2.y);
    }

    Point<f128> standardize(Point<f128> vec) { // 转换为单位向量
        return vec / sqrt(vec.x * vec.x + vec.y * vec.y);
    }

    template<class T>
    Point<T> rotate(Point<T> p1, Point<T> p2) { // 旋转
        Point<T> vec = p1 - p2;
        return {-vec.y, vec.x};
    }
} // namespace Geometry
void nhir() {
    int64 n;
    std::cin >> n;
    std::vector<Geometry::Point<int64>> p(n);
    for (auto &i: p) std::cin >> i;
    std::vector<int64> px, py;
    px.reserve(n), py.reserve(n);
    for (auto &[x, y]: p) {
        px.push_back(x + y);
        py.push_back(x - y);
    }
    std::ranges::sort(px);
    std::ranges::sort(py);
    std::vector<int64> prex(n + 1), prey(n + 1);
    for (int i = 0; i < n; i++) {
        prex[i + 1] = prex[i] + px[i];
        prey[i + 1] = prey[i] + py[i];
    }
    int64 ans = inf_i64;
    for (int i = 0; i < n; i++) {
        int itx = std::ranges::lower_bound(px, p[i].x + p[i].y) - px.begin();
        int ity = std::ranges::lower_bound(py, p[i].x - p[i].y) - py.begin();
        int64 sumx = (itx) * px[itx] - prex[itx] - (n - itx - 1) * px[itx] + prex[n] - prex[itx + 1];
        int64 sumy = (ity) * py[ity] - prey[ity] - (n - ity - 1) * py[ity] + prey[n] - prey[ity + 1];
        ans = std::min(ans, sumx + sumy);
    }
    std::cout << ans / 2 << endl;
}

signed main() {
    std::ios::sync_with_stdio(false);
    std::cin.tie(nullptr);
    int T = 1;
    if (OJ_NAME != "AtCoder")
//        std::cin >> T;
        while (T--) nhir();
    return 0;
}