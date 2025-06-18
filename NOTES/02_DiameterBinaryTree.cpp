#include <iostream>
#include <algorithm>
using namespace std;

// Node structure
struct Node {
    int data;
    Node* left;
    Node* right;

    Node(int val) {
        data = val;
        left = right = nullptr;
    }
};

// recursive functionswhich fids the height of the root amd also calculates diameter of tree
// bottom up recursive approch O(n)Time O(h)Space
int diameterRecur(Node* root, int& res) {
    // base case: tree is empty
    if (root == nullptr) return 0;

    // find the height of left and right subtree (it will also calculate diameter of left and right subtree)
    int lHeight = diameterRecur(root->left, res);
    int rHeight = diameterRecur(root->right, res);

    // check if diameter of the root is greater than res
    res = max(res, lHeight + rHeight);

    // return the height of current subtree
    return 1 + max(lHeight, rHeight); 
}

// Function to get diameter of a binary tree
int diameter(Node* root) {
    int res = 0;
    diameterRecur(root, res);
    return res;
}

// Main function
int main() {
    /* Constructed binary tree
         5
       /   \
      8     6
     / \   /
    3   7 9
    */
    Node* root = new Node(5);
    root->left = new Node(8);
    root->right = new Node(6);
    root->left->left = new Node(3);
    root->left->right = new Node(7);
    root->right->left = new Node(9);

    cout << diameter(root) << "\n";

    return 0;
}
