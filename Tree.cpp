#include "Tree.h"

void Tree::delete_tree(Node *node){
    if(node==nullptr)
        return;
    delete_tree(node->left);
    delete_tree(node->right);

    delete(node);
}

Tree::~Tree(){
    delete_tree(this->root);
}