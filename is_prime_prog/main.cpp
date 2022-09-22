#include <iostream>

int main() {
    int a;
    while (std::cin >> a) {
        std::cout << a << " is a prime: " << (a % 2 == 0 ? "False" : "True") << std::endl;
    }
    return 0;
}
