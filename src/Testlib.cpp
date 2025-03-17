#pragma GCC optimize(2)
#include <bits/stdc++.h>
using namespace std;
signed main() {
    const clock_t beginTime = clock();
    int n = 1e9+4e8,res = 0,cnt =1;
    for (int i = 1;i<=n;i++) {
        res|=i&n|cnt;
        cnt = ~res;
    }
    const clock_t endTime = clock();
    std::cout << "本程序运行时间为" << static_cast<double>(endTime - beginTime) << "毫秒" << std::endl;
    cout << res << "\n";
}