//模板
//记得把文件重定向注释掉
#include <bits/stdc++.h>
using namespace std;
vector<vector<int>> v;
vector<int> temp;
bool sortcmp(vector<int> a, vector<int> b) {
    int i = 0, j = 0;
    while (i < a.size() && j < b.size() && a[i] == b[j]) {
        i++;
        j++;
    }
    if (i == a.size()) {
        return false;
    }
    else if (j == b.size()) {
        return true;
    }
    else {
        return a[i]<b[j];
    }
}
int main() {
#ifdef LOCAL
    freopen("Testlib.in", "r", stdin);
    freopen("Code.out", "w", stdout);
#endif
    ios_base::sync_with_stdio(false);
    int n;
    cin >> n;
    for (int i = 0; i < n; i++) {
        int a;
        cin >> a;
        if(temp.empty()){
            temp.push_back(a);
        }
        else if(a >= temp.back()){
            temp.push_back(a);
        }
        else {
            v.push_back(temp);
            temp.clear();
            temp.push_back(a);
        }
    }
    v.push_back(temp);
    sort(v.begin(), v.end(),sortcmp);
    for (auto &it :v){
        for (auto &itt :it){
            cout << itt << " ";
        }
    }
#ifdef LOCAL
    fclose(stdin);
    fclose(stdout);
#endif
    return 0;
}