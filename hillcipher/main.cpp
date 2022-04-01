#include <iostream>
#include "hillcypher.h"

using namespace std;

int main() {

    int test[3][3] = {1, 0, 5, 5, 5, 5, 5, 0, 5};
    Hill hill;
    cout << "37 mod 26 =" << hill.mod(37, false, 26) << "\n";
    cout << "17 mod 26 =" << hill.mod(17, false, 26) << "\n";
    cout << "-7 mod 26 =" << hill.mod(-7, false, 26) << "\n";
    cout << "1/9 mod 26 =" << hill.mod(9, true, 26) << "\n";
    cout << "1/5 mod 26 =" << hill.mod(5, true, 26) << "\n";
    return 0;
}
