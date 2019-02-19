#include <iostream>
#include <vector>
#include <string>

using namespace std;

struct TreeNode {
    int val;
    TreeNode* left;
    TreeNode* right;
    TreeNode(int v) : val(v), left(nullptr), right(nullptr) {};
};

void s_preorder(TreeNode* node, vector<string>& result) {
    result.push_back(to_string(node->val));

    // next nodes
    if (node->left == nullptr) {
        result.push_back("null");
    } else {
        s_preorder(node->left, result);
    }
    if (node->right == nullptr) {
        result.push_back("null");
    } else {
        s_preorder(node->right, result);
    }
}

void s_inorder(TreeNode* node, vector<string>& result) {
    if (node->left == nullptr) {
        result.push_back("null");
    } else {
        s_inorder(node->left, result);
    }
    result.push_back(to_string(node->val));
    if (node->right == nullptr) {
        result.push_back("null");
    } else {
        s_inorder(node->right, result);
    }
}

void s_postorder(TreeNode* node, vector<string>& result) {
    if (node->left == nullptr) {
        result.push_back("null");
    } else {
        s_postorder(node->left, result);
    }
    if (node->right == nullptr) {
        result.push_back("null");
    } else {
        s_postorder(node->right, result);
    }
    result.push_back(to_string(node->val));
}

void r_preorder(vector<string>& data, int& index, TreeNode* node) {
    // current node
    node->val = atoi(data[index].c_str());
    // left node
    if (data[++index] == "null") {
        node->left = nullptr;
    } else {
        node->left = new TreeNode(0);
        r_preorder(data, index, node->left);
    }
    // right node
    if (data[++index] == "null") {
        node->right = nullptr;
    } else {
        node->right = new TreeNode(0);
        r_preorder(data, index, node->right);
    }
}

int main() {
    vector<string> data{"1", "2", "4", "null", "null", "5", "null", "null", "3", "null", "null"};
    cout<<"[preorder]:data source:"<<endl<<"1,2,4,null,null,5,null,null,3,null,null"<<endl;
    TreeNode* head = new TreeNode(0);
    int index = 0;
    r_preorder(data, index, head);
    vector<string> result{};
    s_preorder(head, result);
    for (auto x : result) {
        cout<<x<<",";
    }
    return 0;
}
