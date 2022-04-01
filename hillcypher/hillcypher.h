#ifndef hillcypher_h
#define hillcypher_h

#include <iostream>

#include <string>


class Hill
{
private:
    int key[3][3];
    int keyinv[3][3];

public:
    // 1
    //construct identity matrix key     //there is no reason for choosing identity matrix
    Hill();

    // 1
    //construct with the key k
    Hill(int k[3][3]);

    // 1
    //set key from the user input
    void setKey(int k[3][3]);

    // 1
    //calculate the determinant and return it
    int determinant();

    // 1
    //check if the key determinant is non-zero and relatively prime to 26
    bool checkKey();

    // 1
    //return the modulus of operand1 whither it is positive or negative
    //if isDevisor is true ... (1/9)mod 26 = 3 // where oprand1 = 9
    int mod(int operand1, float isDevisor = false, int oprand2 = 26);

    // 2
    //this will randomly generate a key
    //use checkKey() method to validate the key
    //use getKeyInverse() method to get the inverse
    void generateKey();

    // 2
    //use the key to encrypt the text and return the encrypted text
    std::string hillEncryption(std::string text);

    // 2
    //use the keyinv to decrypt the text and return the decrypted text
    std::string hillDecryption(std::string text);

    // 3
    //multiply the plain text with the key or the cyphered text with keyinv
    //if useKey is false use keyinv
    //store the result in res1_3
    //be careful as mul1_3 and res1_3 have higher index than 3
    void matrixMultiplication(const int* mat1_3, int* res1_3, bool useKey = true);

    // 3
    //get the inverse of key[3][3] and store it in keyinv[3][3]
    //calculate the keyInverse using adjoint
    void getKeyInverse();
};

#endif // hillcypher_h
