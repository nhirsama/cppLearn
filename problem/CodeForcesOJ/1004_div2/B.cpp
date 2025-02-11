#include <bits/stdc++.h>
using namespace std;
const int N = 2e5+10;
typedef long long ll;
void Func(){
    int n;
    cin>>n;
    vector<int> v(1005);
    for(int i=1;i<=n;i++){
        int a;
        scanf("%d",&a);
        v[a]++;
    }
    for(int i=1;i<=1000;i++){
        if(v[i]==0){
            continue;
        }
        if(v[i]==2){}
        else if(v[i]&1 && v[i]>2) v[i+1] += v[i]-2,v[i] = 2;
        else if(!(v[i]&1)) v[i+1] += v[i]-2,v[i] = 2;
        if(v[i]&1) {
            puts("No");
            return;
        }
    }
    puts("Yes");
}
int main() {
    int T;
    cin >> T;
    while (T--) {
        Func();
    }
    return 0;
}
