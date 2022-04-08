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
    Key(unsigned char key[4][4]);

    //2
    unsigned char **sub_word(unsigned char temp[4][4]);

    //2
    unsigned char **rotate_word(unsigned char temp[4][4]);

    //3
    unsigned char **get_expanded_key();

    //3
    //expands the key
    void expand();
};


#endif //KEY_EXPANSION_KEY_H
