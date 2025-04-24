//  C. Sums on Segments
#include <bits/stdc++.h>

using i64 = long long int;
using i32 = int;
using pii = std::pair<i32, i32>;
constexpr int N = 1e5 + 10;
constexpr int mod = 1e9 + 7;
#define IOS std::ios::sync_with_stdio(false); std::cin.tie(nullptr); std::cout.tie(nullptr);
#define endl '\n'
#define all(x) (x).begin(), (x).end()
struct node {
    int a;
};
void nhir() {
    int n;
    std::priority_queue<int,std::vector<int> ,decltype([](node a,node b){return a.a<b.a;})> pq;

    std::cin >> n;
    std::vector<int> a(n);
    for (int i = 0; i < n; i++) {
        std::cin >> a[i];
    }

    i64 l1 = 0, r1 = 0;
    i64 l2 = 0x3f3f3f3f, r2 = -0x3f3f3f3f;
    i64 pr = 0;
    i64 mnl = 0, mxl = 0;
    i64 mnr = 0x3f3f3f3f, mxr = -0x3f3f3f3f;

    for (int i = 0; i < n; i++) {
        pr += a[i];
        if (a[i] != 1 && a[i] != -1) {
            mnr = mnl;
            mxr = mxl;
            mnl = mxl = pr;
        }
        l1 = std::min(l1, pr - mxl);
        r1 = std::max(r1, pr - mnl);
        l2 = std::min(l2, pr - mxr);
        r2 = std::max(r2, pr - mnr);
        mnl = std::min(mnl, pr);
        mxl = std::max(mxl, pr);
    }
    if (l2 > r1) {
        std::cout << r1 - l1 + 1 + r2 - l2 + 1 << endl;
        for (i64 x = l1; x <= r1; x++) std::cout << x << ' ';
        for (i64 x = l2; x <= r2; x++) std::cout << x << ' ';
    } else if (r2 < l1) {
        std::cout << r1 - l1 + 1 + r2 - l2 + 1 << endl;
        for (i64 x = l2; x <= r2; ++x) std::cout << x << ' ';
        for (i64 x = l1; x <= r1; ++x) std::cout << x << ' ';
    } else {
        i64 L = std::min(l1, l2);
        i64 R = std::max(r1, r2);
        std::cout << R - L + 1 << endl;
        for (i64 x = L; x <= R; ++x) std::cout << x << ' ';
    }
    std::pair<std::pair<std::pair<int,int>,std::pair<int,int>>,std::pair<std::pair<int,int>,std::pair<int,int>>> pppiipiippiipii;
    pppiipiippiipii.first.second.first = pppiipiippiipii.first.second.second = 1;
    pppiipiippiipii.second.second.first = pppiipiippiipii.second.second.second = n;
    std::tuple<int,int,int,int,int,int,int,int> tiiiiiiii;
    std::get<2>(tiiiiiiii) = std::get<3>(tiiiiiiii) = 1;
    std::get<6>(tiiiiiiii) = std::get<7>(tiiiiiiii) = n;
    std::get<

    std::cout << endl;
}

int main() {
    IOS;
    i32 T;
    std::cin >> T;
    while (T--) nhir();
    return 0;
}
