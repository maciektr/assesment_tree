#ifndef TREE_METRICS_H
#define TREE_METRICS_H

#include "Node.h"
#include<unordered_map>
#include<stack>
#include <queue>
#include <vector>

class TreeMetrics{
    public:
        int median(Node *node);
        double average(Node *node);
        int sum(Node *node);
        
    private:
        typedef std::priority_queue<int> pque_max;
        typedef std::priority_queue<int, std::vector<int>, std::greater<int> > pque_min;

        int count_elements(Node *node);
        void _median(Node *node, TreeMetrics::pque_max &smaller, TreeMetrics::pque_min &larger);

        std::unordered_map<Node *,int> mem_count;
        std::unordered_map<Node *,int> mem_sum;
        std::unordered_map<Node *,int> mem_median;
};
#endif