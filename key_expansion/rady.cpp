#include "Key.h"

void Key::expand() {
    unsigned char rcon[4][10] = {{0x1, 0x2, 0x4, 0x8, 0x10, 0x20, 0x40, 0x80, 0x1b, 0x36},
                                 {0},
                                 {0},
                                 {0}};//RCON array[4][10]
    unsigned char *temp = new unsigned char[4];
    int counter = 1;
    int complex_column = 4;//number of column that need to rotate & sub to create it
    while (counter <= 10)//10 because we need generate 10 key from origin key
    {
        //each time enter to the wile loop we generate additional key[4][4](4*32 bit word) from previous key
        for (int i = 0; i < 4; i++) {
            temp[i] = expanded_key[complex_column - 1][i];//[3]
        }
        temp = rotate_word(temp);
        temp = sub_word(temp);
        for (int i = 0; i < 4; i++)//generate complex coulmn
        {
            expanded_key[complex_column][i] = expanded_key[complex_column - 4][i] ^ temp[i] ^ rcon[i][counter - 1];
        }
        for (int j = 0; j < 3; j++)//generate the 3 column after the complex coulmn
        {
            for (int i = 0; i < 4; i++) {
                expanded_key[j + complex_column + 1][i] =
                        expanded_key[j + complex_column - 3][i] ^ expanded_key[j + complex_column][i];
            }
        }
        counter++;
        complex_column += 4;
    }
}


unsigned char **Key::get_expanded_key() {
    unsigned char **arr = new unsigned char *[44]; //create array 2D with pointer to pointer
    for (int i = 0; i < 44; i++) {
        arr[i] = new unsigned char[4];
    }

    for (int i = 0; i < 44; i++) {
        for (int j = 0; j < 4; j++) {
            arr[i][j] = expanded_key[i][j];//copy expanded_key to arr
        }
    }
    return arr;
}
