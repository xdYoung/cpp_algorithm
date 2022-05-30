#include <iostream>
#include <queue>
#include <vector>
using namespace std;

/*
    学会二叉树的层序遍历，可以一口气打完以下十题：

    102.二叉树的层序遍历
    107.二叉树的层次遍历II
    199.二叉树的右视图
    637.二叉树的层平均值
    429.N叉树的层序遍历
    515.在每个树行中找最大值
    116.填充每个节点的下一个右侧节点指针
    117.填充每个节点的下一个右侧节点指针II
    104.二叉树的最大深度
    111.二叉树的最小深度
*/
/*
    层序遍历一个二叉树。就是从左到右一层一层的去遍历二叉树。这种遍历的方式和我们之前讲过的都不太一样。
    需要借用一个辅助数据结构即队列来实现，队列先进先出，符合一层一层遍历的逻辑，而是用栈先进后出适合模拟深度优先遍历也就是递归的逻辑。
    而这种层序遍历方式就是图论中的广度优先遍历，只不过我们应用在二叉树上。
*/
/*
    给你一个二叉树，请你返回其按 层序遍历 得到的节点值。 （即逐层地，从左到右访问所有节点）。
    以下这份代码也可以作为二叉树层序遍历的模板，打十个就靠它了。
*/

struct TreeNode{
    int val;
    TreeNode* left;
    TreeNode* right;
    TreeNode(int x):val(x), left(NULL), right(NULL){}
};

class Solution {
public:
    vector<vector<int> > levelOrder(TreeNode* root) {
        queue<TreeNode*> que;
        if (root != NULL) que.push(root);
        vector<vector<int> > result;
        while (!que.empty()) {
            int size = que.size();
            vector<int> vec;
            // 这里一定要使用固定大小size，不要使用que.size()，因为que.size是不断变化的
            for (int i = 0; i < size; i++) {
                TreeNode* node = que.front();
                que.pop();
                vec.push_back(node->val);
                if (node->left) que.push(node->left);
                if (node->right) que.push(node->right);
            }
            result.push_back(vec);
        }
        return result;
    }
};

void printVector(const vector<vector<int> >& v){
    for(vector<vector<int> >::const_iterator it = v.begin(); it != v.end(); it++){
        for(vector<int>::const_iterator vit = it->begin(); vit != it->end(); vit++){
            cout << *vit << " ";
        }
        cout << endl;
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
    printVector(s.levelOrder(&root));
}

int main(){
    test01();
    return 0;
}