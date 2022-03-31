#ifndef NODE_H
#define NODE_H

class Node
{
private:
    int exp;
    double coef;
    Node* next;
    friend class Polynomial; /* Allow Polynomial Access */
};


#endif // NODE_H
