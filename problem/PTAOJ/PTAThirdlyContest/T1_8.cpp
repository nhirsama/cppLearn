#include<bits/stdc++.h>
using namespace std;
using ll = long long;
int main() {
    int q;
    cin>>q;
    deque<int> dq;
    while(q--){
        int op;
        cin>>op;
        if(op == 1){
            int x;
            cin>>x;
            dq.push_back(x);
        }
        if(op == 2){
            if(!dq.empty()) dq.pop_front();
        }
        if(op == 3){
            int d;
            cin>>d;
            if(dq.empty())continue;
            int aa = dq.front();
            dq.pop_front();
            aa-=d;
            if(aa>0)dq.push_front(aa);
        }
        if(op == 4){
            if(!dq.empty())
                cout<<dq.front()<<endl;
            else cout<<0<<endl;
        }
    }
    return 0;
}