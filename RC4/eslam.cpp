//
// Created by eslam on 5/9/22.
//
#include "stream_project.h"
#include "bits/stdc++.h"

using namespace std;

vector<int> primes(int min, int max) {
    bool is_prime[max - 1];
    for (int i = 0; i < max - 1; ++i) {
        is_prime[i] = true;
    }
    for (int i = 2; i * i < max; ++i) {
        if (is_prime[i - 2]) {
            for (int j = i * i, x = 0; j <= max; ++x, j = i * i + x * i) {
                is_prime[j - 2] = false;
            }
        }
    }
    vector<int> primes;
    for (int i = min; i < max - 1; ++i) {
        if (is_prime[i]) {
            primes.push_back(i + 2);
        }
    }
    return primes;
}

BBS::BBS() {
    vector<int> p_numbers = primes(100, 1000);
    srandom(time(nullptr));
    p = p_numbers[random() % p_numbers.size()];
    q = p_numbers[random() % p_numbers.size()];
    while (p % 4 != 3) {
        p = p_numbers[random() % p_numbers.size()];
    }
    while (q % 4 != 3) {
        q = p_numbers[random() % p_numbers.size()];
    }
    n = p * q;
}

void BBS::show_prime_number() {
    cout << "q = " << q << "\np = " << p << "\nn = " << n << "\n";
}

void BBS::show_key() {

    for (int i = 0; i < 128; ++i) {
        cout << bbs_key[i] << " ";
    }
    cout << "\n";

}

void RC4::first_permutation() {
    BBS bbs;
    for (int i = 0; i < 256; ++i) {
        intiial_state_vector[i] = i;
        temp_vector[i] = bbs.bbs_key[i % 128];
    }
    int j = 0;
    for (int i = 0; i < 256; ++i) {
        j = (j + intiial_state_vector[i] + temp_vector[i]) % 256;
        permuted_state_vector[i] = intiial_state_vector[j];
        permuted_state_vector[j] = intiial_state_vector[i];;
    }
}
