#define LOCAL
//P1305 新二叉树
//记得把文件重定向注释掉
#include <bits/stdc++.h>
using namespace std;
const int N = 257;
int idx = 0,root[N][2];
void add(char x,char y,char z){
    if(y == '*') y = 0;
    if(z == '*') z = 0;
    root[x][0] = y;
    root[x][1] = z;
}
void dfs(int a){
    cout<<static_cast<char>(a);
    for(int &i : root[a]) {
        if(i)dfs(i);
    }
}
int main() {
#ifdef LOCAL
    freopen("Testlib.in", "r", stdin);
    freopen("Code.out", "w", stdout);
#endif
    int n;
    cin >> n;
    char father = 0;
    for(int i = 0; i < n; i++){
        char a,b,c;
        cin >> a >> b >> c;
        if(i == 0)  father = a;
        add(a,b,c);
    }
    dfs(father);
    cout<<endl;

#ifdef LOCAL
    fclose(stdin);
    fclose(stdout);
#endif
    return 0;
}