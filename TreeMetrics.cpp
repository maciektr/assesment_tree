#include "TreeMetrics.h"

double TreeMetrics::average(Node *node){
    return (double)TreeMetrics::sum(node) / (double)TreeMetrics::count_elements(node);
}

int TreeMetrics::count_elements(Node *node){
    if(node == nullptr)
        return 0;
    return 1 + TreeMetrics::count_elements(node->left) + TreeMetrics::count_elements(node->right);
}

int TreeMetrics::sum(Node *node){
    if(node == nullptr)
        return 0;
    return node->data + TreeMetrics::sum(node->left) + TreeMetrics::sum(node->right);
}