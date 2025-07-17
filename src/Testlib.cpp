void nhir() {
    i32 n;
    Geometry::Point <i32> o;
    std::cin >> n >> o;
    std::vector <Geometry::Point<i32>> po(n);
    for (i32 i = 0; i < n; i++) {
        std::cin >> po[i];
    }
    for (int i = 0; i < n; i++) {
        if (cross(po[(i + 1) % n] - po[i], o - po[i]) < 0) {
            std::cout << std::fixed << std::setprecision(15) << Geometry::PI * 2 << "\n";
            return;
        }
    }

    std::vector <Geometry::Point<i32>> Long;
    auto dis = [](Geometry::Point <i32> a, Geometry::Point <i32> b) {
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
        vec.push_back(res);
    }
    std::ranges::sort(vec);
    long double ans = 0;
    for (i32 i = 0; i < vec.size() - 1; i++) {
        ans = std::max(ans, vec[i + 1] - vec[i]);
    }
    ans = std::max(ans, vec[0] - vec.back() + (double) Geometry::PI * 2);
    std::cout << std::fixed << std::setprecision(15) << ans << "\n";
}