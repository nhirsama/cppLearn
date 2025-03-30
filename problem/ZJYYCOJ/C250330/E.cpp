//模板
#include <bits/stdc++.h>
using i128 = __int128;
using i64 = long long int;
using i32 = int;
typedef std::pair<i32, i32> pii;
constexpr int N = 1e5 + 10;
constexpr int mod = 1e9 + 7;
#define IOS std::ios::sync_with_stdio(false); std::cin.tie(nullptr); std::cout.tie(nullptr);
#define x first
#define y second
#define endl '\n'
#define all(x) (x).begin(), (x).end()
constexpr double eps = 1e-6;

struct Point {
    double x,y;

    Point(double _x = 0, double _y = 0) {
        x = _x;
        y = _y;
    }

    Point operator-(const Point &p1) const { return Point(x - p1.x,y - p1.y); }
    Point operator+(const Point &p1) const { return Point(x + p1.x,y + p1.y); }

    bool friend operator<(const Point &p1, const Point &p2) {
        if (fabs(p1.x - p2.x) > eps)return p1.x < p2.x;
        return p1.y < p2.y;
    }

    bool friend operator==(const Point &p1, const Point &p2) {
        if (fabs(p1.x - p2.x) > eps)return 0;
        if (fabs(p1.y - p2.y) > eps)return 0;
        return 1;
    }

    double friend operator^(const Point &p1, const Point &p2) { return p1.x * p2.y - p2.x * p1.y; }
    Point friend operator*(const Point &p1, const double &k) { return Point(p1.x * k, p1.y * k); }
    double friend operator*(const Point &p1, const Point &p2) { return p1.x * p2.x + p1.y * p2.y; }
};

Point GetCenter(const Point &p1, const Point &p2, const Point &p3) {
    Point cp;
    double a1 = p2.x - p1.x, b1 = p2.y - p1.y, c1 = (a1 * a1 + b1 * b1) / 2;
    double a2 = p3.x - p1.x, b2 = p3.y - p1.y, c2 = (a2 * a2 + b2 * b2) / 2;
    double d = a1 * b2 - a2 * b1;
    cp.x = p1.x + (c1 * b2 - c2 * b1) / d;
    cp.y = p1.y + (a1 * c2 - a2 * c1) / d;
    return cp;
};

void nhir() {
    Point zero(0, 0);
    i64 n;
    std::cin >> n;
    std::vector<Point> v;
    for (int i = 0; i < n; i++) {
        i32 x,y;
        std::cin >> x >> y;
        v.push_back(Point(x,y));
    }
    i32 ans = 0;
    std::map<Point, i32> mp;
    for (i32 i = 0; i < n; i++) {
        mp.clear();
        for (i32 j = 0; j < n; j++) {
            if (i == j) continue;
            mp[GetCenter(zero, v[i], v[j])]++;
        }
        i32 max = 0;
        for (auto i: mp) {
            max = std::max(max, i.second);
        }
        ans = std::max(ans,max);
    }
    std::cout << ans+1 << endl;
}

signed main() {
    IOS;
    i32 T = 1;

    while (T--) nhir();
    return 0;
}
