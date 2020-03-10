#include "TreeMetrics.h"
#include "Node.h"
#include "Tree.h"
#include<iostream> 

Node *create_example();

int main(){
    Tree tree(create_example());
    TreeMetrics metrics;
    std::cout<<"Sum: "<<metrics.sum(tree.root)<<std::endl;
    std::cout<<"Avg: "<<metrics.average(tree.root)<<std::endl;
    std::cout<<"Median: "<<metrics.median(tree.root)<<std::endl;
}

Node *create_example(){
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