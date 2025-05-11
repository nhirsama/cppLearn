//
// Created by ling on 25-5-11.
//
#include <bits/stdc++.h>
using namespace std;
using i32 = long long;

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    i32 n;
    std::cin >> n;
    string s;
    std::cin >> s;
    vector<i32> dp(27);
    string ans;
    for (auto i: s) {
        dp[i - 'a']++;
        if (dp[i - 'a'] == 5 && ans.size() == 0) {
            dp = vector<i32>(27);
            ans.push_back(i);
        }
        if (dp[i - 'a'] == 7 && ans.size() == 1) {
            dp = vector<i32>(27);

            ans.push_back(i);
        }
        if (dp[i - 'a'] == 5 && ans.size() == 2) {
            dp = vector<i32>(27);

            ans.push_back(i);
            break;
        }
    }
    if (ans.size() == 3) {
        for (i32 i = 0; i < 5; i++) {
            std::cout << ans[0];
        }
        for (i32 i = 0; i < 7; i++) std::cout << ans[1];
        for (i32 i = 0; i < 5; i++) std::cout << ans[2];
        cout << '\n';
    } else std::cout << "none\n";
    //std::cout<<ans<<endl;
}
