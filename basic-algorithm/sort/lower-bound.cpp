#include<bits/stdc++.h>
using namespace std;
int main() {
    int myints[] = {10,20,30,30,20,10,10,20};
    std::vector<int> v(myints,myints+8); 
                                                              // 0  1  2  3  4  5  6  7
    std::sort (v.begin(), v.end(), greater());                // 10 10 10 20 20 20 30 30
    std::vector<int>::iterator low,up;

    // binary search m >= t, 第一个大于等于 t 的位置
    // binary search m <= t, 最后一个小于等于 t 的位置
    // 升序数组, lower_bound, less 第一个 >= t 的位置
    // 降序数组, lower_bound, greater 第一个 <= t 的位置
    // 升序数组, upper_bound, less 第一个 > t 的位置
    // 降序数组, upper_bound, greater 第一个 < t 的位置
    low=std::lower_bound (v.begin(), v.end(), 20, greater());
    up= std::upper_bound (v.begin(), v.end(), 20, greater());

    std::cout << "lower_bound at position " << (low- v.begin()) << '\n';
    std::cout << "upper_bound at position " << (up - v.begin()) << '\n';

    return 0;
}
