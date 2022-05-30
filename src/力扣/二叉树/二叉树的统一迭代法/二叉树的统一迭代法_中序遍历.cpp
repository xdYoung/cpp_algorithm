#include <iostream>
#include <vector>
#include <stack>
using namespace std;

struct TreeNode{
    int val;
    TreeNode* left;
    TreeNode* right;
    TreeNode(int x):val(x), left(NULL), right(NULL){}
};

class Solution {
public:
    vector<int> inorderTraversal(TreeNode* root) {
        vector<int> result;
        stack<TreeNode*> st;
        if (root != NULL) st.push(root);
        while (!st.empty()) {
            TreeNode* node = st.top();
            if (node != NULL) {
                st.pop(); // 将该节点弹出，避免重复操作，下面再将右中左节点添加到栈中
                if (node->right) st.push(node->right);  // 添加右节点（空节点不入栈）

                st.push(node);                          // 添加中节点
                st.push(NULL); // 中节点访问过，但是还没有处理，加入空节点做为标记。

                if (node->left) st.push(node->left);    // 添加左节点（空节点不入栈）
            } else { // 只有遇到空节点的时候，才将下一个节点放进结果集
                st.pop();           // 将空节点弹出
                node = st.top();    // 重新取出栈中元素
                st.pop();
                result.push_back(node->val); // 加入到结果集
            }
        }
        return result;
    }
};

void printVector(const vector<int>& v){
    for(vector<int>::const_iterator it = v.begin(); it != v.end(); it++){
        cout << *it << " ";
    }
    cout << endl;
}

void test01(){
    // 构建一个二叉树
    TreeNode root(24);
    TreeNode root_left01(23);
    TreeNode root_right01(25);
    root.left = &root_left01;
    root.right = &root_right01;

    TreeNode root_lleft02(21);
    TreeNode root_lright02(22);
    root_left01.left = &root_lleft02;
    root_left01.right = &root_lright02;

    TreeNode root_rleft02(26);
    TreeNode root_rright02(27);
    root_right01.left = &root_rleft02;
    root_right01.right = &root_rright02;

    TreeNode root_lleft03(19);
    TreeNode root_lright03(20);
    root_lleft02.left = &root_lleft03;
    root_lleft02.right = &root_lright03;

    TreeNode root_lleft04(17);
    root_lleft03.left = &root_lleft04;

    // 遍历二叉树
    Solution s;
    printVector(s.inorderTraversal(&root));
}

int main(){
    test01();
    return 0;
}