//
// Created by eslam on 5/9/22.
//
#include "stream_project.h"
#include "bits/stdc++.h"

using namespace std;

//returns all prime numbers between min and max
vector<int> primes(int min, int max) {
    bool is_prime[max - 1];//array of bools true means prime false means not prime
    for (int i = 0; i < max - 1; ++i) {
        is_prime[i] = true;//initiated all true
    }
    for (int i = 2; i * i < max; ++i) {//start with the first prime number (2)
        if (is_prime[i - 2]) {//if the number is prime then delete all of its multiplication
            //as example  3 -> delete 6-9-12....
            for (int j = i * i, x = 0; j <= max; ++x, j = i * i + x * i) {
                is_prime[j - 2] = false;
            }
        }
    }
    vector<int> primes;//the result prime numbers
    for (int i = min; i < max - 1; ++i) {
        if (is_prime[i]) {//if the number is prime push it back into the result vector
            primes.push_back(i + 2);
        }
    }
    return primes;
}

BBS::BBS() {
    vector<int> p_numbers = primes(100, 1000);//get prime numbers between 100 and 1000
    srandom(time(nullptr));//seed the random function with the time
    p = p_numbers[random() % p_numbers.size()];//choose random number for p and q
    q = p_numbers[random() % p_numbers.size()];
    //check if p and q %4 ==3 if not change their value
    while (p % 4 != 3) {
        p = p_numbers[random() % p_numbers.size()];
    }
    while (q % 4 != 3) {
        q = p_numbers[random() % p_numbers.size()];
    }
    n = p * q;
}
//print q, p and n
void BBS::show_prime_number() {
    cout << "q = " << q << "\np = " << p << "\nn = " << n << "\n";
}

//print bbs key
void BBS::show_key() {
    for (int i = 0; i < 128; ++i) {
        cout << bbs_key[i] << " ";
    }
    cout << "\n";

}

void RC4::first_permutation() {
    BBS bbs;
    for (int i = 0; i < 256; ++i) {
        intiial_state_vector[i] = i;//initialize S[] with 0 1 2 3..
        temp_vector[i] = bbs.bbs_key[i % 128];//initialize t[] with the key from bbs repeated
    }
    int j = 0;
    for (int i = 0; i < 256; ++i) {
        j = (j + intiial_state_vector[i] + temp_vector[i]) % 256;//change the value of j each time
        permuted_state_vector[i] = intiial_state_vector[j];//initialize the permuted state vector() by swapping S[i] with S[j]
        permuted_state_vector[j] = intiial_state_vector[i];;
    }
}
