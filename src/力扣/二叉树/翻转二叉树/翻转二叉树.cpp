#include <iostream>
#include <stack>
#include <queue>
using namespace std;

/*
    翻转一颗二叉树
*/

struct TreeNode{
    int val;
    TreeNode* left;
    TreeNode* right;
    TreeNode(int x):val(x), left(NULL), right(NULL){}
};

class Solution{
public:
    // 递归法翻转二叉树，只要把每个节点的左右孩子翻转就可以
    TreeNode* invertTree01(TreeNode* root){
        if(root == NULL) return root;
        swap(root->left, root->right);
        invertTree01(root->left);
        invertTree01(root->right);
        return root;
    }
    // 迭代法翻转二叉树
    TreeNode* invertTree02(TreeNode* root){
        if(root == NULL) return root;
        stack<TreeNode*> st;
        st.push(root);
        while(!st.empty()){
            TreeNode* node = st.top();
            st.pop();
            swap(node->left, node->right);
            if(node->right) st.push(node->right);
            if(node->left) st.push(node->left);
        }
        return root;
    }
    // 广度优先遍历，也即是层序遍历。
    TreeNode* invertTree03(TreeNode* root){
        if(root == NULL) return root;
        queue<TreeNode*> que;
        que.push(root);
        while(!que.empty()){
            int size = que.size();
            for(int i = 0; i < size; i++){
                TreeNode* node = que.front();
                que.pop();
                swap(node->left, node->right);
                if(node->left) que.push(node->left);
                if(node->right) que.push(node->right);
            }
        }
        return root;
    }
};