#include <iostream>
#include <vector>
using namespace std;

// 二叉树的节点定义
struct TreeNode{
    int val;
    TreeNode* left;
    TreeNode* right;
    TreeNode(){}
    TreeNode(int x):val(x), left(NULL), right(NULL){}
};

// 递归遍历
class Solution{
private:
    // 二叉树的前序递归遍历 - 中左右
    void traversal(TreeNode* cur, vector<int>& v){
        if(cur == nullptr) return;
        traversal(cur->left, v);    // 左
        traversal(cur->right, v);   // 右
        v.push_back(cur->val);        // 中
    }
public:
    vector<int> postorderTraversal(TreeNode* root){
        vector<int> result;
        traversal(root, result);
        return result;
    }
};