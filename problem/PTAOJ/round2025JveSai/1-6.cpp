#include <bits/stdc++.h>

std::string gets(int n) {
    std::string s;
    for (int i = 0; i < n; i++) {
        int a;
        std::cin >> a;
        s.push_back(a + 'a');
    }
    return s;
}

int main() {
    int n, m;
    std::cin >> n >> m;
    std::string s = gets(n);
    while (m--) {
        int op;
        std::cin >> op;
        if (op == 1) {
            int l1;
            std::cin >> l1;
            std::string ss = gets(l1);
            int l2;
            std::cin >> l2;
            std::string ss2 = gets(l2);
            for (int i = 0; i < s.size(); i++) {
                if (s.substr(i, l1) == ss) {
                    s = s.substr(0, i) + ss2 + s.substr(i + l1);
                    break;
                }
            }
            // std::cout<<ss<< ' '<<ss2<<std::endl;
            // std::cout<<s<<std::endl;
        }
        if (op == 2) {
            int len = s.size();
            for (int i = 0; i < len - 1; i++) {
                char a = (s[i] - 'a' + s[i + 1] - 'a');
                if (a % 2 == 0) {
                    s.insert(i+1, 1, (a / 2 + 'a'));
                    i++;
                    len++;
                    //s = s.substr(0,i)+((a/2)+'a')+s.substr()
                }
            }
        }
        if (op == 3) {
            int r, l;
            std::cin >> l >> r;
            l--, r--;
            //int len = (l+r+1)/2;
            for (; l < r; l++, r--) {
                std::swap(s[l], s[r]);
            }
        }
        // for (int i = 0; i < s.size(); i++) {
        //     std::cout << s[i] - 'a' << " \n"[i == s.size() - 1];
        // }
    }
    for (int i = 0; i < s.size(); i++) {
        std::cout << s[i] - 'a' << " \n"[i == s.size() - 1];
    }
    //std::cout<<s;
}
//14 9 8 7 6 5 4 3 2 1 9 5 8 19 21 20 2 5 4 14 9 5 8 26 17 1 14 5 4 5 21 13 10 9 21 15 8 21 2 9 10 11 12 13 14 1 2
//14 9 8 7 6 5 4 3 2 1 5 9 8 19 20 21 2 5 4 9 14 5 8 17 26 1 14 5 4 5 13 21 10 9 15 21 8 21 2 9 10 11 12 13 14 1 2
//14 9 8 7 6 5 4 3 2 1 9 8 5 19 21 2 20 5 4 14 5 9 8 26 1 17 14 5 4 5 21 10 13 9 21 8 15 21 2 9 10 11 12 13 14 1 2