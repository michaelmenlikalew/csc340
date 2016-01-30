#include <iostream>

#include "GeneralTree.h"

using namespace std;

GeneralTree::GeneralTree()
{
    n = NULL;
}

GeneralTree::~GeneralTree()
{
    this->clear();
}
GeneralTree::GeneralTree(const GeneralTree &other)
{
    n = NULL;
    copyOther(other);
}

void GeneralTree::copyOther(const GeneralTree &other)
{
    insert(other.n->val, n);
    copyFrom(other.n, n);
}

void GeneralTree::copyFrom(Node *start, Node *other)
{
    if (!start)
        return;
    int size = start->next.size();
    for (int i = 0; i < size; i++) {
        insert(start->next[i]->val, other);
        copyFrom(start->next[i], other->next[i]);
    }
}

GeneralTree& GeneralTree::operator=(const GeneralTree &other)
{
    if (this != &other)
    {
        clear();
        this->n = NULL;
        copyOther(other);
    }
    return *this;
}

Node* GeneralTree::insert(char val, Node *parent)
{
    Node *tmp = new Node(val);
    if (parent) {
        parent->next.push_back(tmp);
    } else if (!parent && n) {
        delete tmp;
        throw No_Parent_Exception();
    } else if (!parent && !n) {
        n = tmp;
    }
    return tmp;
}

void GeneralTree::print() const
{
    printFrom(n);
    cout << endl;
}

void GeneralTree::printFrom(Node *start) const
{
    int size = start->next.size();
    if (size == 0) {
        cout << start->val;
        return;
    }
    cout << '(' << flush;
    for (int i = 0; i < size; i++) {
        printFrom(start->next[i]);
    }
    cout << ')' << flush;
}

void GeneralTree::clear()
{
    clearFrom(n);
}

void GeneralTree::clearFrom(Node *start)
{
    if (!start)
        return;
    int size = start->next.size();
    for (int i = 0; i < size; i++) {
        clearFrom(start->next[i]);
    }
    delete start;
}
