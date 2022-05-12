#include <iostream>
#include <vector>
#include <cmath>
using namespace std;

/* 题目说明：
    给你一个整数数组 nums，请你找出一个具有最大和的连续子数组（子数组最少包含一个元素），返回其最大和。
*/

class Solution{
public:
    int maxSubArray(int* nums, int len){
        int max_sub_sum;
        max_sub_sum = nums[0];
        for(int i = 1; i < len; i++){
            nums[i] = max(nums[i-1]+nums[i], nums[i]);
            max_sub_sum = max(max_sub_sum, nums[i]);
        }
        return max_sub_sum;
    }
};

void test01(){
    Solution s;
    int N;
    cout << "请输入数组的长度：";
    cin >> N;
    int nums[N];
    cout << "请输入数组的值（以空格分割）：\n";
    for(int i = 0; i < N; i++){
        cin >> nums[i];
    }
    cout << "最大子序和为：" << s.maxSubArray(nums, N) << endl;
    

}

int main(){
    test01();
    return 0;
}