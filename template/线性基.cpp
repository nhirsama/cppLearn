i32 gauss(std::vector<long long> &v) {
    i32 n = v.size();
    i32 k = 0;
    for (i32 i = 62; ~i; i--) {
        for (i32 j = k; j < n; j++) {
            if (v[j] >> i & 1) {
                std::swap(v[j], v[k]);
                break;
            }
        }
        if ((v[k] >> i & 1) == 0) continue;
        for (i32 j = 0; j < n; j++) {
            if (j != k && (v[j] >> i & 1)) v[j] ^= v[k];
        }
        k++;
        if (k == n) break;
    }
    return k;
}