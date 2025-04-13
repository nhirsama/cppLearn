#include<bits/stdc++.h>
using namespace std;
using ll = long long;

signed main() {
    ios::sync_with_stdio(0), cin.tie(0), cout.tie(0);
    int orig[3]{};
    //首先就是 n,m,k的存储方面，因为后面要实时的调整和回复
    //所以直接用数组存一个初始，而不是定义一个 n,m,k读入
    for (int i = 0; i < 3; ++i)cin >> orig[i];
    string a;
    cin >> a;
    //自不必多说，写一个 n 肯定比写一堆好
    const int n = a.size();
    //环的基本处理
    a += a;
    int res = 0;
    for (int s = 0; s < 2; ++s) //用 for来枚举 0,1 起点，而我是写了两个，不仅冗长而且不好debug
    {
        int cur[3]{orig[0], orig[1], orig[2]}; //定义实时变化记录剩余可以使用的 00,01,11
        for (int i = s, j = s; i < n; i += 2) //双指针
        {
            while (j + 2 <= n + i && cur[a[j] - '0' + a[j + 1] - '0']) //这里的 j 指向的是满足的后一位
            {
                cur[a[j] - '0' + a[j + 1] - '0']--;
                j += 2;
            }
            res = max(res, j - i);
            cur[a[i] - '0' + a[i + 1] - '0']++;
        }
    }
    cout << res;
}
