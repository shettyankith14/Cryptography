#include <iostream>
#include <tuple>
#include <stdexcept>

std::tuple<int, int, int> extended_euclidean_algorithm(int a, int b) {
    if (b == 0) {
        return std::make_tuple(a, 1, 0);
    }

    int gcd, x1, y1;
    std::tie(gcd, x1, y1) = extended_euclidean_algorithm(b, a % b);

    int x = y1;
    int y = x1 - (a / b) * y1;

    return std::make_tuple(gcd, x, y);
}

int find_modular_inverse(int a, int m) {
    int gcd, x, y;
    std::tie(gcd, x, y) = extended_euclidean_algorithm(a, m);

    if (gcd != 1) {
        throw std::invalid_argument("Inverse does not exist.");
    }

    return (x + m) % m;
}

int main() {
    int a, m;

    std::cout << "Enter a number to find inverse: ";
    std::cin >> a;
    std::cout << "Enter the number whose modulus is to be found: ";
    std::cin >> m;

    try {
        int inverse = find_modular_inverse(a, m);
        std::cout << "Modular inverse of " << a << " mod " << m << " is: " << inverse << std::endl;
    } catch (const std::invalid_argument& e) {
        std::cout << "Error: " << e.what() << std::endl;
    }

    return 0;
}
