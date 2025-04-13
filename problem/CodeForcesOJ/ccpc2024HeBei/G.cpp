//
// Created by Origami on 25-4-13.
//
#include <bits/stdc++.h>
using namespace std;

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    cout.tie(nullptr);

    int n, m, k, ans = 0;
    cin >> n >> m >> k;
    string s;
    cin >> s;
    s += s;
    int len = s.length();
    vector<vector<int> > a(len + 1, vector<int>(2)), b(len + 1, vector<int>(2)), c(len + 1, vector<int>(2)),
            sum_a(len + 1, vector<int>(2)), sum_b(len + 1, vector<int>(2)), sum_c(len + 1, vector<int>(2));
    for (int i = 1; i < len; i+=2) {
        int j=i+1;
        if (s[i]!=s[i-1]) {
            ++b[j][0];
        }else {
            if (s[i]=='0')
                ++a[j][0];
            else ++c[j][0];
        }
        sum_a[j][0]=a[j][0]+sum_a[j-2][0];
        sum_b[j][0]=b[j][0]+sum_b[j-2][0];
        sum_c[j][0]=c[j][0]+sum_c[j-2][0];
    }
    for (int i = 0; i < len; i+=2) {
        int j=i+1;
        if (s[i]!=s[i+1]) {
            ++b[j][1];
        }else {
            if (s[i]=='0')
                ++a[j][1];
            else ++c[j][1];
        }
        sum_a[j][1]=a[j][1]+sum_a[j-2][1];
        sum_b[j][1]=b[j][1]+sum_b[j-2][1];
        sum_c[j][1]=c[j][1]+sum_c[j-2][1];
    }
    int l=1,r=0;
    for (;l<r && r<=len;l++) {
        while (r<=len && sum_a[r+1][0]-sum_a[l-1][0]<=n && sum_b[r+1][0]-sum_b[l-1][0]<=m && sum_c[r+1][0]-sum_c[l-1][0]<=n)
    }

}
