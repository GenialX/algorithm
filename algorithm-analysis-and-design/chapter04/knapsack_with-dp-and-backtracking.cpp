/**
 * 0-1backpack problem with dp & backtracking
 */
#include <iostream>
#include <ctime>

using namespace std;

#define NUM 4 // maximum number of items
#define CAP 5 // maximum capacity of backpack
int w[] = {2, 1, 3, 2}; // the weight of item
int v[] = {12, 10, 20, 15}; // the value of item
int dp[NUM][CAP]; // array for recursion

int knapsack(int num, int cap)
{
    // dp[i][j] = max(dp[i - 1][j], dp[i - 1][j - w[i]] + v[i])
    if (num == 0) {
        if (cap >= w[0]) return v[0];
        else return 0;
    } else {
        if (cap - w[num] >= 0) return max(knapsack(num - 1, cap), knapsack(num - 1, cap - w[num]) + v[num]);
        else return knapsack(num - 1, cap);
    }
}

int main(void)
{
    cout<<"answer:"<<knapsack(NUM - 1, CAP)<<endl;;
    return 0;
}
