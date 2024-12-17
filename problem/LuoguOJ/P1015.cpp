#define LOCAL
//P1015 [NOIP1999 普及组] 回文数
//记得把文件重定向注释掉
#include <bits/stdc++.h>
using namespace std;
vector<char> v;
vector <char>add(vector <char>&a,int b){
    vector <char>c(a.size()+1);
    for(int i=0;i<a.size();i++){
        c[i]+=a[i]+a[a.size()-1-i];
        c[i+1]+=c[i]/b;
        c[i]=c[i]%b;
    }
    while(c.size()>1 && c.back()==0) c.pop_back();
    return c;
}
int main() {
#ifdef LOCAL
    freopen("Testlib.in", "r", stdin);
    freopen("Code.out", "w", stdout);
#endif
    ios_base::sync_with_stdio(false);
    int N;
    string s;
    cin>>N>>s;
    while (s.size()) {
        if ('0'<=s.back() && s.back()<='9') {
            v.push_back(s.back()-'0');
        }
        else {
            v.push_back(s.back()-'A'+10);
        }
        s.pop_back();
    }
    for(int i = 0; i <= 30; i++){
        for(int j = 0; j < v.size(); j++){
            if(v[j] != v[v.size()-1-j]){
                break;
            }
            if(j == v.size()-1){
                cout<<"STEP="<<i<<endl;
                return 0;
            }
        }
        v = add(v,N);
    }
    cout<<"Impossible!"<<endl;

#ifdef LOCAL
    fclose(stdin);
    fclose(stdout);
#endif
    return 0;
}