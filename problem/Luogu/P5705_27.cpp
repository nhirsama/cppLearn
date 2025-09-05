//  P5705 【深基2.例7】数字反转
//  20:57
// #include <bits/stdc++.h>
#include <stdio.h>

signed main() {
    char s[5];
    scanf("%s", s);
    for (int i = 4; i >= 0; i--) {
        printf("%c", s[i]);
    }
    return 0;
}
