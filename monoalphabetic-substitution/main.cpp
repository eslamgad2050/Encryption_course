
#include "bits/stdc++.h"
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
string decrpt(const char *key, string text) {
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

string get_text_from_file(const string &file_name) {
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

bool write_text_to_file(const string &file_name, string text) {
    ofstream my_file(file_name);    //open file "file_name"
    if (my_file.is_open()) {
        my_file << text;
        return true;
    } else {
        return false;
    }
}

void perform_attack(Attack attack) {
    string result = attack.decrypt();
    cout << result << "\n";
    cout << "enter\n s: to show the key\n r: to replace tow chars\n d: to done\n";
    char in;
    cin >> in;
    if (in == 's') {
        cout << attack.get_key() << "\n";
        perform_attack(attack);
    } else if (in == 'r') {
        char first, second;
        cout << "enter the first char" << "\n";
        cin >> first;
        cout << "enter the second char" << "\n";
        cin >> second;
        attack.swap_2_chars_in_key(first, second);
        perform_attack(attack);
    } else if (in == 'd') {
        write_text_to_file("attack_output.txt", result);
    } else {
        perform_attack(attack);
    }
}

void interact() {
    char input;
    cout << "enter\n e: to encrypt\n d: to decrypt\n a: to attack\n 0: to exit\n";
    cin >> input;
    if (input == 'e') {
        cout << "enter\n r:to randomly generate key\n k:to enter key manually\n";
        char in;
        cin >> in;
        char *key = keygen();
        if (in == 'k') {
            cout << "enter the key 26 chars in capital form\n";
            cin >> key;
        }
        cout << "key=   " << key << "\n";
        string x = encrpt(key, get_text_from_file("encryption.txt"));
        cout << x;
        write_text_to_file("decryption.txt", x);
    } else if (input == 'd') {
        cout << decrpt("OXSWACVZJTELGRMUFPHNKQDIBY", get_text_from_file("decryption.txt"));
    } else if (input == 'a') {
        Attack attack(get_text_from_file("cipher.txt"));
        perform_attack(attack);
    } else if (input == '0') {} else { interact(); }
}

int main() {
    interact();
    return 0;
}
