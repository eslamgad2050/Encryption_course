//
// Created by eslam on 3/19/22.
//

#ifndef KEYS_H_NODE_H
#define KEYS_H_NODE_H

#include "KEYS.h"


class Node {
private:
    char *key;
    KEYS *next;
    friend class KEYS;
};


#endif //KEYS_H_NODE_H
