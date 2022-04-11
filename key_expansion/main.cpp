#include <iostream>
#include "Key.h"

using namespace std;

void interact();

void print(unsigned char *word);

int main() {/*
    char x;
    cin >> x;
    unsigned char y;
    cin >> y;
    cout << "x= " << x << "\ny= " << y;
    x = y ^ x;
    //  cout << "\nx^y= " << x;
    cout << hex << int(x) << ' ';
    return 0;*/
    /*std::cout << "enter seed" << std::endl;
    int seed = 0;
    cin >> seed;
    srand(seed);
    string name[] = {"\nGad", "\nRady", "\nAziz"};
    int rand1 = -1, rand2 = -1;
    rand1 = rand() % 3;
    rand2 = rand() % 3;
    while (rand2 == rand1) {
        rand2 = rand() % 3;
    }
    cout << name[0] << " takes task number " << rand2 + 1;
    cout << name[1] << " takes task number " << rand1 + 1;
    cout << name[2] << " takes task number " << 4 - rand1 - rand2;
*/
    interact();
    return 0;

}
