#include <iostream>
#include <vector>

using namespace std;

void permutation_with_visited(vector<vector<int>>& results,
        vector<int>& result,
        vector<int>& nums,
        vector<int>& visited,
        int target) {
    // boundary
    if (target == 0) {
        results.push_back(result);
        return;
    }

    // loop
    for (int i = 0; i < (int)nums.size(); ++i) {
        if (visited[i] == 1) continue;
        visited[i] = 1;
        result.push_back(nums[i]);
        permutation_with_visited(results, result, nums, visited, target - 1);
        result.pop_back();
        visited[i] = 0;
    }
}

// [1, 2, 3]
//
// 1 [2, 3]
// 2 [[3]] => [2, 3]  
// 3 [[2]] => [3, 2]  => [[2, 3], [3, 2]]
// [[1, 2, 3], [1, 3, 2]]

vector<vector<int>> permutation_with_next_nums(vector<int>& nums, int level) {
    vector<vector<int>> ans{}, cur_ans{};
    if (level == 1) {
        for (int i = 0; i < (int)nums.size(); ++i) {
            ans.push_back(vector<int>{nums[i]});
        }
        return ans;
    }
    vector<int> next_nums;
    for (int i = 0; i < (int)nums.size(); ++i) {
        next_nums = nums;
        next_nums.erase(next_nums.begin() + i);
        cur_ans = permutation_with_next_nums(next_nums, level - 1);
        for (int j = 0; j < (int)cur_ans.size(); ++j) {
            cur_ans[j].insert(cur_ans[j].begin(), nums[i]);
        }
        ans.insert(ans.end(), cur_ans.begin(), cur_ans.end());
    }
    return ans;
}

int main() {
    vector<int> nums{1, 2, 3, 4}, result{}, visited(nums.size(), 0);
    vector<vector<int>> results{};
    //permutation_with_visited(results, result, nums, visited, 3);
    results = permutation_with_next_nums(nums, 2);
    for (auto x : results) {
        for (auto xx : x) {
            cout<<xx<<" ";
        }
        cout<<endl;
    }
    cout<<"total size:"<<results.size()<<endl;
    return 0;
}
