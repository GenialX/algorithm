#include <iostream>
#include <vector>

using namespace std;

void dfs(vector<vector<int>>& results, vector<int>& nums, vector<int>& curr, int target, int level) {
    // boundary
    if (target == 0) {
        results.push_back(curr);
        return;
    } 

    // loop
    for (int i = level; i < (int)nums.size(); ++i) {
        curr.push_back(nums[i]);
        dfs(results, nums, curr, target - 1, i + 1);
        curr.pop_back();
    }
}

int main() {
    vector<int> nums{1, 2, 3, 4, 5}, curr{};
    vector<vector<int>> results{};
    dfs(results, nums, curr, 3, 0);
    for (auto x : results) {
        for (auto xx : x) {
            cout<<xx<<" ";
        }
        cout<<endl;
    }
    cout<<"total size:"<<results.size()<<endl;
    return 0;
}


