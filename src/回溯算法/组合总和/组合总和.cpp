#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

/* 题目说明：
    找出所有相加之和为n的k个数的组合。组合中只允许含有1-9的正整数，并且每种组合中不存在重复的数字。
    说明：
    所有数字都是正整数
    解集不能包含重复的组合
*/

void printVector(const vector<vector<int> >& v2){
    int count = 1;
    for(vector<vector<int> >::const_iterator it = v2.begin(); it != v2.end(); it++){
        cout << count << ": ";
        for(vector<int>::const_iterator vit = it->begin(); vit != it->end(); vit++){
            cout << *vit << " ";
        }
        cout << endl;
        count++;
    }
}

// 因为解集组合不能重复，最好利用剪枝+回溯的算法。因为如果k大于3以后，多层for循环效率太低，且难以实现。
class Solution{
private:
    // 因为是返回的解集的组合。所以定一个一个嵌套的容器
    vector<vector<int> > results;
    // 再定义一个组合的结果容器
    vector<int> result;
private:
    // 以下是回溯函数的实现
    void backstacking(int sum, int k, int startIndex){
        if(result.size() == k && sum == 0){
            results.push_back(result);
            return;
        }
        if(sum < 0){return;}
        // 采用剪枝的做法，n的范围已经给定是1-9，即9个数字取值范围
        for(int i = startIndex; i < 9-(k-result.size())+1; i++){
            result.push_back(i);    // 处理节点的任务
            // 因为题目要求组合中数字不能重复，所以是i+1，如果允许重复则是startIndex+1。
            backstacking(sum-i, k, i+1);  // 递推回溯
            result.pop_back();  // 回溯报销处理的节点。
        }
    }
public:
    // 提供一个公共的接口处理组合问题，参数按题目说明，传入相加之和的n和组合中元素的个数k
    vector<vector<int> > combine(int sum, int k){
        // 多层for循环采用回溯的解法，题目说明组合中只允许含有1-9的正整数已经定下来了。如果没定下来，则还需传入取值范围
        backstacking(sum, k, 1);
        return results;
    }

};

class Solution02{
private:
    // 因为是返回的解集的组合。所以定一个一个嵌套的容器
    vector<vector<int> > results;
    // 再定义一个组合的结果容器
    vector<int> result;
private:
    // 以下是回溯函数的实现
    void backstacking(int targetSum, int k, int n, int sum, int startIndex){
        if(result.size() == k){
            if(targetSum == sum){
                results.push_back(result);
                return;
            }else{
                return;
            }
        }
        // 采用剪枝的做法，n的范围已经给定是1-9，即9个数字取值范围
        for(int i = startIndex; i < n-(k-result.size())+1; i++){
            sum += i;
            result.push_back(i);    // 处理节点的任务
            // 因为题目要求组合中数字不能重复，所以是i+1，如果允许重复则是startIndex+1。
            backstacking(targetSum, k, n, sum, i+1);  // 递推回溯
            result.pop_back();  // 回溯报销处理的节点。
            sum -= i;   // 回溯报销处理的节点
        }
    }
public:
    // 提供一个公共的接口处理组合问题，参数按题目说明，传入相加之和的n和组合中元素的个数k
    vector<vector<int> > combine(int targetSum, int k, int n){
        // 多层for循环采用回溯的解法，题目说明组合中只允许含有1-9的正整数已经定下来了。如果没定下来，则还需传入取值范围
        backstacking(targetSum, k, n, 0, 1);
        return results;
    }

};

void test01(){
    Solution s;
    int targetSum;
    int k;
    cout << "请输入求取的总和为： ";
    cin >> targetSum;
    cout << "请输入取数大小： ";
    cin >> k;
    printVector(s.combine(targetSum, k));
}

void test02(){
    Solution02 s02;
    int targetSum;
    int k;
    int n;
    cout << "请输入求取的总和为： ";
    cin >> targetSum;
    cout << "请输入取数大小： ";
    cin >> k;
    cout << "请输入取值的范围： ";
    cin >> n;
    printVector(s02.combine(targetSum, k, n));
}

int main(){
    // test01();
    test02();
    return 0;
}