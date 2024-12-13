#define LOCAL
//P4407 [JSOI2009] 电子字典
//记得把文件重定向注释掉
#include <bits/stdc++.h>
using namespace std;
int N,M;
int Trie[200105][27];
int cnt[200105];
int idx = 0;
long long FindTrie(string &s) {
    int p = 0;
    for(char i :s) {
        if(!Trie[p][i-'a']) {
            p = 0;
            break;
        }
        p = Trie[p][i-'a'];
    }
    if(cnt[p] && p)return p;
    return false;
}
long long dfs(string &s) {
    bool visit[200105] = {};
    long long ans = 0;
    if(FindTrie(s)) return -1;
    //删除
    for(int i = 0;i<s.size();i++) {
        string temp = s.substr(0,i)+s.substr(i+1);
        long long a = FindTrie(temp);
        if(a && !visit[a]) {
            ans+=1;
            visit[a] = true;
        }
    }
    //添加
    for(int i = 0;i<=s.size();i++) {
        for(char j = 'a';j<='z';j++) {
            string temp = s.substr(0,i)+j+s.substr(i);
            long long a = FindTrie(temp);
            //cout<<temp<<endl;
            if(a && !visit[a]) {
                ans+=1;
                visit[a] = true;
            }
            if(j == s[i])continue;
            if(i == s.size()) continue;
            temp = s.substr(0,i)+j+s.substr(i+1);
            a = FindTrie(temp);
            if(a && !visit[a]) {
                ans+=1;
                visit[a] = true;
            }
        }
    }
    return ans;
}
int main() {
#ifdef LOCAL
    freopen("Testlib.in", "r", stdin);
    freopen("Code.out", "w", stdout);
#endif
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);cout.tie(nullptr);
    cin>>N>>M;
    for(int i=0;i<N;i++){
        string s;
        cin>>s;
        int p = 0;
        for(char j:s){
            if(Trie[p][j-'a']){
                p=Trie[p][j-'a'];
            }
            else{
                Trie[p][j-'a']=++idx;
                p = idx;
            }
        }
        cnt[p]=1;
    }
    for(int i = 0;i<M;i++) {
        string s;
        cin>>s;
        cout<<dfs(s)<<'\n';
    }
    cout<<endl;

#ifdef LOCAL
    fclose(stdin);
    fclose(stdout);
#endif
    return 0;
}