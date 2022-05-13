#include <cstddef>
#include <iostream>
#include <vector>
using namespace std;

/* 题目说明：
    给你一个包含n个整数的数组 nums，判断 nums 中是否存在三个元素 a，b，c，使得 a+b+c=0 ? 
    请你找出所有和为0且不重复的三元组。
    提示：
    0 <= nums.length <= 3000
    -10<5> <= nums[i] <= 10<5>
*/

void printVector(const vector<int>& v){
    for(vector<int>::const_iterator it = v.begin(); it != v.end(); it++){
        cout << *it << " ";
    }
    cout << endl;
}
void printVector(const vector<vector<int> >& v){
    for(vector<vector<int> >::const_iterator it = v.begin(); it != v.end(); it++){
        for(vector<int>::const_iterator vit = it->begin(); vit != it->end(); vit++){
            cout << *vit << " ";
        }
        cout << " | ";
    }
    cout << endl;
}

class Solution{
public:
    vector<vector<int> > three_num_sum_norepeat01(vector<int> v){
        vector<vector<int> > v2;
        vector<int> v1;
        sort(v.begin(),v.end());
        cout << "排序后vector: "; printVector(v);
        int N = v.size();
        int cnt = 0;
        for(int first = 0; first < N; ++first){
            if(v[first] == v[first-1]) continue;
            // 如何排序后第一个数都大于0了，则三数相加结果不可能为0；后续则不需要再循环了
            if(v[first] > 0) break;
            int third = N - 1;
            int target = -v[first];
            for(int second = first+1; second < N; ++second){
                if(v[second] == v[second-1]) continue;
                while(second < third && v[second]+v[third] > target){
                    --third;
                }
                if(second == third) break;
                if(v[second]+v[third]==target){
                    v1.push_back(v[first]);
                    v1.push_back(v[second]);
                    v1.push_back(v[third]);
                    v2.push_back(v1);
                    v1.resize(0);
                    cnt++;
                }
            }
        }
        cout << "不重复的三数之和的数量为：" << cnt << endl;
        return v2;
    }

};

void test01(){
    Solution s;
    vector<int> v;
    cout << "请输入vector的数值(以空格分隔)：\n";
    int num;
    while(cin >> num){
        v.push_back(num);
        if(cin.get() == '\n') break;
    }
    cout << "排序前vector: "; printVector(v);
    printVector(s.three_num_sum_norepeat01(v));
}

int main(){
    test01();
    return 0;
}

