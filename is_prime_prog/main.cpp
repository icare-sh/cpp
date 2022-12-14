#include <iostream>

bool is_prime(long long n) {
    if (n <= 1) return false;
    if (n <= 3) return true;
    if (n % 2 == 0 || n % 3 == 0) return false;
    for (long long i = 5; i * i <= n; i = i + 6)
        if (n % i == 0 || n % (i + 2) == 0)
            return false;
    return true;
}

int main() {
    long long a;
    while (std::cin >> a) {
        std::cout << a << " is a prime: " << (is_prime(a) ? "True" : "False") << std::endl;
    }
    return 0;
}
