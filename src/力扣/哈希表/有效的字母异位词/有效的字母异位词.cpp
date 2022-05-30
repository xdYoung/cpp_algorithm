#include <iostream>
#include <string>
using namespace std;

/* 题目说明：
    给定两个字符串 s 和 t ，编写一个函数来判断 t 是否是 s 的字母异位词。
    示例 1: 输入: s = "anagram", t = "nagaram" 输出: true
    示例 2: 输入: s = "rat", t = "car" 输出: false
    说明: 你可以假设字符串只包含小写字母。  
*/

class Solution{
public:
    bool isAnagram(string s1, string t){
        int record[26] = {0};
        for(int i = 0; i < s1.size(); i++){
            // 并不需要记住字符a的ASCII，只要求出一个相对数值就可以了
            record[s1[i] - 'a']++;
        }
        for(int i = 0; i < t.size(); i++){
            record[t[i] - 'a']--;
        }
        for(int i = 0; i < 26; i++){
            // record数组如果有的元素不为零0，说明字符串s1和s2 一定是谁多了字符或者谁少了字符。
            if(record[i] != 0) return false;
        }
        // record数组所有元素都为零0，说明字符串s1和s2是字母异位词
        return true;
    }
};

void test01(){
    Solution s;
    string s1;
    string s2;
    cout << "请输入字符串s1: ";
    cin >> s1;
    cout << "请输入字符串s2: ";
    cin >> s2;
    cout << (s.isAnagram(s1, s2) ? s1+"和"+s2+":是字母异位词" : s1+"和"+s2+":不是字母异位词") << endl;

}

int main(){
    test01();
    return 0;
}