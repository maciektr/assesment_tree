#include "TreeMetrics.h"
#include "Node.h"
#include<iostream> 

Node *create_example();

int main(){
    Node *tree = create_example();
    TreeMetrics metrics;
    std::cout<<"Sum: "<<metrics.sum(tree)<<std::endl;
    std::cout<<"Avg: "<<metrics.average(tree)<<std::endl;
    std::cout<<"Median: "<<metrics.median(tree)<<std::endl;
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