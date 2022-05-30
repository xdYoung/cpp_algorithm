#include <iostream>
#include <vector>
using namespace std;

/* 题目说明：
    给定n个非负整数表示每个宽度为1的柱子的高度图，计算按次排列的柱子，下雨之后能接多少雨水
*/

void printVector(const vector<int>& v){
    for(vector<int>::const_iterator it = v.begin(); it != v.end(); it++){
        cout << *it << " ";
    }
    cout << endl;
}

class Solution{
public:
    // 暴力解法：
    int trap01(vector<int> height){
        int ans = 0;    // answer:ans为总的接雨水的量
        int len = height.size();
        // 循环不包含取第一个和最后一个数。因为没意义。
        for(int i = 1; i < len - 1; i++){
            int max_left = 0, max_right = 0;
            // 向左遍历，获取左边最大的高度，最后的最大高度不小于height[i]，因为从i开始循环的。
            for(int j = i; j >= 0 ; j--){
                max_left = max(max_left, height[j]);
            }
            // 向右遍历，获取右边最大的高度，最后的最大高度不小于height[i]，因为从i开始循环的。
            for(int k = i; k < len; k++){
                max_right = max(max_right, height[k]);
            }
            // 每循环一次，取左边和右边的最小值减去当前循环的i的高度，即为当前i的高度能装多少水。
            // 然后累加到ans上。
            ans += min(max_left, max_right) - height[i];
        }
        return ans;
    }
    // 双指针解法：
    int trap02(vector<int> height){
        int left = 0, right = height.size() - 1;
        int ans = 0;
        int left_max = 0, right_max = 0;
        while(left < right){
            // cout << left << " ";
            if(height[left] < height[right]){
                (height[left] >= left_max) ? (left_max = height[left]) : ans += (left_max - height[left]);
                // left++;
                ++left;
            }else{
                (height[right] >= right_max) ? (right_max = height[right]) : ans += (right_max - height[right]);
                // right--;
                --right;
            }
            // cout << left << " ";
        }
        return ans;
    }
};
// 双指针解法，暴力解法
void test01(){
    Solution s;
    vector<int> v;
    int num;
    cout << "请输入vector的值: \n";
    while(cin >> num){
        v.push_back(num);
        if(cin.get() == '\n') break;
    }
    cout << "vector: ";
    printVector(v);
    cout << "能接的雨水总量为：" << s.trap01(v) << endl;
}
// 双指针解法，双指针解法
void test02(){
    Solution s;
    vector<int> v;
    int num;
    cout << "请输入vector的值: \n";
    while(cin >> num){
        v.push_back(num);
        if(cin.get() == '\n') break;
    }
    cout << "vector: ";
    printVector(v);
    cout << "能接的雨水总量为：" << s.trap02(v) << endl;
}

int main(){
    test01();
    test02();
    return 0;
}
