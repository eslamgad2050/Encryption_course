//
// Created by eslam on 4/8/22.
//
#include "Key.h"

using namespace std;

//get the original key anp put in into the first 4 words of the expanded key
Key::Key(unsigned char key[4][4]) {
    for (int i = 0; i < 4; ++i) {   //iterate over the words
        for (int j = 0; j < 4; ++j) { //iterate over the byte of each word
            expanded_key[i][j] = key[i][j];  //word i and byte j
        }
    }
//    expand();//start the expand function
}

void interact() {
    cout << "enter the main_key you want to expand\n";
    unsigned char main_key[4][4], **expanded_key;
    for (int i = 0; i < 4; i++) {//iterate on each word of the key
        for (int j = 0; j < 4; ++j) {//iterate on each byte of the word
            cin >> main_key[i][j];//enter the value of the byte
        }
    }
    Key key(main_key);//object of clas key and set the value of the key
    cout << "here is the expanded key\n";
    expanded_key = key.get_expanded_key();//get the expanded key from the class key
    for (int i = 0; i < 44; ++i) {//iterate on each word of the expanded key
        for (int j = 0; j < 4; ++j) {//iterate on each byte of the word
            cout << expanded_key[i][j] << " ";//print the value of the byte
        }
        cout << "\n";//new line for each word
    }
    char input;//ask the user if what to do next
    cout << "\nenter 1 :to expand another key"
            "\n 2 to show the main key "
            "\n anything else to exit";
    cin >> input;
    if (input == '1') {//expand another key
        interact();
    } else if (input == '2') {//show the original key [4][4]
        for (int i = 0; i < 4; ++i) {//iterate on each word of the key
            for (int j = 0; j < 4; ++j) {//iterate on each byte of the word
                cout << expanded_key[i][j] << " ";//print the value of the byte
            }
            cout << "\n";//new line for each word
        }
    }
}

