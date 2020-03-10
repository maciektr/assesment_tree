#ifndef TREE_H
#define TREE_H
#include "Node.h"

class Tree{
    public:
        Node *root;
        Tree(Node *r) : root(r) {}
        ~Tree();
    private:
        void delete_tree(Node *node);
};

#endif