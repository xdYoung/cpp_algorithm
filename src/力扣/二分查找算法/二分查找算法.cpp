#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

class Solution{
public:
    int binarySearch01(int key, int arr[], int len){
        int lo = 0;
        int hi =  len - 1;
        while(lo <= hi){
            int mid = lo + (hi - lo)/2;
            if(key < arr[mid]) hi = mid - 1;
            else if(key > arr[mid]) lo = mid + 1;
            else return mid;
        }
        return -1;
    }

    int binarySearch02(int key, vector<int> v){
        sort(v.begin(), v.end());
        int lo = 0;
        int hi =  v.size() - 1;
        while(lo <= hi){
            int mid = lo + (hi - lo)/2;
            if(key < v[mid]) hi = mid - 1;
            else if(key > v[mid]) lo = mid + 1;
            else return mid;
        }
        return -1;
    }
};

void printVector(const vector<int>& v){
    for(vector<int>::const_iterator it = v.begin(); it != v.end(); it++){
        cout << *it << " ";
    }
    cout << endl;
}
void printArr(const int arr[], int len){
    for(int i = 0; i < len; i++){
        cout << arr[i] << " ";
    }
    cout << endl;
}

void test01(){
    Solution s;
    int arr[] = {1,2,3,4,5,7,8,9,10};
    int len = sizeof(arr)/sizeof(int);
    printArr(arr,len);
    int index = s.binarySearch01(6, arr, len);
    cout << "查找到序号：" << index << endl;
}
void test02(){
    Solution s;
    vector<int> v;
    for(int i = 0; i < 20; i++){
        v.push_back(i+2);
    }
    printVector(v);
    int index = s.binarySearch02(6, v);
    cout << "查找到序号：" << index << endl;
}

int main(){
    test01();
    test02();
    return 0;
}