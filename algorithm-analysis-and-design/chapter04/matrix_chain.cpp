#include <iostream>
#include <vector>
#include <unordered_map>

using namespace std;

struct Matrix {
    int row;
    int col;
};

// 返回方案数量，不保留细节，即分割点和计算次数
// 失败：这种方式求出来的全排列会有重复的情况
// 共计六种全排列0 1 2/0 2 1/1 0 2/1 2 0/2 0 1/2 1 0 其中 0 2 1 和 2 0 1 重复
void matrix_chain_with_backtracking_not_saving_detail(vector<Matrix>& matrixs, int& result, unordered_map<int, int> visited, int target) {
    // boudary
    if (target == 0) {
        ++result;
        return;
    }

    // dfs for loop
    for (int i = 0; i < (int)matrixs.size() - 1; ++i) {
        if (visited[i] == 1) continue;
        visited[i] = 1;
        //cout<<"selected:"<<i<<endl;
        matrix_chain_with_backtracking_not_saving_detail(matrixs, result, visited, target - 1);
        visited[i] = 0;
    }
}

// 分治法
// 只返回方案数量
// 成功！
int matrix_chain_with_divide_and_conquer_not_saving_detail(int n) {
    // boundary
    if (n == 1) return 1;
    int result = 0;

    // loop
    for (int k = 1; k < n; ++k) {
        result += matrix_chain_with_divide_and_conquer_not_saving_detail(k)
            * matrix_chain_with_divide_and_conquer_not_saving_detail(n - k);
    }

    return result;
}

// 分治法 + 备忘录法
// 返回最优解，不够造最优解
unordered_map<int, unordered_map<int, int>> m;
int matrix_chain_with_divide_and_conquer_return_optimal_value(vector<Matrix>& matrixs, int start, int end) {
    if (m[start][end] != 0) return m[start][end];
    // boundary
    if (start >= end) {
        return 0;
    }
    if (start + 1 == end) {
        m[start][end] = matrixs[start].row * matrixs[start].col * matrixs[end].col;
        return m[start][end];
    }

    // declare
    int ans = INT_MAX, min = INT_MAX;
    for (int k = start; k <= end - 1; ++k) {
        ans = matrix_chain_with_divide_and_conquer_return_optimal_value(matrixs, start, k)
            + matrix_chain_with_divide_and_conquer_return_optimal_value(matrixs, k + 1, end)
            + matrixs[start].row * matrixs[k].col * matrixs[end].col;
        if (min > ans) min = ans;
    }
    m[start][end] = min;

    return min;
}

// 分治法 + 备忘录法
// 返回最优解，存储最优解过程
unordered_map<int, unordered_map<int, int>> s;
int matrix_chain_with_divide_and_conquer_return_optimal_value_saving_tracking(vector<Matrix>& matrixs, int start, int end) {
    if (m[start][end] != 0) return m[start][end];
    // boundary
    if (start >= end) {
        return 0;
    }
    if (start + 1 == end) {
        s[start][end] = start;
        m[start][end] = matrixs[start].row * matrixs[start].col * matrixs[end].col;
        return m[start][end];
    }

    // declare
    int ans = INT_MAX, min = INT_MAX;
    s[start][end] = start;
    for (int k = start; k <= end - 1; ++k) {
        ans = matrix_chain_with_divide_and_conquer_return_optimal_value_saving_tracking(matrixs, start, k)
            + matrix_chain_with_divide_and_conquer_return_optimal_value_saving_tracking(matrixs, k + 1, end)
            + matrixs[start].row * matrixs[k].col * matrixs[end].col;
        if (min > ans) {
            min = ans;
            s[start][end] = k;
        }
    }
    m[start][end] = min;

    return min;
}

int main() {
    vector<Matrix> matrixs{Matrix{50, 10}, Matrix{10, 40}, Matrix{40, 30}, Matrix{30, 5}};
    //vector<Matrix> matrixs{Matrix{50, 10}, Matrix{10, 40}, Matrix{40, 30}};
    int result = 0;
    //unordered_map<int, int> visited{};
    //matrix_chain_with_backtracking_not_saving_detail(matrixs, result, visited, matrixs.size() - 1);
    //result = matrix_chain_with_divide_and_conquer_not_saving_detail(matrixs.size());
    result = matrix_chain_with_divide_and_conquer_return_optimal_value_saving_tracking(matrixs, 0, matrixs.size() - 1);
    cout<<result<<endl;
    cout<<"optimal sub-problem"<<endl;
    for (auto x : m) {
        for (auto xx : x.second) {
            cout<<x.first<<" "<<xx.first<<" value:"<<xx.second<<endl;
        }
    }
    cout<<"backtracking"<<endl;
    for (auto x : s) {
        for (auto xx : x.second) {
            cout<<x.first<<" "<<xx.first<<" value:"<<xx.second<<endl;
        }
    }
    return 0;
}

