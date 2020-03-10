#include "TreeMetrics.h"

double TreeMetrics::average(Node *node){
    if(node==nullptr)
        throw std::invalid_argument("Node pointer cannot be null!");

    return (double)TreeMetrics::sum(node) / (double)TreeMetrics::countElements(node);

}

int TreeMetrics::countElements(Node *node){
    if(node == nullptr)
        return 0;

    if(this->mem_count.find(node) == this->mem_count.end())        
        this->mem_count[node] = (1 + TreeMetrics::countElements(node->left) + TreeMetrics::countElements(node->right));

    return this->mem_count[node];
}

int TreeMetrics::sum(Node *node){
    if(node == nullptr)
        return 0;

    if(this->mem_sum.find(node) == this->mem_sum.end())        
        this->mem_sum[node] = (node->data + TreeMetrics::sum(node->left) + TreeMetrics::sum(node->right));

    return this->mem_sum[node];
}

void TreeMetrics::_merge(std::vector<int> &elements, std::vector<int> &left_elements, std::vector<int> &right_elements, int data){
    bool data_not_taken = true;
    int l = 0, r = 0;
    while((int)left_elements.size() > l && (int)right_elements.size() > r){
        if(data_not_taken && data <= std::min(left_elements[l], right_elements[r])){
            elements.push_back(data);
            data_not_taken = false;
        }else{
            if(left_elements[l] <= right_elements[r]){
                elements.push_back(left_elements[l++]);
            }else{
                elements.push_back(right_elements[r++]);
            }
        }
    }    
    while((int)left_elements.size() > l){
        if(data_not_taken && data <= left_elements[l]){
            elements.push_back(data);
            data_not_taken = false;            
        }else
            elements.push_back(left_elements[l++]);
    }
    while((int)right_elements.size() > r){
        if(data_not_taken && data <= right_elements[r]){
            elements.push_back(data);
            data_not_taken = false;            
        }else
            elements.push_back(right_elements[r++]);
    }
    if(data_not_taken)
        elements.push_back(data);

}

void TreeMetrics::_median(Node *node, std::vector<int> &elements){
    if(node==nullptr)
        return;

    std::vector<int> left_elements;
    _median(node->left, left_elements);

    std::vector<int> right_elements;
    _median(node->right, right_elements);
    
    _merge(elements, left_elements, right_elements, node->data);

    if(elements.size() % 2 == 1)
        this->mem_median[node] = 2*elements[(elements.size()/2)];
    else 
        this->mem_median[node] = elements[(elements.size()/2)] + elements[(elements.size()/2)-1];
}

double TreeMetrics::median(Node *node){
    if(node==nullptr)
        throw std::invalid_argument("Node pointer cannot be null!");

    if(this->mem_median.find(node) == this->mem_median.end()){
        std::vector<int> elements; 
        _median(node, elements);
    }
    
    return ((double)this->mem_median[node])/2.;
}