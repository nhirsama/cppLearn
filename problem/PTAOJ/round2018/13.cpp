#include <bits/stdc++.h>
using namespace std;
int main(){
    string s;
    // cout<<"int main()\n{\n";
    int tab = 0;
    string temp;
    getline(cin,s);
    auto prspace = [&tab]() {
        for (int i = 0;i<tab;i++) {
            cout<<' ';
        }
    };
    for (auto c:s) {

        if (c == '{') {
            cout<<"{\n";
            tab+=2;
            prspace();
        }
        else if (c == '}') {
            //cout<<"\n";
            prspace();
            cout<<"}\n";
            tab-=2;
        }
        else if (temp == "main()") {
            cout<<temp<<'\n';
            temp ="";
        }
        else if (c == ' ') {
            if (temp.empty())continue;

            cout<<temp<<' ';
            temp = "";
        }
        else if (c == ';') {
            cout<<temp;
            temp = "";
            cout<<c<<'\n';
            prspace();
        }
        else temp.push_back(c);
    }
    return 0;
}