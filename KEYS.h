#ifndef KEYS_Header
#define KEYS_Header

const char mfoc[8] = {'e', 't', 'a', 'o' , 'i', 'n', 's', 'r'}; //most frequent one-char
const int smfoc = 5; //number of  selected one-char
const char mftc[2][5] = {{'t', 'i', 'e', 'a', 'r'},{'h', 'n', 'r', 'n', 'e'}};
const int smftc = 4; //maybe we get two e's if we set it to 5


extern char* cypheredText;
extern int cypheredTextsize;
void getText(); //ESLAM
void outText(char* ); //ESLAM

class chfreq
{
public:
    int freq = 0;
    char first = '\0';
    char sec = '\0';
    //char third = '\0';
    void operator = (chfreq); //AZIZ
};


//the class keys
class KEYS
{
private:
    char* key;
    KEYS* first;
    KEYS* next;

public:
    KEYS(); //construct 26-char key of char ' '  //ESLAM
    void addKey(char* k); //add new key to the list  //ESLAM
    void replaceChar(int index, char ch); //update index with cretin character  //ESLAM
    char* showKey(); // return key  //ESLAM
    char* decrept();  //ESLAM
    //char* decrept(char* text, int textsize); //return decryption of text with current key
    void branch(KEYS* currkey, char* permutate, int permindex, int permsize); //AZIZ
    void oneCharKey(chfreq* cf); //AZIZ
    void twoCharKey(chfreq* cf); //AZIZ
    void Attack(); //AZIZ
    //~KEYS();
};


//used functions
template <typename T>
void Swap(T& a,T& b)
{
    T temp = a;
    a = b;
    b = temp;
}

/*
create array of 26 chfreq
set first to A, B, C, ...
count the frequencies
sort chfreq array
return chfreq*
*/
chfreq* oneCharFreqCounter();
//chfreq* oneCharFreqCounter(char* text, int textsize); //RADY



/*
create array of 26 chfreq put target in first or in sec depending on isAfter
count frequencies
most freq char after certain character or target
note targets are the most frequent characters from oneCharFreqCounter
*/

char twoCharFreqCounter(char target);
//char twoCharFreqCounter(char* text, int textsize, char target); //RADY
//threeCharFreqCounter


/*
fill key from oneCharFreqCounter
if two chars have the same frequency then branch
*/
//void oneCharKey();
//twoCharKey
//threeCharKey


/*
create new key from current key
update the new key with newbranch
update current key with current char
return the new key
*/
//KEYS* branch(KEYS* currkey, char currchar, char newbranch, int index); //AZIZ


#endif
