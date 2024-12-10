#define LOCAL
//P3375 【模板】KMP
//记得把文件重定向注释掉
#include <bits/stdc++.h>
using namespace std;
vector<int> get_next(string v){
    vector<int> next;
    int j = 0;
    next.push_back(0);
    for(int i = 1; i < v.size(); i++){
        while(j>0 && v[j] != v[i]){
            j = next[j-1];
        }
        if(v[j] == v[i]){
            j++;
        }
        next.push_back(j);
    }
    return next;
}
int main() {
#ifdef LOCAL
    freopen("Testlib.in", "r", stdin);
    freopen("Code.out", "w", stdout);
#endif
    string s,p;
    cin >> s >> p;
    vector<int> nextArr = get_next(p);
    int i = 0, j = 0;
    for(; i < s.size(); i++){
        while(j>0 && s[i] != p[j]){
            j = nextArr[j-1];
        }
        if(s[i] == p[j]){
            j++;
        }
        if(j == p.size()){
            cout << i-j+2 << endl;
            j = nextArr[j-1];
        }
    }
    for (int a : nextArr) {
        cout << a << ' ';
    }
#ifdef LOCAL
    fclose(stdin);
    fclose(stdout);
#endif
    return 0;
}