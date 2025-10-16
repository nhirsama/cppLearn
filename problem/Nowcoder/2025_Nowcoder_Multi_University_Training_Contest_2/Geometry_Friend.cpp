//  Geometry Friend
#include <bits/stdc++.h>

using i64 = long long int;
using i32 = long long int;
constexpr int mod = 1e9 + 7;
constexpr char endl = '\n';
constexpr char enld = '\n';
constexpr i64 inf_i64 = 0x3f3f3f3f3f3f3f3f;
namespace Geometry { // 平面几何基础
    using namespace std;
    using ld = long double;
    const ld PI = acos(-1);
    const ld EPS = 1e-7;
    const ld INF = numeric_limits<ld>::max();
#define cc(x) cout << fixed << setprecision(x);

    ld fgcd(ld x, ld y) { // 实数域gcd
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

        friend auto &operator>>(istream &is, Point &p) {
            return is >> p.x >> p.y;
        }

        friend auto &operator<<(ostream &os, Point p) {
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

        friend auto &operator<<(ostream &os, Line l) {
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
    ld dis(T x1, T y1, T x2, T y2) {
        ld val = (x1 - x2) * (x1 - x2) + (y1 - y2) * (y1 - y2);
        return sqrt(val);
    }

    template<class T>
    ld dis(Point<T> a, Point<T> b) {
        return dis(a.x, a.y, b.x, b.y);
    }

    template<class T>
    T dis1(Point<T> p1, Point<T> p2) { // 曼哈顿距离公式
        return abs(p1.x - p2.x) + abs(p1.y - p2.y);
    }

    Point<ld> standardize(Point<ld> vec) { // 转换为单位向量
        return vec / sqrt(vec.x * vec.x + vec.y * vec.y);
    }

    template<class T>
    Point<T> rotate(Point<T> p1, Point<T> p2) { // 旋转
        Point <T> vec = p1 - p2;
        return {-vec.y, vec.x};
    }
} // namespace Geometry
void nhir() {
    i32 n;
    Geometry::Point<i32> o;
    std::cin >> n >> o;
    std::vector<Geometry::Point<i32>> po(n);
    for (i32 i = 0; i < n; i++) {
        std::cin >> po[i];
    }
    for (int i = 0; i < n; i++) {
        if (cross(po[(i + 1) % n] - po[i], o - po[i]) < 0) {
            std::cout << std::fixed << std::setprecision(15) << Geometry::PI * 2 << "\n";
            return;
        }
    }

    std::vector<Geometry::Point<i32>> Long;
    auto dis = [](Geometry::Point<i32> a, Geometry::Point<i32> b) {
        return (a.x - b.x) * (a.x - b.x) + (a.y - b.y) * (a.y - b.y);
    };
    i32 maxv = 0;
    for (auto p: po) {
        i32 len = dis(p, o);
        if (len > maxv) {
            Long.clear();
            Long.push_back(p);
            maxv = len;
        } else if (len == maxv) {
            Long.push_back(p);

        }
    }
    std::vector<long double> vec;
    for (auto poi: Long) {
        long double res = atan2(poi.y - o.y, poi.x - o.x);
        if (res < 0) res += 2 * Geometry::PI;
//        double res = 0;
//        i32 vex = (poi - o).x;
//        i32 vey = (poi - o).y;
//        if (vex < 0) {
//            res += Geometry::PI;
//            if (vey) res += atan2(vey, vex);
//        } else if (vex == 0) {
//            if (vey > 0) res += Geometry::PI / 2;
//            else res = -Geometry::PI / 2;
//        } else {
//            res += atan2(vey, vex);
//        }
//        if (res < 0) res += Geometry::PI * 2;
//        res += Geometry::PI / 2;
        vec.push_back(res);
    }
    std::ranges::sort(vec);
    long double ans = 0;
    for (i32 i = 0; i < vec.size() - 1; i++) {
        ans = std::max(ans, vec[i + 1] - vec[i]);
    }
    ans = std::max(ans, vec[0] - vec.back() + (double) Geometry::PI * 2);
//    if (vec.size() == 1) ans = 0;
//    printf("%.15f\n", ans);

    std::cout << std::fixed << std::setprecision(15) << ans << "\n";
//    std::cout << 2 * Geometry::PI - vec.back() << endl;

}

signed main() {
    std::ios::sync_with_stdio(false);
    std::cin.tie(nullptr);
    int T = 1;
    std::cin >> T;
    while (T--) nhir();
    return 0;
}