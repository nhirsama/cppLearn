/*

//模板
//记得把文件读写流和define注释掉
#include <bits/stdc++.h>
using namespace std;
int main() {
    #define cin fin
    #define cout fout
    ifstream fin("Testlib.in");
    ofstream fout("Code.out");

    return 0;
}

*/

#define LOCAL
//模板
//记得把文件重定向注释掉
#include <bits/stdc++.h>
using namespace std;
int main() {
    #ifdef LOCAL
    freopen("Testlib.in", "r", stdin);
    freopen("Code.out", "w", stdout);
    #endif


    #ifdef LOCAL
    fclose(stdin);
    fclose(stdout);
    #endif
    return 0;
}