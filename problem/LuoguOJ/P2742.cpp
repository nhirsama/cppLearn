//P2742 [USACO5.1] 圈奶牛Fencing the Cows /【模板】二维凸包
#include <bits/stdc++.h>
using namespace std;
constexpr int N = 1e5 + 10;
typedef long long int ll;
#define x first
#define y second
#define endl '\n'
#define space << ' '
//using pdd  = pair<double,double>;
struct pdd{
    double x,y;
    const double operator *(const pdd &b){
        return this->x*b.y-this->y*b.x;
    }
};
typedef pair<int, int> pii;
int n;
pdd arr[N];
queue<pdd> q;
bool cmp(pdd a,pdd b){
    double temp = a*b;
}
int main() {
    if (getenv("ONLINE_JUDGE") == nullptr) {
        freopen("Testlib.in", "r", stdin);
        freopen("Code.out", "w", stdout);
    }
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    cin>>n;
    pdd o(10000000,10000000);
    for(int i  =1;i<=n;i++){
        cin>>arr[i].x>>arr[i].y;
        if(o.y>arr[i].y) o = arr[i];
        if(o.y == arr[i].y && o.x>arr[i].x) o = arr[i];
    }
    sort(arr+1,arr+n+1,[&o](auto a,auto b)->bool{if(a.y == b.y) return a.x<b.x; return a.y<b.y;});
    q.push(arr[1]);
    for(int i = 2;i<=n;i++){
        while(q.size()>1 && check
    }
    return 0;
}
