//  C. Manhattan Pairs
#include <bits/stdc++.h>

using int64 = int64_t;
using i32 = int64_t;
constexpr int mod = 1e9 + 7;
constexpr char endl = '\n';
constexpr char enld = '\n';
constexpr int64 inf_i64 = 0x3f3f3f3f3f3f3f3f;

void nhir() {
    i32 n;
    std::cin >> n;
    std::vector<std::array<i32, 3>> point(n);
    for (i32 i = 0; i < n; i++) {
        std::cin >> point[i][0] >> point[i][1];
        point[i][2] = i;
    }
    auto px = point;
    auto py = point;
    std::ranges::sort(px, [](auto a, auto b) {
        if (a[0] == b[0]) return a[1] < b[1];
        else return a[0] < b[0];
    });

    std::ranges::sort(py, [](auto a, auto b) {
        if (a[1] == b[1]) return a[0] < b[0];
        else return a[1] < b[1];
    });

    std::sort(px.begin(), px.begin() + n / 2, [](auto a, auto b) {
        return a[1] < b[1];
    });
    std::sort(px.begin() + n / 2, px.begin() + n, [](auto a, auto b) {
        return a[1] > b[1];
    });

    std::sort(py.begin(), py.begin() + n / 2, [](auto a, auto b) {
        return a[0] < b[0];
    });
    std::sort(py.begin() + n / 2, py.begin() + n, [](auto a, auto b) {
        return a[0] > b[0];
    });

    i32 manberx = 0, manbery = 0;
    for (i32 i = 0; i < n / 2; i++) {
        manberx += std::abs(px[i][0] - px[i + n / 2][0]) + std::abs(px[i][1] - px[i + n / 2][1]);
        manbery += std::abs(py[i][0] - py[i + n / 2][0]) + std::abs(py[i][1] - py[i + n / 2][1]);
    }
    if (manberx > manbery) {
        for (i32 i = 0; i < n / 2; i++) {
            std::cout << px[i][2] + 1 << ' ' << px[i + n / 2][2] + 1 << endl;
        }
    } else {
        for (i32 i = 0; i < n / 2; i++) {
            std::cout << py[i][2] + 1 << ' ' << py[i + n / 2][2] + 1 << endl;
        }
    }
}
//    for (i32 i = 0; i < n / 2; i++) {
//        std::cout << point[i][2] + 1 << ' ' << point[n - i - 1][2] + 1 << enld;
//    }
//    i32 dx[] = {1, 1, -1, -1};
//    i32 dy[] = {1, -1, 1, -1};
//    auto sort = [&dx, &dy, &n](i32 t, auto point) {
//        std::ranges::sort(point, [&](auto &a, auto &b) {
//            return dx[t] * a[0] + dy[t] * a[1] < dx[t] * b[0] + dy[t] * b[1];
//        });
//        i32 res = 0;
//        for (i32 i = 0; i < n / 2; i++) {
//            res += std::abs(point[i][0] - point[i + n / 2][0]) + std::abs(point[i][1] - point[i + n / 2][1]);
//        }
//        return res;
//    };
//    i32 maxv = 0, maxt = 0;
//    for (i32 i = 0; i < 4; i++) {
//        i32 t = sort(i, point);
//        if (maxv < t) {
//            maxv = t;
//            maxt = i;
//        }
//    }
//    [&](i32 t) {
//        std::ranges::sort(point, [&](auto &a, auto &b) {
//            return dx[t] * a[0] + dy[t] * a[1] < dx[t] * b[0] + dy[t] * b[1];
//        });
//    }(maxt);
//    for (i32 i = 0; i < n / 2; i++) {
//        std::cout << point[i][2] + 1 << ' ' << point[i + n / 2][2] + 1 << endl;
//    }
//    i32 n;
//    std::cin >> n;
//    std::vector<i32> x(n), y(n), u(n), v(n);
//    std::set<std::array<i32, 2>> su, sv;
//    for (i32 i = 0; i < n; i++) {
//        std::cin >> x[i] >> y[i];
//        u[i] = x[i] + y[i];
//        v[i] = x[i] - y[i];
//        su.insert({u[i], i});
//        sv.insert({v[i], i});
//    }
//    std::vector<bool> rm(n);
//    for (i32 it = 0; it < n / 2; it++) {
//        // 清理已删除的脏节点
//        while (!su.empty() && removed[su.begin()->second]) {
//            su.erase(su.begin());
//        }
//        while (!su.empty() && removed[su.rbegin()->second]) {
//            auto it2 = prev(su.end());
//            su.erase(it2);
//        }
//        while (!sv.empty() && removed[sv.begin()->second]) {
//            sv.erase(sv.begin());
//        }
//        while (!sv.empty() && removed[sv.rbegin()->second]) {
//            auto it2 = prev(sv.end());
//            sv.erase(it2);
//        }
//        i32 a = (*su.begin())[1];
//        i32 b = (*prev(su.end()))[1];
//        i32 du = std::abs(x[a] - x[b]) + std::abs(y[a] - y[b]);
//        i32 c = (*sv.begin())[1];
//        i32 d = (*prev(sv.end()))[1];
//        i32 dv = std::abs(x[c] - x[d]) + std::abs(y[c] - y[d]);
//
//        i32 p, q;
//        if (du >= dv) {
//            p = a;
//            q = b;
//        } else {
//            p = c;
//            q = d;
//        }
//        std::cout << p + 1 << " " << q + 1 << endl;
//        rm[p] = rm[q] = true;
//        su.erase({u[p], p});
//        su.erase({u[q], q});
//        sv.erase({v[p], p});
//        sv.erase({v[q], q});
//    }
//    i32 n;
//    std::cin >> n;
//    std::vector<std::array<i32, 3>> point(n);
//    for (i32 i = 0; i < n; i++) {
//        std::cin >> point[i][0] >> point[i][1];
//        point[i][2] = i;
//    }
//    i32 dx[] = {1, 1, -1, -1};
//    i32 dy[] = {1, -1, 1, -1};
//    auto sort = [&dx, &dy, &n](i32 t, auto point) {
//        std::ranges::stable_sort(point, [&](auto &a, auto &b) {
//            return dx[t] * a[0] + dy[t] * a[1] < dx[t] * b[0] + dy[t] * b[1];
//        });
//        i32 res = 0;
//        for (i32 i = 0; i < n / 2; i++) {
//            res += std::abs(point[i][0] - point[n - i - 1][0]) + std::abs(point[i][1] - point[n - i - 1][1]);
//        }
//        return res;
//    };
//    i32 maxv = 0, maxt = 0;
//    for (i32 i = 0; i < 4; i++) {
//        i32 t = sort(i, point);
//        if (maxv < t) {
//            maxv = t;
//            maxt = i;
//        }
//    }
//    [&](i32 t) {
//        std::ranges::stable_sort(point, [&](auto &a, auto &b) {
//            return dx[t] * a[0] + dy[t] * a[1] < dx[t] * b[0] + dy[t] * b[1];
//        });
//        i32 res = 0;
//        for (i32 i = 0; i < n / 2; i++) {
//            res += std::abs(point[i][0] - point[n - i - 1][0]) + std::abs(point[i][1] - point[n - i - 1][1]);
//        }
//        return res;
//    }(maxt);
////    std::ranges::sort(point, [](auto &a, auto &b) {
////        if (a[0] == b[0]) return a[1] < b[1];
////        else return a[0] < b[0];
////    });
//    for (i32 i = 0; i < n / 2; i++) {
//        std::cout << point[i][2] + 1 << ' ' << point[n - i - 1][2] + 1 << endl;
//    }
//}

signed main() {
    std::ios::sync_with_stdio(false);
    std::cin.tie(nullptr);
    int T = 1;
    std::cin >> T;
    while (T--) nhir();
    return 0;
}