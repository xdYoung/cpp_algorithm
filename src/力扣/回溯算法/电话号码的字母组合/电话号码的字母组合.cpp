#include <iostream>
#include <vector>
using namespace std;

/* 题目说明：
    给定一个仅包含数字2-9的字符串，返回所有它能表示的字母组合。答案可以按任意顺序返回。
    给出的数字到字母的映射如下（与电话按键相同）。注意：1不对应任何字母。
    2-abc 3-def 4-ghi 5-jkl 6-mno 7-pqrs 8-tuv 9-wxyz
    
    示例 1：
    输入：digits = "23"
    输出：["ad","ae","af","bd","be","bf","cd","ce","cf"]
    
    示例 2：
    输入：digits = ""
    输出：[]

    示例 3：
    输入：digits = "2"
    输出：["a","b","c"]
*/

void printVector(const vector<string>& v){
    for(vector<string>::const_iterator it = v.begin(); it != v.end(); it++){
        cout << *it << " ";
    }
    cout << endl;
}

class Solution{
private:
    const string letterMap[10] = {
        "", "", "abc", "def", "ghi", "jkl", "mno", "pqrs", "tuv", "wxyz"};
    vector<string> result;
    string s;
private:
    void backstacking(const string& digits, int index){
        if(digits.length() == index) {
            result.push_back(s);
            return;
        }
        int digit = digits[index] - '0';
        // cout << digit << endl;
        string letters = letterMap[digit];
        for(int i = 0; i < letters.length(); i++){
            s.push_back(letters[i]);
            backstacking(digits, index+1);
            s.pop_back();
        }

    }
public:
    vector<string> letterCombination(const string& digits){
        if(digits.length() == 0) return result;
        backstacking(digits, 0);
        return result;
    }

};

void test01(){
    Solution s;
    string digits;
    cout << "请输入电话号码：";
    cin >> digits;
    // cout << digits << endl;
    printVector(s.letterCombination(digits));
}

int main(){
    test01();
    return 0;
}