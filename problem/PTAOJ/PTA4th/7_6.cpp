#include <bits/stdc++.h>
using namespace std;
using i64 = long long;
using i32 = int;
using pii = pair<i32,i32> ;
vector<i32> root(1e5+10);
i32 find(i32 u){
	return root[u] == u? u: root[u] = find(root[u]);
}
int main(){
	for(i32 i = 1;i<=1e5;i++) root[i] = i;
	i64 n,m;
	cin>>n>>m;
	for(i32 i = 1;i<=m;i++){
		i32 u,v;
		cin>>u>>v;
		root[find(u)] = find(v);
	}
	i32 q;
	cin >>q;
	for(i32 i = 1;i<=q;i++){
		i32 u,v;
		cin>>u>>v;
		if(find(u) == find(v)){
			cout<<"Yes\n";
		}
		else {
			cout<<"No\n";
		}
	}
	return 0;
}
