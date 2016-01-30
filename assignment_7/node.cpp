#include <vector>
#include <cstddef>

struct Node {
    char val;
    std::vector<Node *> next;
    Node(char c) : val(c) {};
};
