// C++ program for building suffix array of a given text
#include <iostream>
#include <cstring>
#include <algorithm>

using namespace std;

const int N = 1e5 + 5;
int c[N] = {0};
 
// Structure to store information of a suffix
struct suffix {
    int index; // To store original index
    int rank[2]; // To store ranks and next rank pair
};
 
void radixSort(suffix suffixes[], int ri, int m, int n) {
    fill(c, c + m + 1, 0);
    struct suffix output[n];
    for (int i = 0; i < n; ++i) c[suffixes[i].rank[ri]]++;
    for (int i = 1; i < m + 1; ++i) c[i] += c[i - 1];
    for (int i = n - 1; i >= 0; i--) {
        int index = --c[suffixes[i].rank[ri]];
        output[index] = suffixes[i];
    }
    memcpy(suffixes, output, sizeof(output));
}
 
// This is the main function that takes a string 'txt' of size n as an
// argument, builds and return the suffix array for the given string
int *buildSuffixArray(char *txt, int n) {
    // A structure to store suffixes and their indexes
    struct suffix suffixes[n];
 
    // Store suffixes and their indexes in an array of structures.
    // The structure is needed to sort the suffixes alphabatically
    // and maintain their old indexes while sorting
    for (int i = 0; i < n; i++) {
        suffixes[i].index = i;
        suffixes[i].rank[0] = txt[i] - 'a' + 1;
        suffixes[i].rank[1] = ((i+1) < n)? (txt[i + 1] - 'a' + 1): 0;
    }
 
    // Sort the suffixes using redixSort
    radixSort(suffixes, 1, 26, n);
    radixSort(suffixes, 0, 26, n);

    // At this point, all suffixes are sorted according to first
    // 2 characters.  Let us sort suffixes according to first 4
    // characters, then first 8 and so on
    int ind[n];  // This array is needed to get the index in suffixes[]
                 // from original index.  This mapping is needed to get
                 // next suffix.
    for (int k = 4; k < 2*n; k = k*2) {
        // Assigning rank and index values to first suffix
        int rank = 0;
        int prev_rank = suffixes[0].rank[0];
        suffixes[0].rank[0] = rank;
        ind[suffixes[0].index] = 0;
 
        // Assigning rank to suffixes
        for (int i = 1; i < n; i++) {
            // If first rank and next ranks are same as that of previous
            // suffix in array, assign the same new rank to this suffix
            if (suffixes[i].rank[0] == prev_rank &&
                    suffixes[i].rank[1] == suffixes[i-1].rank[1]) {
                prev_rank = suffixes[i].rank[0];
                suffixes[i].rank[0] = rank;
            } else {
                prev_rank = suffixes[i].rank[0];
                suffixes[i].rank[0] = ++rank;
            }
            ind[suffixes[i].index] = i;
        }
 
        // Assign next rank to every suffix
        for (int i = 0; i < n; i++) {
            int nextindex = suffixes[i].index + k/2;
            suffixes[i].rank[1] = (nextindex < n)?
                                  suffixes[ind[nextindex]].rank[0]: 0;
        }
 
        // Sort the suffixes according to first k characters
        radixSort(suffixes, 1, rank + 5, n);
        radixSort(suffixes, 0, rank + 5, n);
    }
 
    // Store indexes of all sorted suffixes in the suffix array
    int *suffixArr = new int[n];
    for (int i = 0; i < n; i++)
        suffixArr[i] = suffixes[i].index;
 
    // Return the suffix array
    return  suffixArr;
}
 
// A utility function to print an array of given size
void printArr(int arr[], int n) {
    for (int i = 0; i < n; i++)
        cout << arr[i] << " ";
    cout << endl;
}
 
// Driver program to test above functions
int main() {
    char txt[] = "banana";
    int n = strlen(txt);
    int *suffixArr = buildSuffixArray(txt,  n);
    cout << "Following is suffix array for " << txt << endl;
    printArr(suffixArr, n);
    return 0;
}
