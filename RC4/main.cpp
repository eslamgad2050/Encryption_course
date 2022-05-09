#include <iostream>
#include "eslam.cpp"

using namespace std;

int main() {


    vector<int> x = primes(5, 100);
    for (int y: x) {
        cout << y << "  ";
    }
    return 0;
}
