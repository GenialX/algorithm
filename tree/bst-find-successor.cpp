//https://www.youtube.com/watch?v=jma9hFQSCDk
#include<bits/stdc++.h>
using namespace std;
struct TreeNode {
    int val;
    TreeNode *left, *right;
    TreeNode(int v) : val(v), left(nullptr), right(nullptr) {};
};

TreeNode *root;
int val = 14, p = -1;
bool founds = false, foundp = false;

void inorder(TreeNode* node) {
    if (node == nullptr) return;
    if (foundp) return;
    inorder(node->left);
    if (foundp) return;
    if (founds) {
        foundp = true;
        p = node->val;
        return;
    }
    if (node->val == val) {
        founds = true;
    }
    inorder(node->right);
}

int main() {
    root = new TreeNode(20);
    root->left = new TreeNode(9);
    root->right = new TreeNode(25);
    auto node = root->left;
    node->left = new TreeNode(5);
    node->right = new TreeNode(12);
    node = node->right;
    node->left = new TreeNode(11);
    node->right = new TreeNode(14);

    inorder(root);

    cout << p << endl;

    return 0;
}
