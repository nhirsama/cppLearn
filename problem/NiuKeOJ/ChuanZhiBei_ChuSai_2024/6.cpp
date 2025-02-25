#include <bits/stdc++.h>
using namespace std;
int arr[505][505];
int n,m,k;
map<string,int> mpsi;
map<int ,string> mpis;
string To(string a,char b) {

}
int main(){
    for(int i = 1;i<=k;i++) {
        string aa;
        cin>>aa;
        mpsi.insert({aa,i});
        mpis.insert({i,aa});
    }
    int q;
    cin>>q;
    while(q--) {
        string a;
        char b;
        cin>>a>>b;
        cout<<To(a,b)<<endl;
    }
}