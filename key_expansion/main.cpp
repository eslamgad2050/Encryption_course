#include <iostream>
#include "Key.h"
#include "eslam.cpp"
using namespace std;

int main() {
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
