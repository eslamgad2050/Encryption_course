
#include "bits/stdc++.h"
#include "KEYS.h"
#include "Attack.h"

using namespace std;

string encrpt(char *key, string text) {
    string result;
    for (char i: text) {
        result += key[i - 'A'];
    }
    return result;
}


//decrypt by encrypt with inverse key
string decrpt(char *key, string text) {
    char *keyinv = new char[26];
    for (int i = 0; i < 26; i++) {
        keyinv[key[i] - 'A'] = i + 'A';
    }
    return encrpt(keyinv, text);
}


//key generation note include stdlib.h, time.h
char *keygen(unsigned int keyG = 0) {
    char *key = new char[26];
    for (int i = 0; i < 26; i++)
        key[i] = i + 'A';

    srand(keyG);

    for (int j = 0; j < 5; j++) {
        for (int i = 0; i < 26; i++) {
            int r = rand() % 26;
            char temp = key[i];
            key[i] = key[r];
            key[r] = temp;
        }
    }
    return key;
}

string get_text(const string &file_name) {
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

bool write_text(const string &file_name, string text) {
    ofstream my_file(file_name);    //open file "file_name"
    if (my_file.is_open()) {
        my_file << text;
        return true;
    } else {
        return false;
    }
}

void interact() {
    char input;
    cout << "enter \"e\" for encrypt\n \"d\" for decrypt\n\"a\" for attack";
    cin >> input;
    if (input == 'e') {
        char *key = keygen();
        cout << "key=   " << key << "\n";
        string x = encrpt(key, get_text("encryption.txt"));
        cout << x;
        write_text("decryption.txt", x);
    } else if (input == 'd') {
        cout << decrpt("OXSWACVZJTELGRMUFPHNKQDIBY", get_text("decryption.txt"));
    } else if (input == 'a') {}
}

int main() {
    //make the cout<< write in the file "output.txt"
    // freopen("output.txt", "w", stdout);
    interact();
    // Attack attack(get_text("cipher.txt"));
    // cout << attack.decrypt();
    return 0;
}
