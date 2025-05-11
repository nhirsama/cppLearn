#include <iostream>
#include <string>
int main() {
    const std::string s = R"(#include <iostream>
#include <string>
int main() {
    const std::string s = R"(%s)";
    std::cout << std::format(s, s) << std::endl;
    return 0;
})";
    std::cout << std::format(s, s) << std::endl;
return 0;
}
