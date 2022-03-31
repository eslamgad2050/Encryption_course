#ifndef NODE_H
#define NODE_H

class Node {
private:
    int exp;
    double coef;
    Node *next;

    friend class Polynomial; /* Allow Polynomial Access */
public:
    Node() {};

    Node(int e, double c) : exp(e), coef(c), next(nullptr) {
    }

    Node(int e, double c, Node *n) : exp(e), coef(c), next(n) {
    }
};


#endif // NODE_H
