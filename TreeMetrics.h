#ifndef TREE_METRICS_H
#define TREE_METRICS_H

#include "Node.h"
#include<unordered_map>
#include<stack>
#include <queue>
#include <vector>

class TreeMetrics{
    public:
        double median(Node *node);
        double average(Node *node);
        int sum(Node *node);

    private:
        int count_elements(Node *node);
        void _median(Node *node, std::vector<int> &elements);
        void _merge(std::vector<int> &elements, std::vector<int> &left_elements, std::vector<int> &right_elements, int data);

        std::unordered_map<Node *,int> mem_count;
        std::unordered_map<Node *,int> mem_sum;
        std::unordered_map<Node *,int> mem_median;
};
#endif