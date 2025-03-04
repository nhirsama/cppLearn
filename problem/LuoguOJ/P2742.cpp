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
struct pdd {
    double x,y;

    const double operator *(const pdd &b) {
        return this->x * b.y - this->y * b.x;
    }

    const pdd operator -(const pdd &b) {
        return {b.x - this->x, b.y - this->y};
    }
} o;

double d(pdd p1, pdd p2) //两点间距离。。。
{
    return sqrt((p2.y - p1.y) * (p2.y - p1.y) + (p2.x - p1.x) * (p2.x - p1.x));
}

typedef pair<int, int> pii;
int n;
pdd arr[N];
stack<pdd> s, ss;

bool cmp(pdd &a, pdd &b) {
    auto A = a - o;
    auto B = b - o;
    auto temp = A * B;
    if (temp > 0) return true;
    if (temp == 0) return d(b, o) > d(a, o);
    return false;
}

double check(pdd a, pdd b, pdd c) {
    auto A = a - c;
    auto B = b - c;
    auto temp = A * B;
    return temp;
}

int main() {
    if (getenv("ONLINE_JUDGE") == nullptr) {
        freopen("Testlib.in", "r", stdin);
        freopen("Code.out", "w", stdout);
    }
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    cin >> n;
    o = {10000000, 10000000};
    for (int i = 1; i <= n; i++) {
        cin >> arr[i].x >> arr[i].y;
        if (o.y > arr[i].y) o = arr[i];
        if (o.y == arr[i].y && o.x > arr[i].x) o = arr[i];
    }
    sort(arr + 1, arr + n + 1, cmp);
    s.push(arr[1]);
    auto c = s.top();
    for (int i = 2; i <= n; i++) {
        while (s.size() > 1 && check(s.top(), arr[i], ss.top()) <= 0) s.pop(), ss.pop();
        ss.push(s.top());
        s.push(arr[i]);
    }
    double ans = 0;
    auto t = s.top();
    ans += d(t, o);
    while (!s.empty()) {
        ans += d(t, s.top());
        t = s.top();
        s.pop();
    }

    printf("%.2lf\n", ans);
    return 0;
}
