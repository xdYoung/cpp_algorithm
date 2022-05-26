#include <iostream>
#include <vector>
#include <unordered_map>
using namespace std;

/* 题目说明：
    给定一个整数数组nums和一个目标值target，请你在该数组中找出和为目标值的那两个整数，
    并返回他们的数组下标
    你可以假设每种输入只会对应一个答案。但是，数组中的同一个元素不能使用两遍。
    示例：
    给定nums=[2,7,11,15],target=9
    因为nums[0]+nums[1]=2+7=9
    所以返回[0,1]
*/

class Solution{
public:
    vector<int> SumOfTwoNum(const vector<int> nums, int target){
        unordered_map<int,int> map;
        vector<int> result;
        for(int i = 0; i < nums.size(); i++){
            auto iter = map.find(target - nums[i]);
            if(iter != map.end()) {
                result.push_back(iter->second);
                result.push_back(i);
            }
            map.insert(pair<int, int>(nums[i], i));
        }
        return result;
    }
};

void test01(){
    Solution s;
    vector<int> nums;
    int target;
    int n;
    cout << "请输入数组sums中的元素：" << endl;
    while(cin >> n){
        nums.push_back(n);
        if(cin.get() == '\n') break;
    }
    cout << "请输入两数之和的目标值target：";
    cin >> target;
    cout << s.SumOfTwoNum(nums, target)[0] << "," << s.SumOfTwoNum(nums, target)[1] << endl;

}

int main(){
    test01();
    return 0;
}