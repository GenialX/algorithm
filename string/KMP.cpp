/**
 * Reference from https://github.com/torvalds/linux/blob/master/lib/ts_kmp.c
 * 
 * @author huxiaoxu <admin@ihuxu.com>
 */
#include <string>
#include <vector>
#include <iostream>

const int IGNORECASE = 1 << 1;

using namespace std;

void compute_prefix_tbl(string pattern, vector<int>& prefix_tbl, int flags) {
    unsigned k, q, len = pattern.length();
    const int icase = flags & IGNORECASE;
    for (k = 0, q = 1; q < len; ++q) {
        if (k > 0 && (icase ? toupper(pattern[k]) : pattern[k]) != (icase ? toupper(pattern[q]) : pattern[q]))
            k = prefix_tbl[k - 1];
        if ((icase ? toupper(pattern[k]) : pattern[k]) == (icase ? toupper(pattern[q]) : pattern[q]))
            ++k;
        prefix_tbl[q] = k;
    }
}

unsigned int kmp_find(string text, string pattern, int flags = 0) {
    unsigned int text_len = text.length(), pattern_len = pattern.length();
    if (text_len == 0 || pattern_len == 0 || pattern_len > text_len) return UINT_MAX;
    unsigned int i = 0, q = 0;
    const int icase = flags & IGNORECASE;
    vector<int> prefix_tbl(pattern_len, 0);
    compute_prefix_tbl(pattern, prefix_tbl, flags);
    for (i = 0, q = 0; i < text_len; ++i) {
        while (q > 0 && (icase ? toupper(text[i]) : text[i]) != (icase ? toupper(pattern[q]) : pattern[q]))
            q = prefix_tbl[q - 1];
        if ((icase ? toupper(text[i]) : text[i]) == (icase ? toupper(pattern[q]) : pattern[q])) {
            ++q;
        }
        if (q == pattern_len) {
            return i - pattern_len + 1;
        }
    }
    return UINT_MAX;
}

int main() {
    string text = "abcabcd", pattern = "aBcd";
    cout << kmp_find(text, pattern, IGNORECASE) << endl;
    cout << kmp_find("", pattern, IGNORECASE) << endl;
    cout << kmp_find(text, "", IGNORECASE) << endl;
    cout << kmp_find(text, "b", IGNORECASE) << endl;
    cout << kmp_find("a", pattern, IGNORECASE) << endl;
    return 0;
}