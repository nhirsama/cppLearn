//P1010 [NOIP1998 普及组] 幂次方
//记得把文件读写流和define注释掉
#include <bits/stdc++.h>
using namespace std;
string to_power(int n){
    string s;
    if(n == 1) return "";
    if(n == 0) return "(0)";
    int pow = 0;
    while(n>0) {
        if(n&1) {
            if(s.size()>0) {
                s = "2" + to_power(pow)+"+"+s;
            }
            else s = "2" + to_power(pow);
        }
        pow++;
        n = n>>1;
    }
    return "("+s+")";
}
int main() {
#define cin fin
#define cout fout
    ifstream fin("Testlib.in");
    ofstream fout("Code.out");
    int n;
    cin>>n;
    string s = to_power(n);
    s = s.substr(1,s.length()-2);
    cout<<s<<endl;
    return 0;
}