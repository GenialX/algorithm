/**
 * Suffix Array.
 *
 * @author huxiaoxu <admin@ihuxu.com>
 *
 * see https://www.geeksforgeeks.org/suffix-array-set-2-a-nlognlogn-algorithm
 */

#include <iostream>
#include <cstring>
#include <algorithm>

using namespace std;

// Structure to store information of a suffix
struct suffix {
    int index; // To store original index
    int rank[2]; // To store ranks and next rank pair
};

// A comparison function used by sort() to compare two suffixes
// Compares two pairs, returns 1 if first pair is smaller
int cmp(struct suffix a, struct suffix b) {
    return (a.rank[0] == b.rank[0]) ? (a.rank[1] < b.rank[1] ? 1 : 0) :
        (a.rank[0] < b.rank[0] ? 1 : 0);
}

void countSort(suffix *suffixes, int n, int exp, int ri) {
    cout << "exp:" << exp << " ri:" << ri << endl;
    struct suffix output[n];

    int i, count[10] = {0};
    for (int i = 0; i < n; ++i) ++count[(suffixes[i].rank[ri] / exp) % 10];
    for (int i = 1; i < 10; ++i) count[i] += count[i - 1];
    for (int i = n - 1; i >= 0; --i) {
        cout<<"i:" << i << " index:" << count[(suffixes[i].rank[ri] / exp) % 10] - 1<< endl;
        output[count[(suffixes[i].rank[ri] / exp) % 10] - 1] = suffixes[i];
        --count[ (suffixes[i].rank[ri] / exp) % 10];
    }

    for (int i = 0; i < n; ++i) suffixes[i] = output[i];
}

void sortRadix(suffix *suffixes, int n) {
    for (int ri = 0; ri < 2; ++ri) {
        int m = 0;
        for (int i = 0; i < n; ++i) {
            m = max(suffixes[i].rank[ri], m);
        }
        cout << " max :" << m << endl;
        if (ri == 1) {
            for (int k = 0; k < n; ++k) {
                cout << "suf index:" << suffixes[k].index << " rank0:" << suffixes[k].rank[0] << " rank1:" << suffixes[k].rank[1] << endl;
            }
        }
        for (int exp = 1; m / exp > 0; exp *= 10) {
            countSort(suffixes, n, exp, ri);
        }
    }
}

int *buildSuffixArray(char *txt, int n) {
    struct suffix suffixes[n];

    for (int i = 0; i < n; ++i) {
        suffixes[i].index = i;
        suffixes[i].rank[0] = txt[i] - 'a' + 1;
        suffixes[i].rank[1] = (i + 1 < n) ? (txt[i + 1] - 'a' + 1) : 0;
    }

    //sort(suffixes, suffixes + n, cmp);
    sortRadix(suffixes, n);
    for (int i = 0; i < n; ++i) cout <<" i:"<<i <<" index:"<< suffixes[i].index<<endl;

    int ind[n]; // original index -> suffixes index, as for finding the special suffix emlement by the original index

    for (int k = 4; k < 2 * n; k *= 2) {
        int rank = 0;
        int prev_rank = suffixes[0].rank[0];
        suffixes[0].rank[0] = rank;
        ind[suffixes[0].index] = 0;

        // Assign rank to suffixes
        for (int i = 1; i < n; ++i) {
            if (suffixes[i].rank[0] == prev_rank &&
                    suffixes[i].rank[1] == suffixes[i - 1].rank[1]) {
                prev_rank = suffixes[i].rank[0];
                suffixes[i].rank[0] = suffixes[i - 1].rank[0];
            } else {
                prev_rank = suffixes[i].rank[0];
                suffixes[i].rank[0] = ++rank;
            }
            ind[suffixes[i].index] = i;
        }
        
        // Assign next rank to suffixes
        for (int i = 0; i < n; ++i) {
            int nextindex = suffixes[i].index + k / 2;
            suffixes[i].rank[1] = nextindex < n ? (suffixes[ind[nextindex]].rank[0]) : 0;
        }

        sortRadix(suffixes, n);
    for (int i = 0; i < n; ++i) cout <<" i:"<<i <<" index:"<< suffixes[i].index<<endl;
        //sort(suffixes, suffixes + n, cmp);
    }

    int *suffixArr = new int[n];
    for (int i = 0; i < n; ++i) {
        suffixArr[i] = suffixes[i].index;
    }

    return suffixArr;
}

void printArr(int arr[], int n)
{
    for (int i = 0; i < n; i++)
        cout << arr[i] << " ";
    cout << endl;
}

int main()
{
    char txt[] = "banana";
    int n = strlen(txt);
    int *suffixArr = buildSuffixArray(txt,  n);
    cout << "Following is suffix array for " << txt << endl;
    printArr(suffixArr, n);
    return 0;
}
