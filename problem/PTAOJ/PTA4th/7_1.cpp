#include <bits/stdc++.h>
using namespace std;
using i64 = long long;
using i32 = int;
using pii = pair<i32, i32>;

int main() {
    string s;
    cin >> s;
    std::vector<int> last(30, -1);
    for (int i = 0; i < s.size(); i++) {
        last[s[i] - 'a'] = i;
    }
    std::vector<bool> st(26);
    std::string ans;
    for (int i = 0; i < s.size(); i++){
        char c = s[i];
        if (st[c - 'a']) continue;

        while (!ans.empty() && ans.back() < c && last[ans.back() - 'a'] > i) {
            st[ans.back() - 'a'] = false;
            ans.pop_back();
        }
        ans.push_back(c);
        st[c - 'a'] = true;
    }
    // for (i32 i = 0; i < s.size(); i++) {
    //     if (st[s[i] - 'a']) continue;
    //     bool flag = false;
    //     for (i32 j = s[i] - 'a' + 1; j < 26; j++) {
    //         if (last[j] != -1) flag = true;
    //     }
    //     if (flag == true && i < last[s[i] - 'a'])continue;
    //     ans.push_back(s[i]);
    //     st[s[i] - 'a'] = true;
    //     last[s[i] - 'a'] = -1;
    // }
    // for(i32 i = 0;i<s.size();i++){
    //     cnt[i] = {i,s[i]};
    // }
    // sort(cnt.begin(),cnt.end(),[](auto a,auto b){if(a.second == b.second) return a.first<b.first;return a.second>b.second;});
    // string ans;
    // vector<i32> st(26);
    // for(auto i:cnt){
    //     if(st[i.second-'a'])continue;
    //     ans.push_back(i.second);
    //     st[i.second-'a'] =  1;
    // }
    //	for(char i:s) {
    //		cnt[i-'a']++;
    //	}
    //	string ans;
    //	vector<i64> st(27,0);
    //	for(char i:s) {
    //		if(st[i-'a'])continue;
    //		if(cnt[i-'a']>1) {
    //			i64 sum = 0;
    //			for(i32 j = i-'a'+1; j<26; j++)if(cnt[j]>1)sum+=cnt[j];
    //			if(sum) {
    //				cnt[i-'a']--;
    //				continue;
    //			}
    //			ans.push_back(i);
    //			cnt[i-'a'] = 0;
    //			st[i-'a'] = 1;
    //		} else if(cnt[i-'a'] == 1) {
    //			ans.push_back(i);
    //			cnt[i-'a'] = 0;
    //			st[i-'a'] = 1;
    //		}
    //	}
    cout << ans << endl;
    return 0;
}
