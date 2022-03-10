#include <iostream>
#include <fstream>

using namespace std;

string get_text(string file_name) {
    ifstream my_file(file_name);    //open file "file_name"
    string text;
    if (my_file.is_open()) {
        while (my_file.good()) {      //check if read the last char in the file
            char x = 0;
            my_file >> x;
            if (x >= 'a' && x <= 'z') {
                text += (x - 32);
            } else if (x >= 'A' && x <= 'Z') {
                text += x;
            }
        }
    }
    return text;
}

void encrypt() {
}

void decrypt() {

}

int main() {
    //make the cout<< write in the file "output.txt"
    freopen("output.txt", "w", stdout);

    cout << get_text("encryption.txt");
    return 0;
}
