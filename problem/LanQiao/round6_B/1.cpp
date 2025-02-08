#include <bits/stdc++.h>
using namespace std;
int ans = 0;
bool Func(int i){
    string a = to_string(i);
    //cout<<a;
    for(char m :a){
        if(m == '4')
        return false;
    }
    return true;
}
int main()
{
    for(int i =10000;i<=99999;i++){
        if(Func(i))ans++;
    }
    cout << ans;
    return 0;
}