//
// Created by zxy15 on 25-4-16.
//
#include <bits/stdc++.h>

struct time1 {
    int hhb, mmb, ssb;
    int hhe, mme, sse;
    int b, e;
};

int main() {
    int t;
    std::cin >> t;
    std::vector<time1> v(t);
    for (int i = 0; i < t; i++) {
        std::scanf("%d:%d:%d %d:%d:%d", &v[i].hhb, &v[i].mmb, &v[i].ssb, &v[i].hhe, &v[i].mme, &v[i].sse);
    }
    for (int i = 0; i < t; i++) {
        v[i].b = (v[i].hhb) * 3600 + (v[i].mmb) * 60 + (v[i].ssb);
        v[i].e = (v[i].hhe) * 3600 + (v[i].mme) * 60 + (v[i].sse);
    }
    std::sort(v.begin(), v.end(), [](time1 a, time1 b) {
        if (a.b == b.b) {
            return a.e < b.e;
        }
        return a.b < b.b;
    });
    int cnt = 0;
    int up = 0;
    for (auto i: v) {
        if (i.b >= up) cnt++, up = i.e;
        else if (i.e < up) up = i.e;
    }
    std::cout << cnt << std::endl;
}
