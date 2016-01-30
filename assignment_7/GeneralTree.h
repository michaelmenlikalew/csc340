/* Shwe Aye
 * 915827905
 * saye@mail.sfsu.edu
 * Assignment 7
 * Nov. 15, 2015
 * I used g++ compiler on Linux(GNU)/Unix.
 */

#include "node.cpp"
#include "exception.h"

#ifndef _GENERAL_TREE_H_
#define _GENERAL_TREE_H_

class GeneralTree {
private:
    Node *n;
public:
    GeneralTree();
    GeneralTree(const GeneralTree &other);
    ~GeneralTree();
    GeneralTree& operator=(const GeneralTree &other);
    Node* insert(char val, Node *parent);
    void print() const;
    void copyOther(const GeneralTree &other);
    void clear();
    void printFrom(Node *) const;
    void copyFrom(Node *, Node *other);
    void clearFrom(Node *start);
};

#endif
