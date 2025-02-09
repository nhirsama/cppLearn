#include <bits/stdc++.h>
using namespace std;
void Func(){
    string s;
    cin>>s;
    bool flag=false;
    for(int i=0;i<s.length()-1;i++){
      if(s[i]==s[i+1]){
          flag = true;
      }
    }
    if(flag==true){
        cout << 1 << endl;
    }
    else{
        cout << s.size()<<endl;
    }
}
int main() {
    int T;
    cin >> T;
    while (T--) {
        Func();
    }
    return 0;
}
