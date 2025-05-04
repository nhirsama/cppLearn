#include <bits/stdc++.h>

int main() {
    std::ios::sync_with_stdio(false);
    std::cin.tie(nullptr);
    int n;
    std::cin >> n;
    int cnt[100][100]{};
    int dx[] = {-1, -1, 0, 0};
    int dy[] = {-1, 0, -1, 0};
    int dcnt[] = {1, 2, 8, 4};
    for (int _ = 0; _ < n; _++) {
        int x, y;
        std::cin >> x >> y;
        for (int i = 0; i < 4; i++) {
            int ix = x + dx[i];
            int iy = y + dy[i];
            cnt[ix][iy] |= dcnt[i];
            //std::cout << cnt[ix][iy] << std::endl;
        }
    }
    double ans = 0;
    for (int i = 0; i < 100; i++) {
        for (int j = 0; j < 100; j++) {
            int base = cnt[i][j];
            if (!cnt[i][j]) continue;
            if ((cnt[i][j] & 0b0101) == 0b0101) {
                ans += 1;
            } else if ((cnt[i][j] & 0b1010) == 0b1010) {
                ans += 1;
            } else if ((base & 0b0011) == 0b0011 || (base & 0b1100) == 0b1100 || (base & 0b1001) == 0b1001 || ( base & 0b0110) == 0b0110) {
                ans += 0.75;
            } else if (base) {
                ans += 0.5;
            }
        }
    }
    printf("%.10f", ans);
    //std::cout << ans << std::endl;
}
