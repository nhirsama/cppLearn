#include <bits/stdc++.h>
using namespace std;
const int N = 1e5 + 10;
vector<vector<int> > g;
int arr[N];
int n = 0;

int main() {
    cin >> n;
    for (int i = 1; i <= n; i++) {
        scanf("%d", &arr[i]);
    }
    sort(arr + 1, arr + n + 1);
    for (int i = 1; i <= n; i++) {
        bool flag = true;
        for (auto & j : g) {
            if (arr[i] > j.size()) {
                j.push_back(arr[i]), flag = false;
                break;
            }
        }
        if (flag) {
            g.push_back(vector<int>(1, arr[i]));
        }
    }
    cout << g.size() << endl;
    return 0;
}
