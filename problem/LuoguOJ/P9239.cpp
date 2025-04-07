#include <bits/stdc++.h>
using namespace std;

int A() {
    vector<int> arr(100);
    for (auto &i: arr) std::cin >> i;
    vector<int> v(8, -1);
    set<string> s;
    auto dfs = [&](auto &&dfs, int t, int begin)-> void {
        if (t == 8 && v[7] == 0 && v[6] == 0) return;
        if (t == 8 && v[7] >= 2 && v[6] == 3) return;
        if (t == 8) {
            string ss;
            for (int i: v) {
                ss.push_back(i + '0');
            }
            s.insert(ss);
            return;
        }
        if (t == 1) if (v[0] != 2) return;
        if (t == 2 && v[1] != 0) return;
        if (t == 3 && v[2] != 2) return;
        if (t == 4 && v[3] != 3) return;
        if (t == 5 && v[4] > 1) return;
        if (t == 7 && v[6] > 3) return;
        if (t == 6 && v[5] > 2 && v[4] == 1) return;
        if (t == 6 && v[4] == 0 && v[5] == 0) return;

        for (int i = begin + 1; i < 100; i++) {
            v[t] = arr[i];
            dfs(dfs, t + 1, i);
            v[t] = -1;
        }
    };
    dfs(dfs, 0, 0);
    cout << s.size() << endl;
    for (auto i: s) {
        cout << i << endl;
    }
    // ans 235
    return 0;
}

int B() {
    int t = 23333333;
    long double ans = 11625907.5798;
    constexpr long double esp = 1e-3;
    long double log2t = log2(t);
    for (int i = 1; i < t; i++) {
        double o = t - i;
        //long double h = ((t-i)*(t-i)/t*(log2t-log2(t-i))+(i*i/t)*(log2t-log2(i)));
        long double h = (double) i * i / t * (log2t - log2(i)) + o * o / t * (log2t - log2(o));
        if (abs(ans - h) < esp) {
            cout << i << ' ' << t - i << endl;
        }
    }
    //ans 11027421
    return 0;
}

int main() {
    //A();
    //B();
    string ans[] = {
        "235", // 双引号中替换为 A 题的答案
        "11027421", // 双引号中替换为 B 题的答案
    };
    char T;
    cin >> T;
    cout << ans[T - 'A'] << endl;
    return 0;
}
