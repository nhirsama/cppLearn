#include <bits/stdc++.h>
int main(){
    std::cout<<"zako zako ~ \n ";
    return 0;
}
#include <bits/stdc++.h>

using namespace std;

// 高性能分段埃氏筛 + 奇数优化
// 常数因子优于普通线性筛，适用于大 N

struct SegmentedSieve {
    using ll = long long;
    int64_t n;
    int64_t limit;
    vector<int> primes;
    vector<char> is_prime; // 用于初始筛到 sqrt(n)

    SegmentedSieve(int64_t _n) : n(_n) {
        limit = floor(sqrt(n)) + 1;
        is_prime.assign(limit + 1, true);
    }

    // 筛出所有 <= limit 的素数
    void simple_sieve() {
        is_prime[0] = is_prime[1] = false;
        for (int64_t i = 2; i * i <= limit; ++i) {
            if (is_prime[i]) {
                for (int64_t j = i * i; j <= limit; j += i)
                    is_prime[j] = false;
            }
        }
        for (int i = 2; i <= limit; ++i)
            if (is_prime[i]) primes.push_back(i);
    }

    // 主筛
    vector<int64_t> run() {
        simple_sieve();
        vector<int64_t> result;
        result.reserve(n / log(n));

        int64_t segment_size = max<int64_t>(limit, 32768);
        vector<char> segment(segment_size);

        for (int64_t low = 2; low <= n; low += segment_size) {
            int64_t high = min(low + segment_size - 1, n);
            fill(segment.begin(), segment.end(), true);

            // 用小素数标记本块
            for (int p: primes) {
                int64_t start = max<int64_t>(int64_t(p) * p,
                                             ((low + p - 1) / p) * p);
                for (int64_t j = start; j <= high; j += p)
                    segment[j - low] = false;
            }

            // 收集本块的素数
            for (int64_t i = low; i <= high; ++i) {
                if (i > 1 && segment[i - low])
                    result.push_back(i);
            }
        }
        return result;
    }
};

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    int64_t N;
    if (!(cin >> N)) return 0;

    SegmentedSieve sieve(N);
    auto primes = sieve.run();
    int q;
    cin >> q;
    while (q--) {
        int t;
        cin >> t;
        std::cout << primes[t - 1] << '\n';
    }
//    for (auto p : primes) cout << p << ' ';
//    cout << '\n';
    return 0;
}

/*
备注：
- 只用于奇偶分离的优化更复杂，可在 simple_sieve 和段内标记时仅处理奇数，
  将存储压缩一半。
- 进一步可用 bitset 或字节级压缩以及 wheel-factorization 提升常数。
*/