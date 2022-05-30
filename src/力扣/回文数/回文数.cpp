#include <cstdint>
#include <iostream>
#include <algorithm>
#include <string>
using namespace std;

/* 题目说明：
    给你一个整数x，如果x是一个回文整数，返回true；否则，返回false。
    回文数是指正序（从左向右）和倒序（从右向左）读都是一样的整数。
    例如：121是回文，123不是回文。
*/

class Solution{
public:
    // 解法一：将数字转换为字符串，反转字符串，然后判断是否相等即可
    bool isPalinDrome01(int x){
        string s = to_string(x);
        reverse(s.begin(), s.end());
        // cout << s << endl;
        return to_string(x) == s ? true : false;
    }
    // 解法二：将数字转换为字符串，反转字符串，然后判断是否相等即可，只用判断字符串的一半即可。
    bool isPalinDrome02(int x){
        string s = to_string(x);
        int len = s.length();
        bool flag = false;
        for(int i = 0; i < len/2; i++){
            if(s[i] == s[len-i-1]) flag = true;
            else{
                flag = false;
                break;
            }
        }
        return flag;
    }
    // 解法三：只判断正数回文
    bool isPalinDrome03(int x){
        // 如果末尾是0，直接返回false，因为数字开头不可能以0开头
        if(x<0 || (x % 10 == 0 && x != 0)) return false;
        
        int rev_num = 0;
        // 判断x是不是小于rev_num，如果小于rev_num，则说明数字已经过半。因为过半后，位数小的肯定更小。
        while(x > rev_num){
            rev_num = rev_num*10 + x % 10;
            x /= 10;
        }
        // 因为存在数字是奇偶数个，所以判断条件要加上如果是奇数个数字，需要除以10.
        return x == rev_num || x == rev_num / 10;
    }
    // 解法四：可以判断负数回文
    bool isPalinDrome04(int x){
        // 如果末尾是0，直接返回false，因为数字开头不可能以0开头
        if(x % 10 == 0 && x != 0) return false;
        if(x < 0) x = -x;
        
        int rev_num = 0;
        // 判断x是不是小于rev_num，如果小于rev_num，则说明数字已经过半。因为过半后，位数小的肯定更小。
        while(x > rev_num){
            rev_num = rev_num*10 + x % 10;
            x /= 10;
        }
        // 因为存在数字是奇偶数个，所以判断条件要加上如果是奇数个数字，需要除以10.
        return x == rev_num || x == rev_num / 10;
    }
};
// 转换为字符串判断回文
void test01(){
    Solution s1;
    int num;
    cout << "请输入一个整数：";
    cin >> num;
    cout << (s1.isPalinDrome01(num) ? to_string(num)+"：是回文数" : to_string(num)+"：不是回文数") << endl;

    cout << ((s1.isPalinDrome02(num)) ? to_string(num)+"：是回文数" : to_string(num)+"：不是回文数") << endl;
}
// 判断正数回文
void test02(){
    Solution s2;
    int num;
    cout << "请输入一个整数：";
    cin >> num;
    cout << (s2.isPalinDrome03(num) ? to_string(num)+"：是回文数" : to_string(num)+"：不是回文数") << endl;
}
// 可以判断负数回文
void test03(){
    Solution s3;
    int num;
    cout << "请输入一个整数：";
    cin >> num;
    cout << (s3.isPalinDrome04(num) ? to_string(num)+"：是回文数" : to_string(num)+"：不是回文数") << endl;
}

int main(){
    // test01();
    // test02();
    test03();
    return 0;
}