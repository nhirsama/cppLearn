//E. Triple Operations
//记得把文件重定向注释掉
#include <bits/stdc++.h>
constexpr int N = 2e5 + 10;
std::vector<long long> pre(N + 1);

void Func() {
    long long l, r;
    std::cin >> l >> r;
    long long ans = 0;
    ans = pre[r] + pre[l] - 2 * pre[l - 1];
    std::cout << ans << '\n';

    //    int ans = 0,aa = 1,pown = 0;
    //    bool flag = true;
    //    for (;aa<l;aa*=3,pown++) {
    //    }
    //    ans+=min(r-l+1,aa-l)*pown;
    //    for(;aa<r;aa*=3,pown++){
    //        if (l<aa/3) ans+=(aa-aa/3)*pown;
    //    }
    //    cout<<ans<<endl;
}

int main() {
    for (int i = 1; i <= 2e5 + 5; i++) pre[i] = pre[i / 3] + 1;
    for (int i = 1; i <= 2e5 + 4; i++)pre[i] += pre[i - 1];
    int T;
    std::cin >> T;
    while (T--) {
        Func();
    }
    return 0;
}
