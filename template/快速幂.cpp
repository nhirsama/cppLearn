//
// Created by zxy15 on 25-8-5.
//
int power(long long _a, long long b, int p) {
    int res = 1;
    int a = _a % p;
    for (; b; b /= 2, a = 1LL * a * a % p) {
        if (b % 2) {
            res = 1LL * res * a % p;
        }
    }
    return res;
}