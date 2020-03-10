#ifndef NODE_H
#define NODE_H

class Node{
    public: 
        int data;
        Node *left;
        Node *right;
        Node(int d, Node *l, Node *r):data(d),left(l),right(r){}
        Node(int d):data(d),left(nullptr),right(nullptr){}
};

#endif