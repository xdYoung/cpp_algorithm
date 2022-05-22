#include <iostream>
#include <unordered_set>
#include <vector>
using namespace std;

/* 题目说明：
    给定两个数组，编写一个函数来计算它们的交集。
    说明： 输出结果中的每个元素一定是唯一的。 我们可以不考虑输出结果的顺序。
*/

void printVector(const vector<int>& v){
    for(vector<int>::const_iterator it = v.begin(); it != v.end(); it++){
        cout << *it << " ";
    }
    cout << endl;
}

class Solution{
public:
    vector<int> intersection(vector<int> nums1, vector<int> nums2){
        unordered_set<int> result_set;
        unordered_set<int> nums_set(nums1.begin(), nums1.end());
        for(int num: nums2){
            if(nums_set.find(num) != nums_set.end()){
                result_set.insert(num);
            }
        }
        return vector<int>(result_set.begin(), result_set.end());
    }
};

void test01(){
    Solution s;
    vector<int> nums1;
    vector<int> nums2;
    int n;
    cout << "请输入nums1的数据：" << endl;
    while(cin >> n){
        nums1.push_back(n);
        if(cin.get() == '\n') break;
    }
    cout << "请输入nums2的数据：" << endl;
    while(cin >> n){
        nums2.push_back(n);
        if(cin.get() == '\n') break;
    }
    cout << "nums1: ";
    printVector(nums1);
    cout << "nums2: ";
    printVector(nums2);
    cout << "intersection: ";
    printVector(s.intersection(nums1, nums2));
}

int main(){
    test01();
    return 0;
}