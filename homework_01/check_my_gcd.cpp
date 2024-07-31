#include <bits/stdc++.h>

int my_gcd(int a, int b) {
    a = std::abs(a);
    b = std::abs(b);
    while (b) {
        int tmp = b;
        b = a % b;
        a = tmp;
    }
    return a;
}

int main() {
    std::srand(std::time(nullptr));
    int num_tests = 1000;
    for (int i = 0; i < num_tests; ++i) {
        int a = -std::rand();
        int b = -std::rand();
        if (std::gcd(a, b) != my_gcd(a, b)) {
            std::cout << "Incorrect gcd for a = " << a << " and b = " << b << ";\n";
        }
    }
}