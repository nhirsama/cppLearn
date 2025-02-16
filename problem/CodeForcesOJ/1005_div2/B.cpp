#include <bits/stdc++.h>
using namespace std;
constexpr int N = 2e5+10;
typedef long long ll;
void Func(){
    int n;
    cin>>n;
    vector<int> a(n+1),cnt(n+1,-1),sco(n+1);
    for(int i=1;i<=n;i++){
        scanf("%d",&a[i]);
        cnt[a[i]]++;
    }
    int ans=0,l = 1,maxans = 0,ansl = 0;
    for(int i=1;i<=n;i++){
        if(cnt[a[i]] == 0){
            ans++;
            if(ans>maxans){
                maxans = ans;
                ansl = l;
            }
        }
        else {
            ans = 0;
            l = i+1;
        }
    }
    if(maxans)cout<<ansl<<' '<<ansl+maxans-1<<endl;
    else cout <<0<<endl;
}
int main() {
    #ifdef LOCAL
    freopen("Testlib.in", "r", stdin);
    //freopen("Code.out", "w", stdout);
    #endif
    int T;
    cin >> T;
    while (T--) {
        Func();
    }
    return 0;
}
