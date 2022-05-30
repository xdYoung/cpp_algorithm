#include <iostream>
#include <algorithm>
#include <vector>
using namespace std;

/* 题目说明：
    给你一个包含n个整数的数组 nums，判断 nums 中是否存在三个元素 a，b，c，使得 a+b+c=0 ? 
    请你找出所有和为0的三元组。
    提示：
    0 <= nums.length <= 3000
    -10<5> <= nums[i] <= 10<5>
*/

void printVector(const vector<int>& v){
    for(vector<int>::const_iterator it = v.begin(); it != v.end(); it++){
        cout << *it << " ";
    }
    cout << endl;
}
void printVector(const vector<vector<int> >& v){
    for(vector<vector<int> >::const_iterator it = v.begin(); it != v.end(); it++){
        for(vector<int>::const_iterator vit = it->begin(); vit != it->end(); vit++){
            cout << *vit << " ";
        }
        cout << " | ";
    }
    cout << endl;
}

int binary_search_complete(int k, vector<int>& v){
    int lo = 0, hi = v.size() - 1;
    while(lo <= hi){
        int mid = lo + (hi - lo)/2;
        if(k < v[mid]) hi = mid - 1;
        else if(k > v[mid]) lo = mid + 1;
        else return mid;
    }
    return -1;
}

class Solution{
public:
    // 解法一：暴力解法
    vector<vector<int> > tree_num_sum01(const vector<int>& v){
        vector<vector<int> > v1;
        vector<int> v2;
        int cnt = 0;
        for(int i = 0; i < v.size(); i++){
            for(int j = i+1; j < v.size(); j++){
                for(int k = j+1; k < v.size(); k++){
                    if(v[i] + v[j] + v[k] == 0){
                        v2.push_back(v[i]);
                        v2.push_back(v[j]);
                        v2.push_back(v[k]);
                        v1.push_back(v2);
                        v2.resize(0);
                        cnt++;
                    }
                }
            }
        }
        cout << "三数之和为0的组合数有：" << cnt << " 个" << endl;
        return v1;
    }

    // 解法二：二分查找法
    vector<vector<int> > tree_num_sum02(vector<int> v){
        vector<vector<int> > v1;
        vector<int> v2;
        sort(v.begin(), v.end());
        cout << "排序后的vector："; printVector(v);
        cout << v.size() << v[20] << endl;
        int cnt = 0;
        int index;
        for(int i = 0; i < v.size(); i++){
            for(int j = i+1; j < v.size(); j++){
                index = binary_search_complete((-v[i]-v[j]),v);
                if(index > j){
                    v2.push_back(v[i]);
                    v2.push_back(v[j]);
                    v2.push_back(v[index]);
                    v1.push_back(v2);
                    v2.resize(0);
                    cnt++;
                }
            }
        }
        cout << "三数之和为0的组合数有：" << cnt << " 个" << endl;
        return v1;
    }
};

// 解法一：暴力解法
void test01(){
    Solution s1;
    vector<int> v;
    int num;
    cout << "请输入vector数组的值（以空格分隔）：\n";
    while(cin >> num){
        v.push_back(num);
        if(cin.get() == '\n') break;
    }
    cout << "vector："; printVector(v);
    printVector(s1.tree_num_sum01(v));
}
// 解法二：二分查找法
void test02(){
    Solution s2;
    vector<int> v;
    int num;
    cout << "请输入vector数组的值（以空格分隔）：\n";
    while(cin >> num){
        v.push_back(num);
        if(cin.get() == '\n') break;
    }
    cout << "vector："; printVector(v);
    printVector(s2.tree_num_sum02(v));
}

int main(){
    test01();
    test02();
    return 0;
}