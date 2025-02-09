#include <bits/stdc++.h>
using namespace std;
bool sortcmp(unsigned long long a,unsigned long long b) {
    return a > b;
}
void Func(){
    int n,m;
    cin>>n>>m;
    vector<unsigned long long > v(n);
    unsigned long long sum = 0;
    for(int i=0;i<n;i++) {
        unsigned long long temp = 0,aaaa = 0;
        for(int j=0;j<m;j++) {
            int aa;
            scanf("%d",&aa);
            temp += aa;
            aaaa += temp;
        }
        v[i] = temp;
        sum+=aaaa;
    }
    sort(v.begin(),v.end(),sortcmp);
    for(int i=0;i<n;i++) {
        sum += v[i]*(n-i-1)*m;
    }
    cout<<sum<<endl;
}
int main() {
    int T;
    cin >> T;
    while (T--) {
        Func();
    }
    return 0;
}
