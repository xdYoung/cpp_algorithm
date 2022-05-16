#include <iostream>
#include <string>
#include <vector>
using namespace std;

/* 题目说明：
    给定两个整数n和k，返回范围[1,n]中所有可能的k个数的组合。
    可按任意顺序返回答案
*/
// 剪枝+回溯优化

string toString(int n){
    if(n < 10){
        return "   " + to_string(n);
    }else if(n<100){
        return "  " + to_string(n);
    }else if(n<100){
        return " " + to_string(n);
    }else{
        return to_string(n);
    }
}

void printVector(const vector<vector<int> >& v2){
    int count = 1;
    for(vector<vector<int> >::const_iterator it = v2.begin(); it != v2.end(); it++){
        cout << toString(count) << ": ";
        for(vector<int>::const_iterator vit = it->begin(); vit != it->end(); vit++){
            cout << toString(*vit) << " ";
        }
        cout << endl;
        count++;
    }
}

class Solution{
private:
    vector<vector<int> > results;    // 存放符合条件结果的集合
    vector<int> result; // 存放符合条件的结果
private:
    void backstacking(int n, int k, int startIndex){
        if(result.size() == k){
            results.push_back(result);
            return;
        }
        /*
        // 循环的次数根据k值决定的：(剪枝优化)
            // 已经选取的元素个数：result.size();
            // 还需要的元素个数：k - result.size();
            // 在每一层，集合n中至多需要从起始位置遍历到：(n - (k - result.size())) + 1 这个次数。
            // +1是因为包括起始位置，左闭的集合。
        */
        for(int i = startIndex; i <= n - (k - result.size()) + 1; i++){   // 剪枝优化
            result.push_back(i);    // 处理节点
            backstacking(n, k, i+1);   // 递推
            result.pop_back();  // 回溯，报销处理的节点
        }
    }
public:
    vector<vector<int> > combine(int n, int k){
        backstacking(n, k, 1);
        return results;
    }
};

void test01(){
    Solution s;
    int n;
    int k;
    cout << "请输入取数范围： ";
    cin >> n;
    cout << "请输入取数大小： ";
    cin >> k;
    printVector(s.combine(n, k));
}

int main(){
    test01();
    return 0;
}