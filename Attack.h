#include "iostream"

using namespace std;
#ifndef KEYS_H_ATTACK_H
#define KEYS_H_ATTACK_H


class Attack {
private:
    pair<int, char> *one_chars;
    pair<int, char *> *tow_chars;
    string cipher;
    char choosed[26];
    string key = "--------------------------";

public:
    Attack(string x);

    pair<int, char> *count_1_char();

    pair<int, char *> *count_2_chars();

    string get_key();

    string decrypt();

    void get_char_from_tows(char target, char twin, bool first);
};


#endif //KEYS_H_ATTACK_H
