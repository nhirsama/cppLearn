#define LOCAL
#include <stdio.h>
#include <string.h>
#include <ctime>
#define min(a, b) (((a) < (b)) ? (a) : (b))
#define max_primes ((160000))
#define sieve_span ((1 << 22))
#define sieve_words ((sieve_span >> 7))
#define wheel_size ((3 * 5 * 7 * 11 * 13))
typedef long long ll;
typedef unsigned long long ull;

int rd() {
    int k = 0;
    char c = getchar();
    while (c < '0' || c > '9')
        c = getchar();

    while (c >= '0' && c <= '9') {
        k = (k << 1) + (k << 3) + (c ^ 48);
        c = getchar();
    }
    return k;
}
void wr(int x) {
    if (x > 9)wr(x / 10);
    putchar(x % 10 + '0');
}


ull mask[64];//mask[i] = 1ull << i

void build_mask() {
    mask[0] = 1ull; for (int i = 1; i < 64; ++i) mask[i] = mask[i - 1] << 1ull;
}

int primes[max_primes], mcnt;
ull sieve[sieve_words];
ull pattern[wheel_size];
int all[50000000 + sieve_span], pcnt;
void mark(ull *s, int o) {
    s[o >> 6] |= mask[o & 63];
}
void unmark(ull *s, int o) {
    s[o >> 6] &= ~mask[o & 63];
}
int test(ull *s, int o) {
    return (s[o >> 6] & mask[o & 63]) == 0;
}

void update_sieve(int base) {
    int o = base % wheel_size;
    o = (o + ((o * 105) & 127) * wheel_size) >> 7;
    for (int i = 0, k; i < sieve_words; i += k, o = 0) {
        k = min(wheel_size - o, sieve_words - i);
        memcpy(sieve + i, pattern + o, sizeof(*pattern) * k);
    }
    if (base == 0) { // mark 1 as not prime, and mark 3, 5, 7, 11, and 13 as prime
        sieve[0] |= mask[0];
        sieve[0] &= ~(mask[1] | mask[2] | mask[3] | mask[5] | mask[6]);
    }
    for (int i = 0; i < mcnt; ++i) {
        ll j = primes[i] * primes[i];
        if (j > base + sieve_span - 1) break;
        if (j > base) j = (j - base) >> 1;
        else {
            j = primes[i] - base % primes[i];
            if ((j & 1) == 0) j += primes[i];
            j >>= 1;
        }
        while (j < sieve_span >> 1) {
            mark(sieve, j);
            j += primes[i];
        }
    }
}
void pre_sieve() {
    for (int i = 0; i < (1048576 >> 7); ++i) sieve[i] = 0;
    for (int i = 3; i < 1024; i += 2) {
        if (test(sieve, i >> 1)) {
            for (int j = (i * i) >> 1; j < 1048576; j += i) mark(sieve, j);
        }
    }
    mcnt = 0;
    for (int i = 8; i < 1048576; ++i) {
        if (test(sieve, i)) primes[mcnt++] = (i << 1) + 1;
    }
    //printf("m is %d\n", m);
    for (int i = 0; i < wheel_size; ++i) pattern[i] = 0;
    for (int i = 1; i < wheel_size * 64; i += 3) mark(pattern, i);
    for (int i = 2; i < wheel_size * 64; i += 5) mark(pattern, i);
    for (int i = 3; i < wheel_size * 64; i += 7) mark(pattern, i);
    for (int i = 5; i < wheel_size * 64; i += 11) mark(pattern, i);
    for (int i = 6; i < wheel_size * 64; i += 13) mark(pattern, i);
}
//sieve [base, min(base+span, lim)]
void segment_sieve(int base, int lim) {
    update_sieve(base);
    int u = min(base + sieve_span, lim);
    for (int i = 0; i < sieve_words; ++i) {
        ull o = ~sieve[i];
        while (o) {
            int p = __builtin_ctzll(o);
            int u = base + (i << 7) + (p << 1) + 1;
            if (u >= lim) break;
            all[pcnt++] = u;
            o -= o & ((~o) + 1);
        }
    }
}

//sieve from [0, n)
void fast_sieve(int lim) {
    pre_sieve();
    all[pcnt++] = 2;
    int i = 0, now = 1;
    for (int base = 0; base < lim; base += sieve_span)
        segment_sieve(base, lim);
}

int T;

int main() {
#ifdef LOCAL
    clock_t start,end1;
    start = clock();
    freopen("inAndoutFile/P3383_1.in", "r", stdin);
    freopen("Code.out", "w", stdout);
#endif
    build_mask();
    int n = rd();
    fast_sieve(n);
    T = rd();
    while (T--) wr(all[rd() - 1]), putchar('\n');
#ifdef LOCAL
    end1 = clock();
    double time_spent = (double) (end1 - start) / CLOCKS_PER_SEC;
    printf("%.3lf\n", time_spent);
    fclose(stdin);
    fclose(stdout);
#endif
    return 0;
}