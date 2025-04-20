//P1265 公路修建
#include <bits/stdc++.h>
using i64 = long long int;
using i32 = int;
using pii = std::pair<long double, i32>;
constexpr int N = 5e3 + 5;
constexpr int mod = 1e9 + 7;
#define IOS std::ios::sync_with_stdio(false); std::cin.tie(nullptr); std::cout.tie(nullptr);
#define endl '\n'
#define all(x) (x).begin(), (x).end()

namespace Geometry {
    // 平面几何基础
    using ld = double;
    const ld PI = acos(-1);
    const ld EPS = 1e-4;
    const ld INF = std::numeric_limits<ld>::max();
#define cc(x) cout << fixed << setprecision(x);

    ld fgcd(ld x, ld y) {
        // 实数域gcd
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
    struct Point {
        // 在C++17下使用 emplace_back 绑定可能会导致CE！
        T x, y;

        Point(T x_ = 0, T y_ = 0) : x(x_), y(y_) {
        } // 初始化
        template<class U>
        operator Point<U>() {
            // 自动类型匹配
            return Point<U>(U(x), U(y));
        }

        Point &operator+=(Point p) & { return x += p.x, y += p.y, *this; }
        Point &operator+=(T t) & { return x += t, y += t, *this; }
        Point &operator-=(Point p) & { return x -= p.x, y -= p.y, *this; }
        Point &operator-=(T t) & { return x -= t, y -= t, *this; }
        Point &operator*=(T t) & { return x *= t, y *= t, *this; }
        Point &operator/=(T t) & { return x /= t, y /= t, *this; }
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
    ld dis(T x1, T y1, T x2, T y2) {
        ld val = (x1 - x2) * (x1 - x2) + (y1 - y2) * (y1 - y2);
        return sqrt(val);
    }

    template<class T>
    ld dis(Point<T> a, Point<T> b) {
        return dis(a.x, a.y, b.x, b.y);
    }
} // namespace Geometry
Geometry::Point<i64> point[N];

auto Prim(int n) {
    double res = 0;
    std::vector<double> dis(n + 1, 1e12 * 1.0);
    std::vector<bool> vis(n + 1);
    dis[1] = 0.0;
    vis[1] = true;
    int curr;
    double minn;
    for (int i = 1; i <= n; i++) {
        curr = 1;
        minn = 1e9 * 1.0;
        for (int j = 1; j <= n; j++) //找最短边
            if (!vis[j] && dis[j] < minn)
                minn = dis[j], curr = j;
        vis[curr] = true;
        res += dis[curr];
        for (int j = 1; j <= n; j++) //现用现算
            dis[j] = std::min(dis[j], Geometry::dis(point[curr], point[j]));
    }
    return res;
}

void nhir() {
    int n;
    std::cin >> n;
    for (int i = 1; i <= n; i++) std::cin >> point[i];
    printf("%.2f", Prim(n));
}

signed main() {
    //IOS;
    i32 T = 1;
    if (getenv("LOCAL") != nullptr) {
        freopen("Testlib.in", "r", stdin);
        // freopen("Code.out", "w", stdout);
    }

    while (T--) nhir();
    return 0;
}
