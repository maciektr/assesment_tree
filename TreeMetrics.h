#ifndef TREE_METRICS_H
#define TREE_METRICS_H

#include<map>
#include "Node.h"

class TreeMetrics{
    public:
        int median(Node *node);
        double average(Node *node);
        int sum(Node *node);
    private:
        int count_elements(Node *node);
        std::map<Node *,int> mem_count;
        std::map<Node *,int> mem_sum;
};
#endif