#include <iostream>
#include <vector>
using namespace std;

struct Node {
    int data;
    Node* left;
    Node* right;

    Node(int val) : data(val), left(nullptr), right(nullptr) {};
};


void pre_order(Node* node, vector<int> &order) {
    if (node == nullptr) return;
    order.push_back(node->data);      // Root
    pre_order(node->left, order);     // Left
    pre_order(node->right, order);    // Right
}

void in_order(Node* node, vector<int> &order) {
    if (node == nullptr) return;
    in_order(node->left, order);      // Left
    order.push_back(node->data);      // Root
    in_order(node->right, order);     // Right
}

void post_order(Node* node, vector<int> &order) {
    if (node == nullptr) return;
    post_order(node->left, order);    // Left
    post_order(node->right, order);   // Right
    order.push_back(node->data);      // Root
}

// Helper to print the vector
void printVector(const string& name, const vector<int>& v) {
    cout << name << ": ";
    for (int num : v) {
        cout << num << " ";
    }
    cout << endl;
}

int main() {

    Node* root = new Node(1);
    root->left = new Node(2);
    root->right = new Node(3);
    root->left->left = new Node(4);
    root->left->right = new Node(5);
    root->right->right = new Node(6); 

    vector<int> preOrderVec;
    vector<int> inOrderVec;
    vector<int> postOrderVec;

    // Run Traversals
    pre_order(root, preOrderVec);
    in_order(root, inOrderVec);
    post_order(root, postOrderVec);

    printVector("Pre-Order ", preOrderVec);
    printVector("In-Order  ", inOrderVec);
    printVector("Post-Order", postOrderVec);

    return 0;
}