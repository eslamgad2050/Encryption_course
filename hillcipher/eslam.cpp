//
// Created by eslam on 4/1/22.
//

#include "hillcypher.h"

using namespace std;

//constructor takes key and put in into key
//then call getKeyInverse
//by Eslam
Hill::Hill(int k[3][3]) {
    for (int i = 0; i < 3; ++i) {  //loot to got through the rows
        for (int j = 0; j < 3; ++j) {//loot to got through the cols
            key[i][j] = k[i][j]; //i is the row index, j is the column index
        }
    }
    getKeyInverse();//to generate the inverse key
}

//constructor generate random key
//then call getKeyInverse
//by Eslam
Hill::Hill() {
    generateKey();//function generates key
    getKeyInverse();//to generate the inverse key
}

/*function set the key  */
void Hill::setKey(int k[3][3]) {
    for (int i = 0; i < 3; ++i) { //loot to got through the rows
        for (int j = 0; j < 3; ++j) {//loot to got through the cols
            key[i][j] = k[i][j];//go through the key digits and put the passed key digits, i is the row index, j is the column index
        }
    }
}


/*get the determinant of the matrix*/
int Hill::determinant(int data[3][3]) {//pass matrix of 3*3
    int result = 0; //put the determinant int result variable
    //use the first row to calculate the determinant,
    //sum of  the subs determinant multiplied by row element with sign[+ - +]
    int sub_det = data[0][0] * (data[1][1] * data[2][2] - data[1][2] * data[2][1]),//sub determinant 2*2 * cof[0][0]
    sub_det1 = data[0][1] * (data[1][0] * data[2][2] - data[1][2] * data[2][0]),//sub determinant 2*2 cof[0][1]
    sub_det2 = data[0][2] * (data[1][0] * data[2][1] - data[1][1] * data[2][0]);//sub determinant 2*2 cof[0][2]
    return sub_det - sub_det1 + sub_det2;//return the result
}

bool Hill::checkKey() {
    /*the key must have inverse and the elements of the key must be relatively prime with 26*/
    int det = determinant(key);//check if the determinant of the key =0
    if (det == 0) {
        return false;//no inverse for the key cause the determinant is 0
    } else {
        for (auto &i: key) { //got through the rows  i=row
            for (int j: i) {//go through the columns  j=element int the row i
                if (j % 2 == 0 || j % 13 == 0) { //check if the element is relatively prime with 26
                    return false;
                }
            }
        }
        return true;
    }
}

int Hill::mod(int operand1, bool isDivisor, int operand2) {
    if (isDivisor) {
        int result = 0;
        for (int i = 0; i < 26; ++i) {
            if ((operand1 * i) % operand2 == 1) {
                return i;
            }
        }
        return result;
    } else {
        return operand1 > 0 ? operand1 % operand2 : (operand1 % operand2) + operand2;
    }
}
