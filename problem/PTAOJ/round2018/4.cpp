#include <bits/stdc++.h>
using namespace std;

int main() {
    int pa, pb;
    cin >> pa >> pb;
    int aa = 0, bb = 0;
    for (int i = 1; i <= 3; i++) {
        int a;
        cin >> a;
        if (a == 1)bb++;
        else aa++;
    }
    if (aa == 3) {
        printf("The winner is a: %d + %d", pa, aa);
        return 0;
    }
    if (bb == 3) {
        printf("The winner is b: %d + %d", pb, bb);
        return 0;
    }
    if (pa + aa > pb + bb) {
        printf("The winner is a: %d + %d", pa, aa);
    } else {
        printf("The winner is b: %d + %d", pb, bb);
    }
    return 0;
}
