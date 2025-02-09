//ID Codes
#include <bits/stdc++.h>
using namespace std;
string s;
int main() {
    cin >> s;
    while(s!="#"){
        if (next_permutation(s.begin(), s.end())) {
            cout << s << endl;
        }
        else {
            cout << "No Successor"<<endl;
        }
        cin >> s;
    }
    return 0;
}
