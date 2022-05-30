#include <algorithm>
#include <iostream>
#include <stack>
#include <vector>
using namespace std;

struct TreeNode{
    int val;
    TreeNode* left;
    TreeNode* right;
    TreeNode(int x):val(x), left(NULL), right(NULL){}
};

class Solution{
public:
    // 二叉树的后序迭代遍历，使用栈操作，左右中
    vector<int> postorderTraversal(TreeNode* root){
        stack<TreeNode*> st;
        vector<int> result;
        if(root == nullptr) return result;
        st.push(root);
        while(!st.empty()){
            TreeNode* node = st.top();
            st.pop();
            result.push_back(node->val);
            // 相对于前序遍历中左右，只需改变一下顺序，最后再反转vector数组即可。
            // 中左右 -> 中右左 ->（反转）左右中
            if(node->left) st.push(node->left);
            if(node->right) st.push(node->right);
        }
        reverse(result.begin(), result.end());
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
    printVector(s.postorderTraversal(&root));
}

int main(){
    test01();
    return 0;
}