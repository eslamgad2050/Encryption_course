
#include "bits/stdc++.h"
#include "KEYS.h"
#include "Attack.h"

using namespace std;

char *encrpt(char *key, char *text, int textSize) {
    char *out = new char[textSize];
    for (int i = 0; i < textSize; i++) {
        out[i] = key[text[i] - 'A'];
    }
    return out;
}


//decrypt by encrypt with inverse key
char *decrpt(char *key, char *text, int textSize) {
    char *keyinv = new char[26];
    for (int i = 0; i < 26; i++) {
        keyinv[key[i] - 'A'] = i + 'A';
    }
    return encrpt(keyinv, text, textSize);
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

int main() {
    //make the cout<< write in the file "output.txt"
    // freopen("output.txt", "w", stdout);
    Attack attack(get_text("cipher.txt"));
    pair<int, char *> *x = attack.count_2_chars();
    for (int i = 0; i < 26 * 26; ++i) {
        cout << x[i].first << "  " << x[i].second << "\n";
    }
    cout << attack.decrypt();
    return 0;
}
