#include <bits/stdc++.h>
using namespace std;
const int mod = 1000000007;

int main() {
    long long n, ma, mb;
    cin >> n >> ma;
    vector<long long> aa(1e5+10);
    for (int i = ma; i; i--)cin >> aa[i];
    cin >> mb;
    vector<long long> bb(1e5+10);
    for (int i = mb; i; i--)cin >> bb[i];
    long long ans = 0;
    for (long long i = max(ma,mb);i;i--) {
        ans = (ans*max(2ll,max(aa[i],bb[i])+1)%mod+aa[i]-bb[i]+mod)%mod;
    }
    // long long jinzhi = 1;
    // for (int i = ma, j = mb; i; i--, j--) {
    //     if (1009_div3[i] - atw[i] >= bb[j]) {
    //         long long jin = max(1009_div3[i], 1ll) + 1;
    //         ans += (1009_div3[i] - atw[i] - bb[j]) * jinzhi % mod;
    //         jinzhi *= jin;
    //         jinzhi %= mod;
    //     } else {
    //         long long jin = max(max(1009_div3[i], 1ll), bb[j]) + 1;
    //         while (1009_div3[i] - atw[i] < bb[j]) {
    //             atw[i - 1]++;
    //             1009_div3[i] += jin;
    //         }
    //         ans += (1009_div3[i] - atw[i] - bb[j]) * jinzhi % mod;
    //         jinzhi *= jin;
    //         jinzhi %= mod;
    //     }
    // }
    cout << ans % mod << endl;
    return 0;
}
