#include <iostream>
#include <random>
#include <string>

unsigned short custom_hash(const std::string& message) {
    std::hash<std::string> hasher;
    std::default_random_engine rng(hasher(message));
    std::uniform_int_distribution<unsigned short> distribution(0, std::numeric_limits<unsigned short>::max());
    return distribution(rng);
}

int main() {
    std::string message;
    std::cout << "Enter the message: ";
    std::getline(std::cin, message);

    unsigned short hash_value = custom_hash(message);

    std::cout << "Original Message: " << message << std::endl;
    std::cout << "Hash value: " << hash_value << std::endl;

    // Simulate receiver computing the hash again
    std::string received_message;
    std::cout << "Enter the received message: ";
    std::getline(std::cin, received_message);

    unsigned short received_hash_value = custom_hash(received_message);

    std::cout << "Received Message: " << received_message << std::endl;
    std::cout << "Received Hash value: " << received_hash_value << std::endl;

    // Verify integrity
    if (received_hash_value == hash_value) {
        std::cout << "Integrity: The message has not been modified." << std::endl;
    } else {
        std::cout << "Integrity: The message has been modified." << std::endl;
    }

    return 0;
}
