#include <bits/stdc++.h>
using namespace std;
const int N = 2e5+10;
typedef long long int ll;
#define x first;
#define y second;
ll n,m,e,q;
vector<int> v[N];
pair<int,int> input[N];
bool stji[N];
stack<int> s;
int ccb[N];
int main() {
    cin>>n>>m>>e;
    for(int i=0;i<=n;i++)
    for(int i=1;i<=e;i++){
        scanf("%d%d",&input[i].first,&input[i].second);
    }
       cin>>q;
    for(int i=1;i<=q;i++){
        int a;
        scanf("%d",&a);
        stji[a]=true;
        s.push(a);
    }
    for(int i=1;i<=e;i++){
        if(stji[i]) continue;
        v[input[i].first].push_back(input[i].second);
        v[input[i].second].push_back(input[i].first);
    }

    return 0;
}
