#include <cstdio>
#include <iostream>
#include <algorithm>
#include <string>
#include <string.h>
using namespace std;

/* 题目说明：
    给你两个字符串haystack和needle，请你在haystack字符串中找出needle字符串出现的第一个位置（下标从0开始）。如果不存在，则返回-1
    说明：
    当needle是空字符串时，我们应当返回什么值呢？这是一个在面试中很好的问题。
    对于本题而言，当needle时空字符串时我们应当返回0.这与C语言的strstr()以及java的indexOf()定义相符。
    提示：
    1 <= haystack.length, needle.length <= 10<4>
    haystack 和 needle 仅由小写英文字符组成。
*/

// 内置函数解法
namespace test{
    int strStr01(){
        cout << "请输入原字符串：\n";
        string s1;
        cin >> s1;
        cout << "请输入匹配字符串：\n";
        string s2;
        cin >> s2;
        system("clear");
        cout << "原字符串：" << s1 << endl;
        cout << "匹配字符串：" << s2 << endl;
        if(s1.empty() || s2.empty()) return 0;
        const char* p;
        p = strstr(s1.data(), s2.data());
        if(p == nullptr){
            cout << "未找到！" << endl;
            return -1;
        }
        else
        {
            cout << "匹配的位置是：" << p << endl;
            cout << "匹配的位置是：" << strstr(s1.c_str(), s2.c_str()) << endl;
            return 1;
        }  
    }

    int strStr02(){
        cout << "请输入原字符串：\n";
        string s1;
        while(cin >> s1){
            if(cin.get() == '\n') break;
        }
        cout << "请输入匹配字符串：\n";
        string s2;
        while(cin >> s2){
            if(cin.get() == '\n') break;
        }
        system("clear");
        cout << "原字符串：" << s1 << endl;
        cout << "匹配字符串：" << s2 << endl;
        if(s1.empty() || s2.empty()) return 0;
        int pos;
        pos = s1.find(s2, 0);
        return pos;
    }

    void test01(){
        cout << (strStr01()>0 ? "找到！" : "未找到！") << endl;
        int pos = strStr02();
        cout << (pos>0 ? "找到！: "+to_string(pos) : "未找到！") << endl;
    }
}
using namespace test;

class Solution{
public:
    // 暴力解法
    int strStr01(string haystack, string needle){
        int n = haystack.length(), m = needle.length();
        if(m == 0) {
            cout << "匹配字符串为空，返回0！" << endl;
            return 0;
        }
        for(int i = 0; i+m < n; i++){
            bool flag = true;
            for(int j = 0; j < m; j++){
                if(haystack[i+j] != needle[j]){
                    flag = false;
                    break;
                }
            }
            if(flag) return i;
        }
        return -1;
    }
    // KMP算法
    // 创建next数组并初始化
    void getNext(int* next, const string& s){
        int j = 0;
        next[0] = 0;
        for(int i = 1; i < s.size(); i++){
            while(j>0 && s[i] != s[j]){
                j = next[j - 1];
            }
            if(s[i] == s[j]){
                j++;
            }
            next[i] = j;
        }
    }
    int strStr02(string haystack, string needle){
        if(needle.size() == 0) return 0;
        int next[needle.size()];
        getNext(next, needle);
        int j = 0;
        for(int i = 0; i < haystack.size(); i++){
            while(j > 0 && i < haystack[i] != needle[j]){
                j = next[j - 1];
            }
            if(haystack[i] == needle[j]){
                j++;
            }
            if(j == needle.size()){
                return (i - needle.size() + 1);
            }
        }
        return -1;
    }
};
// 暴力解法测试
void test02(){
    Solution s;
    cout << "请输入原字符串：\n";
    string s1;
    // getline(istream &is, string str)
    getline(cin, s1);
    cout << "请输入匹配字符串：\n";
    string s2;
    getline(cin, s2);
    system("clear");
    cout << "原字符串：" << s1 << endl;
    cout << "匹配字符串：" << s2 << endl;
    int pos;
    pos = s.strStr01(s1, s2);
    cout << (pos>0 ? "找到！下标为："+to_string(pos) : "未找到！") << endl;
    
}
// KMP算法测试
void test03(){
    Solution s;
    cout << "请输入原字符串：\n";
    string s1;
    // getline(istream &is, string str)
    getline(cin, s1);
    cout << "请输入匹配字符串：\n";
    string s2;
    getline(cin, s2);
    system("clear");
    cout << "原字符串：" << s1 << endl;
    cout << "匹配字符串：" << s2 << endl;
    int pos;
    pos = s.strStr02(s1, s2);
    cout << pos << endl;
    cout << (pos>0 ? "找到！下标为："+to_string(pos) : "未找到！") << endl;

}

int main(){
    // test01();
    // test02();
    test03();
    return 0;
}