//
// Created by zxy15 on 25-4-16.
//
#include <bits/stdc++.h>
using namespace std;
int main(){
    int n,m,s;
    cin>>n>>m>>s;
    vector<queue<char> > v(101);
    stack<int> ss;
    for (int i = 1;i<=n;i++) {
        for (int j = 1;j<=m;j++) {
            char c;
            cin>>c;
            v[i].push(c);
        }
    }
    int op;
    string ans;
    while (true) {
        cin>>op;
        if (op == -1) break;
        else if (op == 0){
            if (!ss.empty()) {
                ans.push_back(ss.top());
                ss.pop();
            }
        }
        else {
            if (!v[op].empty()) {
                if (ss.size()>=s) {
                    ans.push_back(ss.top());
                    ss.pop();
                }
                ss.push(v[op].front());
                v[op].pop();
            }
        }
    }
    cout<<ans<<endl;
}