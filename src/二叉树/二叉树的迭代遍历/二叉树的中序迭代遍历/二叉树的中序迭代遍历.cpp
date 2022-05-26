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
    // 二叉树的中序迭代遍历，使用栈操作，左中右
    vector<int> inorderTraversal(TreeNode* root){
        stack<TreeNode*> st;
        vector<int> result;
        if(root == nullptr) return result;
        TreeNode* cur = root;
        while(cur != nullptr || !st.empty()){
            if(cur != nullptr){
                st.push(cur);
                cur = cur->left;
            }else{
                cur = st.top();
                st.pop();
                result.push_back(cur->val);
                cur = cur->right;
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