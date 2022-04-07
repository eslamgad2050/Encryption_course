//
// Created by eslam on 4/7/22.
//
#ifndef KEY_EXPANSION_KEY_H
#define KEY_EXPANSION_KEY_H

class Key {
private:
    unsigned char expanded_key[11][4];
public:
    //1 (key and main)
    //constructor set the first 4words of the expanded and call expand
    Key(unsigned char [4][4]);

    unsigned char **sub_word(unsigned char temp[4][4]);

    unsigned char **rotate_word(unsigned char temp[4][4]);

    //3
    //return word number n(0 means the original key)
    unsigned char **get_key(int n);

    //expands the key
    void expand();
};

#endif //KEY_EXPANSION_KEY_H
