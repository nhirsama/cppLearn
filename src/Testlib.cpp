#include <bits/stdc++.h>

int main() {
    time_t t;
    srand((unsigned) time(&t));
    int rangValue = rand() % 101;
    printf("%d", rangValue);
    std::random_device rd{};
    std::mt19937 mt(rd());
    std::cout << mt();
}
