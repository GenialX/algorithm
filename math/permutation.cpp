#include <iostream>
#include <vector>

using namespace std;

void permutation(vector<vector<int>>& results,
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
        permutation(results, result, nums, visited, target - 1);
        result.pop_back();
        visited[i] = 0;
    }
}

int main() {
    vector<int> nums{1, 2, 3, 4, 5}, result{}, visited(nums.size(), 0);
    vector<vector<int>> results{};
    permutation(results, result, nums, visited, 3);
    for (auto x : results) {
        for (auto xx : x) {
            cout<<xx<<" ";
        }
        cout<<endl;
    }
    cout<<"total size:"<<results.size()<<endl;
    return 0;
}
