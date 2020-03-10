#include<iostream> 

#include "TreeMetrics.h"
#include "Tree.h"
#include "Node.h"

Node *createExample();

int main(){
    Tree tree(createExample());
    TreeMetrics metrics;
    std::cout<<"Sum: "<<metrics.sum(tree.root)<<std::endl;
    std::cout<<"Avg: "<<metrics.average(tree.root)<<std::endl;
    std::cout<<"Median: "<<metrics.median(tree.root)<<std::endl;
}

Node *createExample(){
    Node *r = new Node(5, 
                      new Node(3, 
                              new Node(2,nullptr,nullptr), 
                              new Node(5,nullptr,nullptr)
                              ), 
                      new Node(7,
                               new Node(1,nullptr,nullptr),
                               new Node(0,
                                        new Node(2,nullptr,nullptr),
                                        new Node(8,nullptr,
                                                 new Node(5,nullptr,nullptr)
                                                )
                                       )
                             )
                      );
    return r;
}