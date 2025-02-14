#include <iostream>
#include <algorithm>

using namespace std;

int main() {
    int a1, a2, a3, b1, b2, b3;
    int c1, c2, c3, d1, d2, d3;

    // 输入两个积木的区间
    cin >> a1 >> a2 >> a3 >> b1 >> b2 >> b3;
    cin >> c1 >> c2 >> c3 >> d1 >> d2 >> d3;

    // 计算每个维度上的重叠部分
    int overlap_x = max(0, min(b1, d1) - max(a1, c1) + 1);
    int overlap_y = max(0, min(b2, d2) - max(a2, c2) + 1);
    int overlap_z = max(0, min(b3, d3) - max(a3, c3) + 1);

    // 如果任何一个维度没有重叠，则整体没有重叠
    if (overlap_x > 0 && overlap_y > 0 && overlap_z > 0) {
        // 计算重叠体积
        cout << overlap_x * overlap_y * overlap_z << endl;
    } else {
        // 如果没有重叠
        cout << 0 << endl;
    }

    return 0;
}
