#include <iostream>
#include <string>
#include <unordered_set>
using namespace std;

/* 题目说明：
    编写一个算法来判断一个数 n 是不是快乐数。
    「快乐数」定义为：对于一个正整数，每一次将该数替换为它每个位置上的数字的平方和，
    然后重复这个过程直到这个数变为 1，也可能是 无限循环 但始终变不到 1。
    如果 可以变为  1，那么这个数就是快乐数。
    如果 n 是快乐数就返回 True ；不是，则返回 False 。

    示例：
    输入：19
    输出：true
    解释：
    1^2 + 9^2 = 82
    8^2 + 2^2 = 68
    6^2 + 8^2 = 100
    1^2 + 0^2 + 0^2 = 1
*/

class Solution{
private:
    // 取数值各个位上的单数之和
    int getSum(int n){
        int sum = 0;
        while(n){
            sum += (n%10) * (n%10);
            n /= 10;  
        }
        return sum;
    }
public:
    bool isHappyNum(int num){
        unordered_set<int> result_sum;
        while(1){
            int sum = getSum(num);
            if(sum == 1) return true;
            if(result_sum.find(sum) != result_sum.end()){
                return false;
            }else{
                result_sum.insert(sum);
            }
            num = sum;
        }
    }
};

void test01(){
    Solution s;
    int n;
    cout << "请输入一个数：";
    cin >> n;
    cout << (s.isHappyNum(n) ? to_string(n)+"：是快乐数！" : to_string(n)+"：不是快乐数！") << endl;
}

int main(){
    test01();
    return 0;
}