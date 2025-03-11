#include <bits/stdc++.h>
using namespace std;
const int N = 1e5+10;
typedef long long int ll;
#define first x;
#define second y;
ll k,g,m;
ll mv,gv;
int main() {
    cin>>k>>g>>m;
    while (k){
        if(gv == g) gv = 0,k--;
        else if(mv == 0) mv = m,k--;
        else{
            if(mv >= g-gv) mv = mv-(g-gv),gv = g;
            else gv+=mv,mv = 0;
            k--;
        }
    }
    cout<<gv <<' ' <<  mv << endl;
    return 0;
}
