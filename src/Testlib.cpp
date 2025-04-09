#include <iostream>
#include <vector>
using namespace std;

void solve() {
  int n, x, y;
  cin >> n >> x >> y;
  --x; --y;
  vector<int> ans(n);
  for (int i = 0; i < n; ++i) ans[(x + i) % n] = i % 2;
  if (n % 2 || (x - y) % 2 == 0)
    ans[x] = 2;
  for (auto x : ans)cout << x << ' ';
  cout << endl;
}

int main() {
  int T;
  cin >> T;
  while (T--) solve();
}