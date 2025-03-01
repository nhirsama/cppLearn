#include <bits/stdc++.h>
using namespace std;
const int N = 105;
char arr[N][N];
char unarr[N][N];

int main() {
    char ccc;
    cin >> ccc;
    int n;
    cin >> n;
    for (int i = 1; i <= n; i++) {
        for (int j = 1; j <= n; j++) {
            char sbpro = getchar();
            while (sbpro == '\n') sbpro = getchar();
            arr[i][j] = sbpro;
            unarr[n - i + 1][n - j + 1] = arr[i][j];
        }
    }
    bool flag = true;
    for (int i = 1; i <= n; i++) {
        for (int j = 1; j <= n; j++) {
            if (unarr[i][j] != arr[i][j]) flag = false;
        }
    }
    if (flag)cout << "bu yong dao le" << endl;
    for (int i = 1; i <= n; i++) {
        for (int j = 1; j <= n; j++) {
            if (unarr[i][j] != ' ')cout << ccc;
            else cout << ' ';
        }
        cout << endl;
    }
    return 0;
}
