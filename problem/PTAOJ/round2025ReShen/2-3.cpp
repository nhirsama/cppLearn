#include<bits/stdc++.h>
using namespace std;
int main() {
    int n;
    std::cin>>n;
    std::vector<int> tree(2*n+5);
    //for(int i = 1;i<=n;i++) std::cin>>tree[i];
    auto dfs = [&](auto && dfs,int p){
        if(p>n) return;
        dfs(dfs,p*2);
        dfs(dfs,p*2+1);
        std::cin>>tree[p];
        
    };
    dfs(dfs,1);
    for(int i = 1;i<=n;i++){
        std::cout<<tree[i];
        if(i !=n)std::cout<< ' ';
    }
}
