#include <bits/stdc++.h>
using namespace std;
const int N = 2e5+10;
struct number{
    vector<char> n;
    number operator+(const number &b)const {
        number ans;
        ans.n = vector<char>(max(n.size(),b.n.size())+1);

        for(int i = 0; i < max(n.size(),b.n.size()); i++) {
            if (i<n.size()) {
                ans.n[i] += n[i];
            }
            if (i<b.n.size()) {
                ans.n[i] += b.n[i];
            }
            ans.n[i+1]+=ans.n[i]/10;
            ans.n[i]%=10;
        }
        while (ans.n.size()>1 && ans.n.back()==0) ans.n.pop_back();
        return ans;
    }
};
long long n,k;
int arr[N];
int main() {
    cin>>n>>k;
    long long ans=k*(k+1)/2;
    for (int i = 0; i < n; i++) {
        scanf("%d",arr+i);
    }
    sort(arr,arr+n);
    auto it = unique(arr,arr+n)-arr;
    for (int i = 0; i < it; i++) {
        if (arr[i]<=k)ans-=arr[i];
    }
    cout<<ans<<endl;
    return 0;
}