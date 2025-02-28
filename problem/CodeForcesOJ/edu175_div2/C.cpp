#define LOCAL
#include <bits/stdc++.h>
using namespace std;
constexpr int N = 1e5 + 10;
typedef long long int ll;
#define x first
#define y second
#define endl '\n'
#define space << ' '
typedef pair<int, char> pic;

bool check(vector<int> &arr,string &s,int n,int k,int mid){
  int cnt = 0;
  int i = 0;
  for(;i<n;i++){
        if(s[i] == 'B')break;
    }
    bool flag = false;
    for(;i<n;i++){
        if(s[i] == 'B' && arr[i]>mid && flag == false) cnt++,flag = true;
        if(s[i] == 'R' && arr[i]>mid && flag == true) flag = false;
    }
    return cnt<=k;
}
void Solve() {
    int n,k;
    string s;
    cin>>n>>k>>s;
    vector<int> arr(n);
    int r = 0,l = 0;
    for(int i = 0;i<n;i++){
        cin>>arr[i];
        r = max(arr[i],r);
    }
    while(l<r){
        int mid = (l+r)>>1;
        if(check(arr,s,n,k,mid)) r = mid;
        else l = mid+1;
    }
    cout<<l<<endl;
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    cout.tie(nullptr);
#ifdef LOCAL
    freopen("Testlib.in", "r", stdin);
    //freopen("Code.out", "w", stdout);
#endif
    int T;
    cin >> T;
    while (T--) {
        Solve();
    }
    return 0;
}
