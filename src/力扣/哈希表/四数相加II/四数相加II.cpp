#include <iostream>
#include <unordered_map>
#include <vector>
using namespace std;

/* 题目说明：
    给定四个包含整数的数组列表 A , B , C , D ,计算有多少个元组 (i, j, k, l) ，
    使得 A[i] + B[j] + C[k] + D[l] = 0。
    为了使问题简单化，所有的 A, B, C, D 具有相同的长度 N，且 0 ≤ N ≤ 500 。
    所有整数的范围在 -2^28 到 2^28 - 1 之间，最终结果不会超过 2^31 - 1 。

    例如:
    输入: A = [ 1, 2] B = [-2,-1] C = [-1, 2] D = [ 0, 2] 输出: 2 解释: 两个元组如下:
    (0, 0, 0, 1) -> A[0] + B[0] + C[0] + D[1] = 1 + (-2) + (-1) + 2 = 0
    (1, 1, 0, 0) -> A[1] + B[1] + C[0] + D[0] = 2 + (-1) + (-1) + 0 = 0
*/

class Solution{
public:
    int fourSumCount(vector<int> A, vector<int> B, vector<int> C, vector<int> D){
        unordered_map<int, int> fmap;    //key:a+b的数值，value:a+b数值出现的次数
        // 遍历大A和大B数组，统计两个数组元素之和，和出现的次数，放到map中
        for(int a: A){
            for(int b: B){
                fmap[a+b]++;
            }
        }
        int count = 0;  // 统计a+b+c+d = 0 出现的次数
        // 在遍历大C和大D数组，找到如果 0-(c+d) 在map中出现过的话，就把map中key对应的value也就是出现次数统计出来。
        for(int c: C){
            for(int d: D){
                if(fmap.find(0-(c+d)) != fmap.end()){
                    count += fmap[0-(c+d)];
                }
            }
        }
        return count;
    }
};

void test01(){
    Solution s;
    vector<int> A;
    vector<int> B;
    vector<int> C;
    vector<int> D;
    int n;
    cout << "请输入A的元素：" << endl;
    while(cin >> n){
        A.push_back(n);
        if(cin.get() == '\n') break;
    }
    cout << "请输入B的元素：" << endl;
    while(cin >> n){
        B.push_back(n);
        if(cin.get() == '\n') break;
    }
    cout << "请输入C的元素：" << endl;
    while(cin >> n){
        C.push_back(n);
        if(cin.get() == '\n') break;
    }
    cout << "请输入D的元素：" << endl;
    while(cin >> n){
        D.push_back(n);
        if(cin.get() == '\n') break;
    }
    cout << "四数相加为0的元组个数为：" << s.fourSumCount(A, B, C, D) << " 个！" << endl;
}

int main(){
    test01();
    return 0;
}