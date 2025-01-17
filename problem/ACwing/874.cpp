#include <bits/stdc++.h>
using namespace std;
const int N = 1e6 + 10;
int prime[N], cnt, phi[N];
bool notprime[N];
long long ans = 0;

void ora(int n) {
    phi[1] = 1;
    notprime[1] = true;
    for (int i = 2; i <= n; i++) {
        if (!notprime[i]) {
            prime[cnt++] = i;
            phi[i] = i - 1;
        }
        for (int j = 0; prime[j] <= n / i; j++) {
            notprime[i * prime[j]] = true;
            if (i % prime[j] == 0) {
                phi[i * prime[j]] = phi[i] * prime[j];
                break;
            }
            phi[i * prime[j]] = phi[i] * (prime[j] - 1);
        }
    }
}

int main() {
    int n;
    cin >> n;
    ora(n);
    for (int i = 1; i <= n; i++) {
        ans += phi[i];
    }
    cout << ans;
    return 0;
}
