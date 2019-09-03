#include <bits/stdc++.h>

using namespace std;

/**
 * Time Complexity: O(2^n), n is the length of str.
 * Thanks to https://leetcode.com/problems/number-of-valid-words-for-each-puzzle/discuss/371864/Python-Find-all-Sub-Puzzles.
 */
void bfs_only_once() {
    string str = "abc";
    vector<string> subs{""};
    for (auto& c : str) {
        vector<string> cur_subs;
        for (auto& sub : subs) {
            cur_subs.push_back(sub + c);
        }
        subs.insert(subs.end(), cur_subs.begin(), cur_subs.end());
    }
    for (auto& str : subs) cout << str << endl;
}

/**
 * Time Complexity: O(2^n), n is the length of str.
 */
void dfs_only_once(vector<string>& results, string result, string& str, int start) {
    if (start == str.length()) {
        results.push_back(result);
        return;
    }
    // use it
    result.push_back(str[start]);
    dfs_only_once(results, result, str, start + 1);
    result.pop_back();
    // not use it
    dfs_only_once(results, result, str, start + 1);
}

int main() {
    // bfs only once
    bfs();

    // dfs only once
    vector<string> results{};
    string result = "", str = "abc";
    dfs_only_once(results, result, str, 0);
    for (auto& str : results) cout << str << endl;

    return 0;
}
