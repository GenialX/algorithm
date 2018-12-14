#include <iostream>
#include <vector>
#include<ctime>

using namespace std;

void combination_with_for_in_recursive(vector<vector<int>>& results, vector<int>& nums, vector<int>& result, int level, int target) {
    // boundary
    if (target == 0) {
        results.push_back(result);
        return;
    }
    // loop
    for (int i = level; i < nums.size(); ++i) {
        result.push_back(nums[i]);
        combination_with_for_in_recursive(results, nums, result, i + 1, target - 1);
        result.pop_back();
    }
}

void combination_with_recursive(vector<vector<int>>& results, vector<int>& nums, vector<int>& result, int level, int target) {
    // boundary
    if (target == 0) {
        results.push_back(result);
        return;
    }
    if (level >= nums.size()) return;
    // loop
    // use it
    result.push_back(nums[level]);
    combination_with_recursive(results, nums, result, level + 1, target - 1);
    // not use it
    result.pop_back();
    combination_with_recursive(results, nums, result, level + 1, target);
}

int main() {
    //vector<int> nums{1, 2, 3, 4, 5, 6, 7, 8, 9, 10}, result{};
    vector<int> nums{1, 2, 3, 4}, result{};
    vector<vector<int>> results{};

    cout<<"combination_with_for_in_recursive:"<<endl;
    combination_with_for_in_recursive(results, nums, result, 0, 2);
    cout<<"total size:"<<results.size()<<endl;
    for (auto x : results) {
        for (auto xx : x) {
            cout<<xx<<" ";
        }
        cout<<endl;
    }

    cout<<"combination_with_recursive:"<<endl;
    results.clear();
    combination_with_recursive(results, nums, result, 0, 2);
    cout<<"total size:"<<results.size()<<endl;
    for (auto x : results) {
        for (auto xx : x) {
            cout<<xx<<" ";
        }
        cout<<endl;
    }
    return 0;
}


