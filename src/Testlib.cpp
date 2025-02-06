#include <iostream>
#include <cstdlib> // 包含 std::getenv

int main() {
    const char* OJ = std::getenv("ONLINE_JUDGE");
    std::cout << 123456789%13;

    return 0;
}
