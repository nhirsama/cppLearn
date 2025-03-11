#include <bits/stdc++.h>
using namespace std;
const int N = 2e5 + 10;
typedef long long int ll;
#define first x;
#define second y;
ll n, arr[N], k, ans,sum;
int main() {
    cin >> n>> k;
    for (int i = 1; i <= n; ++i) {
        cin >> arr[i];
    }
    unordered_map<long long, int> mp;
    mp[0] = 1;
    for (int i = 1; i <= n; ++i) {
        sum += arr[i];
        long long temp = sum - k;
        if (mp.find(temp) != mp.end()) {
            ans += mp[temp];
        }
        mp[sum]++;
    }

    cout << ans << endl;
    return 0;
}
