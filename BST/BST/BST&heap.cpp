// contains all algorithms for lecture 8

#include <iostream>

struct tnode{
    int key;
    tnode* left;
    tnode* right;
    tnode(int k) {
            key = k;
            left = nullptr;
            right = nullptr;
        }
    
};

tnode* contains (tnode* root, int k){
    
    tnode* v = root;
    
    while (v != nullptr) {
            if (k == v->key) {
                return v;
            } else if (k < v->key) {
                v = v->left;
            } else {
                v = v->right;
            }
        }
    
    return nullptr;
}


tnode* insert (tnode* root, int k){
    if (root == nullptr) {
        return new tnode(k);
    }
    if (k< root->key) {
        root->left = insert(root->left,k);
    }
    
    else if (k> root->key) {
        root->right = insert(root->right,k);
    }
        
    return root;
}


tnode* symmetric_successor(tnode* root, int k) {
    tnode* v = contains(root, k);

    if (v == nullptr || v->right == nullptr) {
        return nullptr;
    }

    // Find leftmost node in right subtree
    tnode* w = v->right;
    while (w->left != nullptr) {
        w = w->left;
    }

    return w;
}

tnode* remove(tnode* root, int k ){
    
    tnode* TBD = contains(root, k);
    if (TBD==nullptr){
        return root; // key wasnt found
    }
    
    if (k< root->key) {
        root->left = remove(root->left, k);
    }
    
    else if (k>root->key) {
        root->right = remove(root->right, k);
    }
    
    else {
        // No kids
        if (root->left == nullptr && root->right ==nullptr) {
            delete root;
            return nullptr;
        }
        // One kid
        
        else if (root->left ==nullptr){
            tnode* temp = root->right;
            delete root;
            return temp;
        }
        
        else if (root->right ==nullptr) {
            tnode* temp = root->left;
            delete root;
            return temp;
        }
        
        //two kids
        
        else {
            tnode* successor = symmetric_successor(root,k);
            root->key= successor->key;
            root->right = remove (root->right, successor->key);
        }
    }
    return root;
}

void SiftUp(std::vector<int>& nums, int m){
    
    int v = nums[m];
    int c = m;
    int p = floor(c-1)/2;
    while (c>0 && v> nums[p]) {
        nums[c] = nums [p];
        c = p;
        p =floor(c-1)/2;
    }
    nums[c] = v;
}

// siftdown

//max heap extraction

// heap sort ( nlog n)n 
