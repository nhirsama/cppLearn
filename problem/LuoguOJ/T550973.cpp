#include <bits/stdc++.h>
using namespace std;
int arr[10005][12000]{0};
string s[10005][5];
map<string,int >hashmap;
vector<int>up;
int main() {
#ifdef LOCAL
    freopen("Testlib.in", "r", stdin);
    freopen("Code.out", "w", stdout);
#endif
    int n,m,t,k;
    cin>>n>>m>>t>>k;
    for(int i=1;i<=n;i++) {
        int id,b;
        cin>>s[i][0]>>s[i][1]>>s[i][2]>>s[i][3];
        cin>>id>>b;
        arr[id][b] = i;
    }
    for(int i = 1;i<=m;i++) {
        for(int j=1;j<=t;j++) {
            int flag = 0;
            if(up.size()<k) {
                for(int k = 1;k<4;k++) {
                    if(hashmap.count(s[arr[i][j]][k])) {
                        flag ++;
                    }
                }
                if(flag<3) {
                    for(int k = 1;k<4;k++) {
                        hashmap[s[arr[i][j]][k]]=1;
                    }
                    up.push_back(arr[i][j]);
                }
            }
        }
    }
    cout<<up.size()<<endl;
    for(const int &i : up) {
        for(int j = 0;j<4;j++) {
            cout<<s[i][j]<<" ";
        }
        cout<<endl;
    }
#ifdef LOCAL
    fclose(stdin);
    fclose(stdout);
#endif
    return 0;
}