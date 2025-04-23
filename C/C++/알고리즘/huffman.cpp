#include <iostream>
#include <queue>
#include <functional>
using namespace std;

struct tree {
    char ch;
    int fq;
    tree* left;
    tree* right;
    tree() {};
    tree(char ch, int fq) : ch(ch), fq(fq), left(nullptr), right(nullptr) {};
    
    tree(int fq) : ch('\0'), fq(fq), left(nullptr), right(nullptr) {};
};

struct compare {
    bool operator()(tree* a, tree* b) {
        return a->fq > b->fq;
    }
};


tree* new_node(struct tree* left, struct tree* right) {
    tree* temp = new tree(left->fq+right->fq);
    temp->left = left;
    temp->right = right;

    return temp;
}

int main(void) {
    priority_queue<tree*, vector<tree*>, compare> pq;
    pq.push(new tree('f', 5));
    pq.push(new tree('e', 9));
    pq.push(new tree('c', 12));
    pq.push(new tree('b', 13));
    pq.push(new tree('d', 16));
    pq.push(new tree('a', 45));

    tree* root;

    while(size(pq) >= 2) {
        tree* left = pq.top();
        pq.pop();
        
        tree* right = pq.top();
        pq.pop();
    

        pq.push(new_node(left, right));

    }

    root = pq.top();


    return 0;
}