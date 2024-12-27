#include <bits/stdc++.h>
using namespace std;
map<string, int> m;
int dx[] = {3,1,-1,-3};
int A,B;
int bfs(string s){
	queue<string> q;
	q.push(s);
	m.insert({s, 0});
	while(!q.empty()){
		string t = q.front();
		q.pop();
		if(t.find('A') == B && t.find('B') == A) return m[t];
		int Sn = -1;
		for(int i = 0; i < t.length(); i++){
			if(t[i] == 'S') Sn = i;
		}
		for(int i = 0; i < 4; i++) {
			int x = Sn + dx[i];
			if(x<0 || x>5) continue;
			if((Sn == 2  &&  x == 3) || (Sn == 3 && x == 2))continue;
			string temp = t;
			swap(temp[Sn], temp[x]);
			if(m.count(temp)) continue;
			q.push(temp);
			m.insert({temp, m[t] + 1});
		}
	}
	return -1;
}
int main() {
#ifdef LOCAL
	freopen("Testlib.in", "r", stdin);
	freopen("Code.out", "w", stdout);
#endif
	string s1,temp1;
	getline(cin, temp1);
	s1 += temp1;
	getline(cin, temp1);
	s1 += temp1;
	int A,B;
	for(int i = 0; i < s1.length(); i++){
		if(s1[i] == 'A') A = i;
		if(s1[i] == 'B') B = i;
		if(s1[i] == ' ') s1[i] = 'S';
	}
	string endStr = s1;
	swap(endStr[A], endStr[B]);
	cout << bfs(s1)-1 << endl;
#ifdef LOCAL
	fclose(stdin);
	fclose(stdout);
#endif
	return 0;
}