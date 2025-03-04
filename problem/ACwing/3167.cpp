#include<bits/stdc++.h>
using namespace std;
double ans = 1e8;
const int N = 110;
using pdd = pair<double, double>;
vector<pdd> v;

double rand(double l, double r) {
    return (double) rand() / RAND_MAX * (r - l) + l;
}

#define x first
#define y second

double get_dist(pdd a, pdd b) {
    double dx = a.x - b.x;
    double dy = a.y - b.y;
    return sqrt(dx * dx + dy * dy);
}

double calc(pdd p) {
    double res = 0;
    for (auto i: v)
        res += get_dist(p, i);
    ans = min(ans, res);
    return res;
}

void th() {
    pdd cur(rand(0, 10000), rand(0, 10000));
    for (double t = 1e4; t > 1e-4; t *= 0.98) {
        pdd np(rand(cur.x - t, cur.x + t), rand(cur.y - t, cur.y + t));
        double dt = calc(np) - calc(cur);
        if (exp(-dt / t) > rand(0, 1)) cur = np;
    }
}

int main() {
    ios::sync_with_stdio(false);
    int n;
    cin >> n;
    for (int i = 1; i <= n; i++) {
        double x,y;
        cin >> x >> y;
        v.push_back({x,y});
    }
    for (int i = 1; i <= 100; i++) {
        th();
    }
    printf("%.0f", ans);
}
