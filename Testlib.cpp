#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

int main() {
    int n;
    cin >> n;

    vector<int> p(n);  // 存储每只喵喵的到达顺序
    for (int i = 0; i < n; ++i) {
        cin >> p[i];
    }

    // 1. 创建一个存储(到达时间, 索引)的结构体
    vector<pair<int, int>> order(n);
    for (int i = 0; i < n; ++i) {
        order[i] = {p[i], i};  // 到达时间和索引配对
    }

    // 2. 按到达时间排序
    sort(order.begin(), order.end());

    // 3. 分组
    vector<vector<int>> groups;
    vector<int> current_group;

    // 遍历所有喵喵，进行分组
    for (int i = 0; i < n; ++i) {
        // 如果当前喵喵的到达时间是连续的，可以放在同一组
        if (i == 0 || order[i].second > order[i-1].second) {
            if (!current_group.empty()) {
                groups.push_back(current_group);
            }
            current_group = {order[i].first};  // 新的一组
        } else {
            current_group.push_back(order[i].first);  // 加入当前组
        }
    }
    if (!current_group.empty()) {
        groups.push_back(current_group);  // 最后一组
    }

    // 4. 生成最终结果，按字典序输出
    vector<int> result;
    for (auto& group : groups) {
        sort(group.begin(), group.end());  // 每组内部按到达时间排序
        result.insert(result.end(), group.begin(), group.end());
    }

    // 输出结果
    for (int i = 0; i < n; ++i) {
        cout << result[i] << " ";
    }
    cout << endl;

    return 0;
}
