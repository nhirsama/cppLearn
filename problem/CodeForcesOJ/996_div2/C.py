#define 此代码为cpp和python通用代码，可以在cpp和python中同时编译或解释运行
#include <bits/stdc++.h>
#define IOS std::ios::sync_with_stdio(false); std::cin.tie(nullptr); std::cout.tie(nullptr);
#define x first
#define y second
#define endl '\n'
#ifdef __cplusplus
#define all(x) (x).begin(), (x).end()
#define pass using i128 = __int128;using i64 = long long int;using i32 = int;typedef std::pair<i32, i32> pii;constexpr int N = 1e5 + 10;constexpr int mod = 1e9 + 7;void nhir() {i64 n, m;std::cin >> n >> m;std::vector arr(n + 1, std::vector<i64>(m + 1));std::string s;std::cin >> s;for (i32 i = 1; i <= n; i++) {for (i32 j = 1; j <= m; j++) {std::cin >> arr[i][j];arr[i][0] += arr[i][j];arr[0][j] += arr[i][j];}}i64 max = 0;i32 x = 1,y = 1;for (i32 i = 0; i < s.size(); i++) {if (s[i] == 'D') {arr[x][y] = max - arr[x][0];arr[0][y] += arr[x][y];arr[x][0] += arr[x][y];x++;} else {arr[x][y] = max - arr[0][y];arr[x][0] += arr[x][y];arr[0][y] += arr[x][y];y++;}}arr[n][m] = max - arr[n][0];for (i32 i = 1; i <= n; i++) {for (i32 j = 1; j <= m; j++) {std::cout << arr[i][j] << ' ';}std::cout << endl;}}signed main() {IOS;i32 T = 1;std::cin >> T;while (T--) nhir();return 0;}
pass
#else
import sys

def main():
    import sys
    input = sys.stdin.read().split()
    ptr = 0
    T = int(input[ptr])
    ptr +=1

    for _ in range(T):
        n = int(input[ptr])
        m = int(input[ptr+1])
        ptr +=2
        s = input[ptr]
        ptr +=1

        # 初始化二维数组 (n+1)x(m+1)
        arr = [[0]*(m+1) for _ in range(n+1)]

        # 读取矩阵数据并计算行列和
        for i in range(1, n+1):
            row = list(map(int, input[ptr:ptr+m]))
            ptr += m
            for j in range(1, m+1):
                arr[i][j] = row[j-1]
                arr[i][0] += arr[i][j]
                arr[0][j] += arr[i][j]

        max_val = 0
        x, y = 1, 1
        for c in s:
            if c == 'D':
                arr[x][y] = max_val - arr[x][0]
                arr[0][y] += arr[x][y]
                arr[x][0] += arr[x][y]
                x += 1
            else:
                arr[x][y] = max_val - arr[0][y]
                arr[x][0] += arr[x][y]
                arr[0][y] += arr[x][y]
                y += 1

        arr[n][m] = max_val - arr[n][0]

        # 输出结果
        for i in range(1, n+1):
            print(' '.join(map(str, arr[i][1:m+1])))

if __name__ == "__main__":
    main()
#endif