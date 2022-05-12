#include <cstdint>
#include <iostream>
#include <cmath>
using namespace std;

/* 题目说明：
    给你一个32位的有符号整数x，返回将x中的数字部分反转后的结果。
    如果反转后整数超过32位的有符号整数的范围[-2<sup>31</sup>, 2<sup>31</sup> -1]，就返回0.
    假设环境不允许存储64位整数（有符号或无符号）.
*/

class Solution{
public:
    int reverse_int(int &x){
        int res = 0;
        while(x != 0){
            // 每次取末尾数字
            int tmp = x % 10;
            // // 判断是否大于最大32位整数
            // if(res > pow(2, 31)/10 || res == pow(2, 31)/10 && tmp > 7) return 0;
            // // 判断是否小于最小32位整数
            // if(res < -pow(2, 31)/10 || res == -pow(2, 31)/10 && tmp < -8) return 0;

            // 当x位正数并且和Integer.MAX_VALUE的位数相等时首位最大只能为2，所以逆转后不会出现
            // res = Integer.MAX_VALUE/10 && tmp>2的情况，反之负数情况也一样
            if(res > INT32_MAX/10 || res < INT32_MIN/10) return 0;
            res = res*10 + tmp;
            x /= 10;
        }
        return res;
    }
};

void test01(){
    Solution s;
    int num;
    cout << "请输入一个整数：";
    cin >> num;
    cout << "输入的整数是：" << num << endl;
    int reverse_num = s.reverse_int(num);
    cout << (reverse_num ? "反转的整数是："+to_string(reverse_num) : "超过32位整数范围！返回：0 ") << endl;
}

int main(){
    test01();
    return 0;
}