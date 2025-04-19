#include <bits/stdc++.h>
using pii = std::pair<int,int> ;
int main() {
    int n;
    std::cin>>n;
    std::vector<pii> t(n);
    for(int i = 0;i<n;i++){
        int bhh,bmm,bss,ehh,emm,ess;
        scanf("%d:%d:%d %d:%d:%d",&bhh,&bmm,&bss,&ehh,&emm,&ess);
        t[i] = {bhh*3600+bmm*60+bss,ehh*3600+emm*60+ess};
    }
    std::sort(t.begin(),t.end());
    std::priority_queue<int,std::vector<int> ,std::greater<>> pq;
    pq.push(-1);
    for(auto [x,y]:t){
        if(pq.top()<x){
            pq.pop();
            pq.push(y);
        }
        else {
            pq.push(y);
        }
    }
    std::cout<<pq.size();
}
