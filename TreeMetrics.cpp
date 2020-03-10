#include "TreeMetrics.h"

double TreeMetrics::average(Node *node){
    return (double)TreeMetrics::sum(node) / (double)TreeMetrics::count_elements(node);
}

int TreeMetrics::count_elements(Node *node){
    if(node == nullptr)
        return 0;

    if(this->mem_count.find(node) == this->mem_count.end())        
        this->mem_count[node] = (1 + TreeMetrics::count_elements(node->left) + TreeMetrics::count_elements(node->right));

    return this->mem_count[node];
}

int TreeMetrics::sum(Node *node){
    if(node == nullptr)
        return 0;

    if(this->mem_sum.find(node) == this->mem_sum.end())        
        this->mem_sum[node] = (node->data + TreeMetrics::sum(node->left) + TreeMetrics::sum(node->right));

    return this->mem_sum[node];
}

void TreeMetrics::_median(Node *node, TreeMetrics::pque_max &smaller, TreeMetrics::pque_min &larger){
    if(node==nullptr)
        return;

    _median(node->left, smaller, larger);
    TreeMetrics::pque_max right_smaller;
    TreeMetrics::pque_min right_larger;
    _median(node->right, right_smaller, right_larger);
    smaller.push(node->data);
    
    while(!right_smaller.empty()){
        smaller.push(right_smaller.top());
        right_smaller.pop();
    }

    while(!smaller.empty() && smaller.size() > larger.size()){
        larger.push(smaller.top());
        smaller.pop();
    }

    while(!right_larger.empty()){
        smaller.push(right_larger.top());
        right_larger.pop();
    }

    while(!smaller.empty() && smaller.size() > larger.size()){
        larger.push(smaller.top());
        smaller.pop();
    }

    if(larger.size() == smaller.size())
        this->mem_median[node] = (larger.top() + smaller.top());
    else 
        this->mem_median[node] = 2*larger.top();
}

double TreeMetrics::median(Node *node){
    if(node==nullptr)
        throw std::invalid_argument("Node pointer cannot be null!");

    if(this->mem_median.find(node) == this->mem_median.end()){
        TreeMetrics::pque_max smaller; 
        TreeMetrics::pque_min larger; 
        _median(node, smaller, larger);
    }
    
    return ((double)this->mem_median[node])/2.;
}