#define LOCAL
//P4551 最长异或路径
//记得把文件重定向注释掉
#include <bits/stdc++.h>
using namespace std;
const int N = 100000 + 10;
int _01trie[N * 8][2], n,cnt = 0 ;
int tree[N];

void get_trie(int w) {
    int root = 0;
    while (w) {
        if (w & 1) {
            if (_01trie[root][1]) {
                root = _01trie[root][1];
            }
            else {
                _01trie[root][1] = ++cnt;

            }

            _01trie[cnt] = 1;
        } else {
            cnt = cnt * 2;
            _01trie[cnt] = 2;
        }
        w >>= 1;
    }
}

int main() {
#ifdef LOCAL
    freopen("Testlib.in", "r", stdin);
    freopen("Code.out", "w", stdout);
#endif
    cin >> n;
    for (int i = 0; i < n; i++) {
        int a,b;
        scanf("%d%d%d", &a,&b,&tree[i]);
        get_trie(tree[i]);
    }
    int ans = 0;
    for (int i = 0; i < n; i++) {
        int w = tree[i], cnt = 1, ve = 0;
        int num = 31;
        while (num--) {
            if (w & 1) {
                cnt = cnt * 2;
                if (_01trie[cnt] == 0) {
                    if (_01trie[++cnt]) {
                        ve <<= 1;
                        w >>= 1;
                    }
                    else {
                        ans = max(ans, ve);
                        break;
                    }
                }
                else {
                    ve <<= 1;
                    w = w >> 1;
                    ve++;
                }
            } else {
                cnt = cnt * 2 + 1;
                if (_01trie[cnt] == 0) {
                    if (_01trie[--cnt]) {
                        ve <<= 1;
                        w >>= 1;
                    }
                    else {
                        ans = max(ans, ve);
                        break;
                    }
                }
                else {
                    ve <<= 1;
                    w = w >> 1;
                    ve++;
                }
            }
        }
    }
    cout << ans << endl;
#ifdef LOCAL
    fclose(stdin);
    fclose(stdout);
#endif
    return 0;
}
