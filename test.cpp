#include <iostream>
#include <cassert>

#include "TreeMetrics.h"
#include "Tree.h"
#include "Node.h"

const double epsilon = 1e-5;

void testExample();
void testNull();
void testList();
void testNegative();

Node *createExample();

int main(){
    testExample();
    testNull();
    testList();
    testNegative();
    std::cout<<"Passed!"<<std::endl;
}

void testNull(){
    Tree tree(nullptr);
    TreeMetrics metrics;

    assert(metrics.sum(tree.root) == 0);
    bool median_thrown = false;
    bool average_thrown = false;

    try{
        metrics.median(tree.root);
    }catch(std::invalid_argument& e){
        median_thrown = true;
    }

    try{
        metrics.average(tree.root);
    }catch(std::invalid_argument& e){
        average_thrown = true;
    }

    assert(median_thrown);
    assert(average_thrown);

}

void testList(){
    Node *ptr = new Node(0);
    for(int i = 1; i <= 1000; i++)
        ptr = new Node(i, ptr, nullptr);
    
    Tree tree(ptr);
    TreeMetrics metrics;

    assert(metrics.sum(ptr) == (500*1001));
    assert(abs(metrics.average(ptr) - 500.) < epsilon);
    assert(abs(metrics.median(ptr) - 500.) < epsilon);
}

void testNegative(){
    Tree tree(new Node(10, new Node(-3, new Node(-12),new Node(9)), new Node(-4, nullptr, new Node(0, new Node(-3), new Node(2)))));
    TreeMetrics metrics;

    assert(metrics.sum(tree.root) == -1); 
    assert(abs(metrics.average(tree.root) + 0.125 ) < epsilon);
    assert(abs(metrics.median(tree.root) + 1.5 ) < epsilon);
}

void testExample(){
    Tree tree(createExample());
    TreeMetrics metricsUp, metricsDown;
    double avg = metricsDown.average(tree.root);

    Node *ptr = tree.root->right->right->right->right;
    assert(abs(metricsDown.average(ptr) - metricsUp.average(ptr)) < epsilon);
    assert(abs(5. - metricsUp.average(ptr)) < epsilon);

    assert(abs(metricsDown.median(ptr) - metricsUp.average(ptr)) < epsilon);
    assert(abs(5. - metricsUp.average(ptr)) < epsilon);

    assert(metricsDown.sum(ptr) == metricsUp.sum(ptr));
    assert(metricsUp.sum(ptr) == 5);

    ptr = tree.root->right->right->right;
    assert(abs(metricsDown.average(ptr) - metricsUp.average(ptr)) < epsilon);
    assert(abs(6.5 - metricsUp.average(ptr)) < epsilon);

    assert(abs(metricsDown.median(ptr) - metricsUp.average(ptr)) < epsilon);
    assert(abs(6.5 - metricsUp.average(ptr)) < epsilon);

    assert(metricsDown.sum(ptr) == metricsUp.sum(ptr));
    assert(metricsUp.sum(ptr) == 13);

    ptr = tree.root->right->right;
    assert(abs(metricsDown.average(ptr) - metricsUp.average(ptr)) < epsilon);
    assert(abs(3.75 - metricsUp.average(ptr)) < epsilon);

    assert(abs(metricsDown.median(ptr) - metricsUp.average(ptr)) < epsilon);
    assert(abs(3.5- metricsUp.average(ptr)) < epsilon);

    assert(metricsDown.sum(ptr) == metricsUp.sum(ptr));
    assert(metricsUp.sum(ptr) == 15);

    ptr = tree.root->right;
    assert(abs(metricsDown.average(ptr) - metricsUp.average(ptr)) < epsilon);
    assert(abs(3.83333333 - metricsUp.average(ptr)) < epsilon);

    assert(abs(metricsDown.median(ptr) - metricsUp.average(ptr)) < epsilon);
    assert(abs(3.5- metricsUp.average(ptr)) < epsilon);

    assert(metricsDown.sum(ptr) == metricsUp.sum(ptr));
    assert(metricsUp.sum(ptr) == 23);

    ptr = tree.root->left;
    assert(abs(metricsDown.average(ptr) - metricsUp.average(ptr)) < epsilon);
    assert(abs(3.33333333 - metricsUp.average(ptr)) < epsilon);

    assert(abs(metricsDown.median(ptr) - metricsUp.average(ptr)) < epsilon);
    assert(abs(3- metricsUp.average(ptr)) < epsilon);

    assert(metricsDown.sum(ptr) == metricsUp.sum(ptr));
    assert(metricsUp.sum(ptr) == 10);

    assert(abs(metricsDown.average(tree.root) - metricsUp.average(tree.root)) < epsilon);
    assert(abs(3.8 - metricsUp.average(tree.root)) < epsilon);

    assert(abs(metricsDown.median(tree.root) - avg) < epsilon);
    assert(abs(4.- metricsUp.average(tree.root)) < epsilon);

    assert(metricsDown.sum(tree.root) == metricsUp.sum(tree.root));
    assert(metricsUp.sum(tree.root) == 38);
}

Node* createExample(){
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