#include <iostream>
using namespace std;

/* 题目说明:
    给定一个赎金信 (ransom) 字符串和一个杂志(magazine)字符串，
    判断第一个字符串 ransom 能不能由第二个字符串 magazines 里面的字符构成。
    如果可以构成，返回 true ；否则返回 false。

    (题目说明：为了不暴露赎金信字迹，要从杂志上搜索各个需要的字母，
    组成单词来表达意思。杂志字符串中的每个字符只能在赎金信字符串中使用一次。)

    注意：
    你可以假设两个字符串均只含有小写字母。
    canConstruct("a", "b") -> false
    canConstruct("aa", "ab") -> false
    canConstruct("aa", "aab") -> true
*/

class Solution{
public:
    // 暴力解法
    bool canConstruct01(string ransom, string magazine){
        for(int i = 0; i < magazine.length(); i++){
            for(int j = 0; j < ransom.length(); j++){
                if(ransom[j] == magazine[i]){
                    ransom.erase(ransom.begin() + j);
                    break;
                }
            }
        }
        if(ransom.length() == 0){
            return true;
        }
        return false;
    }
    
public:
    // 哈希解法
    bool canConstruct02(string ransom, string magazine){
        int record[26] = {0};
        for(int i = 0; i < magazine.length(); i++){
            record[magazine[i] - 'a']++;
        }
        for(int i = 0; i < ransom.length(); i++){
            record[ransom[i] - 'a']--;
            if(record[ransom[i]-'a'] < 0) return false;
        }
        return true;
    }
};

void test01(){
    Solution s;
    string ransom;
    string magazine;
    cout << "请输入ransom字符串：" << endl;
    cin >> ransom;
    cout << "请输入magazine字符串：" << endl;
    cin >> magazine;
    cout << (s.canConstruct01(ransom, magazine) ? "ransom中的字符串【可以】由magazine中的字符组成！" : "ransom中的字符【不可以】由magazine中的字符组成！") << endl;
    cout << (s.canConstruct02(ransom, magazine) ? "ransom中的字符串【可以】由magazine中的字符组成！" : "ransom中的字符【不可以】由magazine中的字符组成！") << endl;

}

int main(){
    test01();
    return 0;
}