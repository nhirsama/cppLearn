#include <bits/stdc++.h>
using namespace std;
const int N = 1e5+10;
typedef long long int ll;
#define first x;
#define second y;
ll l,r;
int main() {
    string s;
    cin>>l>>r;
    cin>>s;
    for(int i=0;i<l-1;i++)cout<<s[i];
    for(int i=r-1;i>=l-1;i--)cout<<s[i];
    for(int i=r;i<s.size();i++)cout<<s[i];
    return 0;
}
