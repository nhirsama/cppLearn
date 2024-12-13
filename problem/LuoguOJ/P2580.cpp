#define LOCAL
//P2580 于是他错误的点名开始了
//记得把文件重定向注释掉
#include <bits/stdc++.h>
using namespace std;
int n,m;
int Trie[500005][27];
int cnt [500005];
int visited[500005];
int idx = 0;
void Init(){
    for(int i = 0; i < n; i++){
        string str;
        cin >> str;
        int p = 0;
        for(char &j:str){
            if(Trie[p][j-'a']){
                p = Trie[p][j-'a'];
            }
            else {
                Trie[p][j-'a'] = ++idx;
                p = idx;
            }
        }
        cnt[p] = 1;
    }
}
void visitTrie(){
    for(int i = 0; i < m ;i++){
        string str;
        cin >> str;
        int p = 0;
        for(char &j:str){
            if(Trie[p][j-'a']){
                p = Trie[p][j-'a'];
            }
            else {
                break;
            }
        }
        if(cnt[p] && !visited[p]){
            cout<<"OK\n";
            visited[p] = 1;
        }
        else if (cnt[p] && visited[p]){
            cout<<"REPEAT\n";
        }
        else {
            cout<<"WRONG\n";
        }
    }
    cout<<endl;
}

int main() {
    #ifdef LOCAL
    freopen("Testlib.in", "r", stdin);
    freopen("Code.out", "w", stdout);
    #endif
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    cout.tie(nullptr);
    cin >> n;
    Init();
    cin >> m;
    visitTrie();
    #ifdef LOCAL
    fclose(stdin);
    fclose(stdout);
    #endif
    return 0;
}