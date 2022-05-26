#include <iostream>
using namespace std;

/*
    二叉树主要有两种遍历方式：
    深度优先遍历：先往深走，遇到叶子节点再往回走。
    广度优先遍历：一层一层的去遍历。
    这两种遍历是图论中最基本的两种遍历方式，后面在介绍图论的时候 还会介绍到。

    那么从深度优先遍历和广度优先遍历进一步拓展，才有如下遍历方式：

    深度优先遍历
    前序遍历（递归法，迭代法）
    中序遍历（递归法，迭代法）
    后序遍历（递归法，迭代法）
    广度优先遍历
    层次遍历（迭代法）
    在深度优先遍历中：有三个顺序，前中后序遍历， 有同学总分不清这三个顺序，经常搞混，我这里教大家一个技巧。

    这里前中后，其实指的就是中间节点的遍历顺序，只要大家记住 前中后序指的就是中间节点的位置就可以了。

    看如下中间节点的顺序，就可以发现，中间节点的顺序就是所谓的遍历方式

    前序遍历：中左右
    中序遍历：左中右
    后序遍历：左右中

    之前我们讲栈与队列的时候，就说过栈其实就是递归的一种是实现结构，
    也就说前中后序遍历的逻辑其实都是可以借助栈使用非递归的方式来实现的。

    而广度优先遍历的实现一般使用队列来实现，这也是队列先进先出的特点所决定的，
    因为需要先进先出的结构，才能一层一层的来遍历二叉树。
*/

// 节点的定义
struct TreeNode{
    int val;
    TreeNode* left;
    TreeNode* right;
    TreeNode(int x):val(x), left(NULL), right(NULL){}
};

void test01(){
    struct TreeNode node(6);
    TreeNode node_left01 = TreeNode(5);
    TreeNode node_right01 = 8;
    node.left = &node_left01;
    node.right = &node_right01;

    cout << node.val << endl;
    cout << node.left->val << endl;
    cout << node.right->val << endl;
}

int main(){
    test01();
    return 0;
}