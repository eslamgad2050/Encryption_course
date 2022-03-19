#include <iostream>
#include <algorithm>
#include "KEYS.h"

char *cypheredText;
int cypheredTextsize;

void getText() {


    //should return
    //cypheredText = text;
    //cypheredTextsize = textsize;
}

//output the text to the file while maintaining its current content
void outText(char *text) {

}

chfreq *oneCharFreqCounter() {
    chfreq *c = new chfreq[26];              //pointer use it to save array[26] of chfreq
    chfreq temp;            //Used for temporary storage of a sort process
    int a[26] = {0};          //Used to determine the frequency of letters

    for (int i = 0; i < cypheredTextsize; i++)   //Used to determine the frequency of letters
    {
        a[(cypheredText[i] - 'A')] += 1;
    }
    for (int i = 0; i < 26; i++)  //Transfer data from array of int(a[26]) to array of chfreq(c[26])
    {
        c[i].freq = a[i];
        c[i].first = i + 'A';
    }
    for (int i = 0; i < 26; i++)   //Sorting from most frequent to least
    {
        for (int j = i + 1; j < 26; j++) {
            if (c[i].freq < c[j].freq)      //swapping process
            {
                Swap(c[i], c[j]);
                /*.freq=c[i].freq;
                temp.first=c[i].first;
                c[i].freq=c[j].freq;
                c[i].first=c[j].first;
                c[j].freq=temp.freq;
                c[j].first=temp.first;*/
            }
        }
    }
    return c;
}

char twoCharFreqCounter(char target) {
    int a[26] = {0};  //Used to determine the frequency of letters after the target char
    int maxmum = 0, char_number;  //They are used in the process of determining the most frequent letter
    for (int i = 0;
         i < (cypheredTextsize - 1); i++)    //Used to determine the frequency of letters after the target char
    {
        if (cypheredText[i] == target) {
            a[cypheredText[i + 1] - 'A'] += 1;
        }
    }
    for (int i = 0; i < 26; i++)  //process of determining the most frequent letter
    {
        if (maxmum < a[i]) {
            maxmum = a[i];
            char_number = i;
        }
    }
    return (char(char_number + 'A'));
}

void chfreq::operator=(chfreq op) {
    freq = op.freq;
    first = op.first;
    sec = op.sec;
}


KEYS::KEYS() {
    first = this;
    next = nullptr;
    char *temp = new char[26];
    for (int i = 0; i < 26; i++) {
        temp[i] = rand() % 26 + 'A';
    }
    key = temp;
}

void KEYS::addKey(char *k) {
    KEYS *temp;
    temp = this;
    while (temp->next != nullptr) {
        temp = temp->next;
    }
    KEYS *node = new KEYS;
    node->first = first;
    node->key = k;
    node->next = nullptr;
    temp->next = node;
}

void KEYS::replaceChar(int index, char ch) {
    key[index]=ch;
}

char *KEYS::showKey() {
    return key;
}

char *KEYS::decrept() {
    char *keyinv = new char[26];
    for (int i = 0; i < 26; i++) {
        if (key[i] != ' ')
            keyinv[key[i] - 'A'] = i + 'a';
        else
            keyinv[key[i] - 'A'] = ' ';
    }

    char *out = new char[cypheredTextsize];
    for (int i = 0; i < cypheredTextsize; i++) {
        out[i] = keyinv[cypheredText[i] - 'A'];
    }
    return out;
}

void KEYS::branch(KEYS *currkey, char *permutate, int permindex, int permsize) //if char* is {A,B} then size is 2
{
    int permfact = 1;  //permutation factorial ... for 3 same frequencies we have 3! permutations

    //copy the content of currkey, and save it because it will be modified
    char *tempShowKey = new char[26];
    char *temp = currkey->showKey();
    for (int i = 0; i < 26; i++)
        tempShowKey[i] = temp[i];


    for (int i = 2; i <= permsize; i++)
        permfact *= permsize;

    KEYS **tempkey = new KEYS *[permfact];

    tempkey[0] = currkey;
    for (int j = 0; j < permsize; j++)
        tempkey[0]->replaceChar(mfoc[permindex + j] - 'a', permutate[j]);

    for (int i = 1; i < permfact; i++) //we use currkey so total number of new keys is permsize
    {
        tempkey[i] = new KEYS;
        tempkey[i]->addKey(tempShowKey);

        std::next_permutation(permutate, permutate + permsize);
        for (int j = 0; j < permsize; j++)
            tempkey[i]->replaceChar(mfoc[permindex + j] - 'a', permutate[j]);
    }

    delete[] tempShowKey;
}

void KEYS::oneCharKey(chfreq *cf) {
    for (int i = 0; i < smfoc; i++) {
        if (cf[i].freq != cf[i + 1].freq) {
            KEYS *tempkey = first;
            while (tempkey) {
                tempkey->replaceChar(mfoc[i] - 'a', cf[i].first); //create Key or Keyinv?
                tempkey = tempkey->next;
            }
        } else {
            int samefreqcount = 0;
            for (int j = 0; j < smfoc; j++) {
                if (cf[j].freq == cf[j + 1].freq)  //more tolerance for the range of possibility!
                    samefreqcount++;
                else if (samefreqcount > 0) {
                    char *permutate = new char[samefreqcount + 1];
                    for (int k = j - samefreqcount, per = 0; k <= j; k++, per++)
                        permutate[per] = cf[k].first;

                    KEYS *tempkey = first;
                    while (tempkey) {
                        branch(tempkey, permutate, j - samefreqcount, samefreqcount + 1);
                        tempkey = tempkey->next;
                    }
                    samefreqcount = 0;
                }
            }
        }
    }
}

void KEYS::twoCharKey(chfreq *cf) //modify keys
{
    KEYS *currkey = first;
    while (currkey) {
        for (int i = 0; i < smftc; i++)
            currkey->replaceChar(mftc[0][i] - 'a', twoCharFreqCounter(mftc[1][i]));

        currkey = currkey->next;
    }
}

void KEYS::Attack() {
    chfreq *cf;
    KEYS *curr = first;
    cf = oneCharFreqCounter();
    curr->oneCharKey(cf);
    curr->twoCharKey(cf);

    while (curr) {
        outText(curr->decrept());
        curr = curr->next;
    }
    std::cout << "Attack done!" << std::endl;
}
