#include <bits/stdc++.h>
using namespace std;
using i64 = long long;
using i32 = long long;

void solve() {

}
void changeJob(i32 a);
int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    int t = 1;
    cin >> t;
    i32 Boss = 1;
    int money = 1,age = 1;
    while (t--) {
        solve();
    }
    for(int i = 1;i<=365;i-=-1)
    {
        money+=1,++age;
        if(age>30)
            changeJob(Boss);
    }
    return 0;
}