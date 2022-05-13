#include <iostream>
using namespace std;

/* 题目说明：
    给定一个长度为n的整数数组 height 。有 n 条垂线，第 i 条线的两个端点是 （i，0） 和 （i， height[i]）。
    找出其中的两条线，使得它们与x轴共同构成的容器可以容纳最多的水。
    返回容器可以存储的最大水量
*/

class Solution{
public:
    int maxArea(int* height, int len){
        int left = 0, right = len - 1;
        int ans = 0;
        while( left < right ){
            int area = min(height[left], height[right]) * (right - left);
            ans = max(ans, area);
            if(height[left] <= height[right]) ++left;
            else --right;
        }
        return ans;
    }
};

void test01(){
    Solution s;
    int arr_len;
    cout << "请输入数组长度：";
    cin >> arr_len;
    int arr[arr_len];
    cout << "请输入数组元素（以空格或者回车分隔）：\n";
    for(int i = 0; i < arr_len; i++){
        cin >> arr[i];
    }
    int maxArea = s.maxArea(arr, arr_len);
    cout << "盛最多水的容器是：" << maxArea << endl;    

}

int main(){
    test01();
    return 0;
}