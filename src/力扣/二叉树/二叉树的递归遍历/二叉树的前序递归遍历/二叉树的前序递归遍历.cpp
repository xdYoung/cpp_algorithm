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
        v.push_back(cur->val);        // 中
        traversal(cur->left, v);    // 左
        traversal(cur->right, v);   // 右
    }
public:
    vector<int> preorderTraversal(TreeNode* root){
        vector<int> result;
        traversal(root, result);
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
    TreeNode* root = new TreeNode;
    root->val = 24;
    TreeNode* root_left01 = new TreeNode;
    root_left01->val = 23;
    TreeNode* root_right01 = new TreeNode;
    root_right01->val = 25;
    root->left = root_left01;
    root->right = root_right01;
    TreeNode* root_lleft02 = new TreeNode;
    root_lleft02->val = 21;
    TreeNode* root_lright02 = new TreeNode;
    root_lright02->val = 22;
    root_left01->left = root_lleft02;
    root_left01->right = root_lright02;
    TreeNode* root_rleft02 = new TreeNode;
    root_rleft02->val = 26;
    TreeNode* root_rright02 = new TreeNode;
    root_rright02->val = 27;
    root_right01->left = root_rleft02;
    root_right01->right = root_rright02;
    TreeNode* root_lleft03 = new TreeNode;
    root_lleft03->val = 19;
    TreeNode* root_lright03 = new TreeNode;
    root_lright03->val = 20;
    root_lleft02->left = root_lleft03;
    root_lleft02->right = root_lright03;
    TreeNode* root_lleft04 = new TreeNode;
    root_lleft04->val = 17;
    root_lleft03->left = root_lleft04;

    // 遍历二叉树
    Solution s;
    printVector(s.preorderTraversal(root));


}
void test02(){
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
    printVector(s.preorderTraversal(&root));


}

int main(){
    test01();
    // test02();
    return 0;
}