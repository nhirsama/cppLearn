#include <bits/stdc++.h>
using namespace std;
using i64 = long long;
using i32 = int;
using pii = pair<i32,i32> ;
int main() {
	string s;
	cin>>s;
	vector<i64> cnt(27,0);
	for(char i:s) {
		cnt[i-'a']++;
	}
	string ans;
	vector<i64> st(27,0);
	for(char i:s) {
		if(st[i-'a'])continue;
		if(cnt[i-'a']>1) {
			i64 sum = 0;
			for(i32 j = i-'a'+1; j<26; j++)if(cnt[j]>1)sum+=cnt[j];
			if(sum) {
				cnt[i-'a']--;
				continue;
			}
			ans.push_back(i);
			cnt[i-'a'] = 0;
			st[i-'a'] = 1;
		} else if(cnt[i-'a'] == 1) {
			ans.push_back(i);
			cnt[i-'a'] = 0;
			st[i-'a'] = 1;
		}
	}
	cout<<ans<<endl;
	return 0;
}
