#include <iostream>
#include <cmath>
int generate_symmetric_key(int g, int p, int x, int y) {
    int A = fmod(pow(g, x), p);
    int B = fmod(pow(g, y), p);

    // Calculate symmetric key
    int key_A = fmod(pow(B, x), p);
    int key_B = fmod(pow(A, y), p);

  
    if (key_A == key_B) {
        return key_A;
    } else {

        return -1;
    }
}
int main() {
    int p = 23;
    int g = 9;  
    int x = 4;  //Private key for Alice
    int y = 3;  //Private key for bob
    int symmetric_key = generate_symmetric_key(g, p, x, y);


    if (symmetric_key != -1) {
        std::cout << "Symmetric Key: " << symmetric_key << std::endl;
    } else {
        std::cout << "Error occurred while generating the symmetric key." << std::endl;
    }

 return 0;
}
