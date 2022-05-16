#include <iostream>
#include <vector>
using namespace std;

/* 题目说明：
    假设你是一位很棒的家长，想要给你的孩子们一些小饼干，但是，每个孩子最多只能给一块饼干。
    对每个孩子i，都有一个胃口值g[i]，这是能让孩子们满足胃口的饼干的最小尺寸；并且每块饼干j，
    都有一个尺寸s[j]，如果s[j] >= g[i]，我们可以将这个饼干j分配给孩子i，这个孩子会得到满足。
    你的目标是尽可能满足越多数量的孩子，而不浪费饼干。并输出这个最大数值。
    
    示例 1:
    输入: g = [1,2,3], s = [1,1]
    输出: 1 解释:你有三个孩子和两块小饼干，3个孩子的胃口值分别是：1,2,3。虽然你有两块小饼干，由于他们的尺寸都是1，你只能让胃口值是1的孩子满足。所以你应该输出1。
    
    示例 2:
    输入: g = [1,2], s = [1,2,3]
    输出: 2
    解释:你有两个孩子和三块小饼干，2个孩子的胃口值分别是1,2。你拥有的饼干数量和尺寸都足以让所有孩子满足。所以你应该输出2.
    提示：

    1 <= g.length <= 3 * 10^4
    0 <= s.length <= 3 * 10^4
    1 <= g[i], s[j] <= 2^31 - 1
*/

void printVector(const vector<int>& v){
    for(vector<int>::const_iterator it = v.begin(); it != v.end(); it++){
        cout << *it << " ";
    }
    cout << endl;
}

class Solution{
public:
    // children_g:孩子的胃口值数组，cookie_s:饼干尺寸数组。
    // 解法一：大饼干先喂饱大胃口的孩子
    int findMaxChildrenSatified01(vector<int>& children_g, vector<int>& cookie_s){
        // 现对孩子胃口和饼干尺寸从小到大排序
        sort(children_g.begin(), children_g.end());
        sort(cookie_s.begin(), cookie_s.end());
        // 饼干从最后开始索引
        int result = 0;
        int index = cookie_s.size() - 1;
        for(int i = children_g.size()-1; i >= 0; i--){
            if(index >= 0 && cookie_s[index] >= children_g[i]){
                result++;
                index--;
            }
        }
        return result;
    }
    int findMaxChildrenSatified02(vector<int>& children_g, vector<int>& cookie_s){
        // 现对孩子胃口和饼干尺寸从小到大排序
        sort(children_g.begin(), children_g.end());
        sort(cookie_s.begin(), cookie_s.end());
        int result = 0;
        int index = 0;
        for(int i = 0; i < children_g.size(); i++){
            if(index <= cookie_s.size()-1 && cookie_s[index] >= children_g[i]){
                result++;
                index++;
            }
        }
        return result;
    }
};

void test01(){
    Solution s;
    vector<int> children_g;
    vector<int> cookie_s;
    int n;
    cout << "请输入孩子的胃口值：" << endl;
    while(cin >> n){
        children_g.push_back(n);
        if(cin.get() == '\n') break;
    }
    
    cout << "请输入饼干的尺寸：" << endl;
    while(cin >> n){
        cookie_s.push_back(n);
        if(cin.get() == '\n') break;
    }
    // printVector(children_g);
    // printVector(cookie_s);
    cout << "在不浪费饼干的前提下能尽可能多的满足孩子胃口的孩子的数量为：\n" << s.findMaxChildrenSatified01(children_g, cookie_s) << endl;
}

void test02(){
    Solution s;
    vector<int> children_g;
    vector<int> cookie_s;
    int n;
    cout << "请输入孩子的胃口值：" << endl;
    while(cin >> n){
        children_g.push_back(n);
        if(cin.get() == '\n') break;
    }
    
    cout << "请输入饼干的尺寸：" << endl;
    while(cin >> n){
        cookie_s.push_back(n);
        if(cin.get() == '\n') break;
    }
    // printVector(children_g);
    // printVector(cookie_s);
    cout << "在不浪费饼干的前提下能尽可能多的满足孩子胃口的孩子的数量为：\n" << s.findMaxChildrenSatified01(children_g, cookie_s) << endl;
}

int main(){
    // test01();
    test02();
    return 0;
}