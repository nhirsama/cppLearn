#include <bits/stdc++.h>
using namespace std;
const int N = 1e5+10;
typedef long long int ll;
#define first x;
#define second y;
ll n,arr[105],arrd[105],ans;
int main() {
    cin>>n;
    for(int i=1;i<=n;i++)cin>>arrd[i];
    for(int i=1;i<=n;i++){
        for(int j=1;j<=arrd[i];j++){
            if (i < 10) {
                if (j == i) {
                    ans++;
                }
                else if (j%10 == j/10 && j%10 == i) {
                    ans++;
                }
            }
            else {
                if (j<10 &&i%10 == i/10 &&j%10 == i%10) {
                    ans++;
                }
                else if(i%10 == i/10 && j%10 == j/10 && j%10 == i%10) {
                    ans++;
                }
            }
        }
    }
    cout<<ans;
    return 0;
}
