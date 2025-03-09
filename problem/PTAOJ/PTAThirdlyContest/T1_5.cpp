#include<bits/stdc++.h>
using namespace std;
using ll = long long;
int main() {
    string s;
    ll cm  = 0,yc = 0;
    vector<string > cmm,ycc;
    while(cin>>s) {
        int cnt = 0;
        for(auto i:s) {
            if(i=='a' || i=='e' || i=='o' || i=='u' || i =='i') {
                cnt++;
            }
        }
        if(s.size()%2==0 || cnt&1) {
            cmm.push_back(s);
            cm++;
        } else {
            yc++;
            ycc.push_back(s);
        }
    }
    cout<<cm<<endl;
    cout<<yc<<endl;
    if(cm) {
        sort(cmm.begin(),cmm.end(),[&](auto a,auto b){if(a.size()==b.size())return a>b;return a.size()<b.size();});
        cout<<cmm.back()<<endl;
    } else {
        cout<<"None"<<endl;
    }
    if(yc) {
        sort(ycc.begin(),ycc.end(),[&](auto a,auto b){if(a.size()==b.size())return a>b;return a.size()<b.size();});
        cout<<ycc.back();
    } else {
        cout<<"None";
    }
    return 0;
}