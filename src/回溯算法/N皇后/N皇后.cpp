#include <algorithm>
#include <iostream>
#include <vector>
#include <unordered_set>
using namespace std;
#define N 0;

/* 题目说明：
    n皇后问题，研究的是如何将n个皇后放置在nxn的棋盘上，并且使皇后彼此之间不能相互攻击
    给你一个整数n，返回所有不同的n皇后问题的解决方案
    每一种解法包含一个不同的n皇后问题的棋子放置方案，该方案中'Q'和'.'分别代表了皇后和空位。
    
    皇后的走法是：可以横走，直走，斜走，格数不限。因此要求皇后彼此之间不能相互攻击，
    等价于要求任何两个皇后都不能在同一行、同一列以及同一条斜线上。aa
*/

namespace printFunc{
    void printVector(const vector<string>& v){
        for(vector<string>::const_iterator it = v.begin(); it != v.end(); it++){
            cout << *it << endl;
        }
    }
    void printVector(const vector<int>& v){
        for(vector<int>::const_iterator it = v.begin(); it != v.end(); it++){
            cout << *it << " ";
        }
        cout << endl;
    }
    void printVector(const vector<vector<string> >& v2, int n){
        int no = 1;
        for(vector<vector<string> >::const_iterator it = v2.begin(); it != v2.end(); it++){
            cout << "棋盘: " << no << endl;
            cout << " ";
            for(int i = 0; i < n; i++){
                cout << "-";
            }
            cout << "--" << endl;
            cout << "|" << "  ";
            for(int i = 0; i < n; i++){
                cout << i;
            }
            cout << "|";
            cout << endl;
            int column = 0;
            for(vector<string>::const_iterator vit = it->begin(); vit != it->end(); vit++){
                cout << "|" << column << " " << *vit << "|" << endl;
                ++column;
            }
            cout << " ";
            for(int i = 0; i < n; i++){
                cout << "-";
            }
            cout << "--" << endl;
            cout << endl;
            no++;
        }
    }
}
using namespace printFunc;
namespace test{
    // 生成棋盘测试
    vector<string> generateBoard(vector<int>& queens, int n){
        auto board = vector<string>();
        for(int i = 0; i < n; i++){
            string row = string(n, '.');
            row[queens[i]] = 'Q';
            board.push_back(row);
        }
        return board;
    }
    void test_board(){
        vector<int> queens;
        cout << "请输入皇后的位置：" << endl;
        int pos;
        for(int i = 0; i < 4; i++){
            cin >> pos;
            queens.push_back(pos);
        }
        cout << "queens的位置分布为：";
        printVector(queens);
        printVector(generateBoard(queens, 4));

    }
}
using namespace test;

class Solution{
public:
    // 返回一个vector<vector<string>>的容器，存放可能的多种棋盘布局方式。
    // 因为题目要求棋盘的样式为'.'代表空为，'Q'代表皇后位，所以棋盘布局是string容器。
    vector<vector<string> > nQueenAnswer(int n){
        // 首先定义好要解决的方案，待最后解决了返回。
        auto solutions = vector<vector<string> >();
        // 初始化每一个布局的皇后的信息，初始皇后没有摆位，位置信息赋值为-1。
        auto queens = vector<int>(n,-1);
        // 每个皇后都会绑定三个信息，列数，反斜角值，正斜角值。判断是否冲突，每个皇后的这三个值是固定的。
        #if 1
            auto column = unordered_set<int>();
            auto diagonals_p = unordered_set<int>();
            auto diagonals_n = unordered_set<int>();
        #endif
        #if 0
            auto column = vector<int>();
            auto diagonals_p = vector<int>();
            auto diagonals_n = vector<int>();
        #endif
        backstack(solutions, queens, n, 0, column, diagonals_p, diagonals_n);
        return solutions;
    }
private:
    // 棋盘显示的样式封装为一个函数方便使用
    vector<string> generateBoard(vector<int>& queens, int n){
        vector<string> board;
        for(int i = 0; i < n; i++){
            string row = string(n, '.');
            row[queens[i]] = 'Q';
            board.push_back(row);
        }
        return board;
    }
    // 回溯函数，也即是递归函数
    void backstack(vector<vector<string> >& solutions, vector<int>& queens, int n, int row, unordered_set<int>& column, unordered_set<int>& diagonals_p, unordered_set<int>& diagonals_n){
        if(row == n){
            solutions.push_back(generateBoard(queens, n));
        }else{
            for(int i = 0; i < n; i++){
                if(column.find(i) != column.end()) continue;
                int diagonal_p = row - i;
                if(diagonals_p.find(diagonal_p) != diagonals_p.end()) continue;
                int diagonal_n = row + i;
                if(diagonals_n.find(diagonal_n) != diagonals_n.end()) continue;
                queens[row] = i;
                column.insert(i);
                diagonals_p.insert(diagonal_p);
                diagonals_n.insert(diagonal_n);
                backstack(solutions, queens, n, row+1, column, diagonals_p, diagonals_n);
                queens[row] = -1;
                column.erase(i);
                diagonals_p.erase(diagonal_p);
                diagonals_n.erase(diagonal_n);
            }
            
        }
    }
    void backstack(vector<vector<string> >& solutions, vector<int>& queens, int n, int row, vector<int>& column, vector<int>& diagonals_p, vector<int>& diagonals_n){
        if(row == n){
            solutions.push_back(generateBoard(queens, n));
        }else{
            for(int i = 0; i < n; i++){
                if(find(column.begin(), column.end(), i) != column.end()) continue;
                int diagonal_p = row - i;
                if(find(diagonals_p.begin(), diagonals_p.end(), diagonal_p) != diagonals_p.end()) continue;
                int diagonal_n = row + i;
                if(find(diagonals_n.begin(), diagonals_n.end(), diagonal_n) != diagonals_n.end()) continue;
                queens[row] = i;
                column[i] = i;
                diagonals_p[i] = diagonal_p;
                diagonals_n[i] = diagonal_n;
                backstack(solutions, queens, n, row+1, column, diagonals_p, diagonals_n);
                queens[row] = -1;
                column.erase(find(column.begin(), column.end(), i));
                diagonals_p.erase(find(diagonals_p.begin(),diagonals_p.end(),diagonal_p));
                diagonals_n.erase(find(diagonals_n.begin(),diagonals_n.end(), diagonal_n));
            }
            
        }
    }
};

void test01(){
    Solution s;
    int n;
    cout << "请输入皇后的数量：";
    cin >> n;
    printVector(s.nQueenAnswer(n), n);
}

int main(){
    // test_board();
    test01();
    return 0;
}