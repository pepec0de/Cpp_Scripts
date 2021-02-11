#include <iostream>
#include <stdio.h>

using namespace std;

struct NodeStruct {
    int value;
    struct NodeStruct *left;
    struct NodeStruct *right;
};

typedef struct NodeStruct *Node;

void add(int value, Node &root) {
    if (root == NULL) {
        Node _new = new (struct NodeStruct);
        _new->value = value;
        _new->left = NULL;
        _new->right = NULL;
        root = _new;
    }
}

int main() {
    Node tree = NULL;
    add(15, tree);
    cout << tree->value << endl;
    return 0;
}
