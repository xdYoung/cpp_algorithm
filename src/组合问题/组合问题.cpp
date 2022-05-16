#include <iostream>
#include <vector>
using namespace std;

/* 题目说明：
    给定两个整数n和k，返回范围[1,n]中所有可能的k个数的组合。
    可按任意顺序返回答案
*/
void printVector(const vector<vector<int> > v2){
    for(vector<vector<int> >::const_iterator it = v2.begin(); it != v2.end(); it++){
        for(vector<int>::const_iterator vit = it->begin(); vit != it->end(); vit++){
            cout << *vit << " ";
        }
        cout << endl;
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
        }
        for(int i = startIndex; i <= n; i++){
            result.push_back(i);    // 处理结点
            backstacking(n, k, i+1);   // 递推
            result.pop_back();  // 回溯，报销处理的结点
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