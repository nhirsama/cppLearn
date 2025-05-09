#include <bits/stdc++.h>

int main() {
    int a, b;
    std::cin >> a >> b;
    auto add = [&](auto &&self, int n)-> void {
        if (n >= 20) {
            std::cout << a + b << std::endl;
            return;
        }
        self(self, n + 1);
    };
    add(add, 0);
    return 0;
}
