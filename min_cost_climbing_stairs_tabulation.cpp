#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

class Solution {
public:
    int minCostClimbingStairs(vector<int>& cost) {
        int n = cost.size();
        vector<int> dp(n + 1, 0);

        dp[0] = 0;
        dp[1] = 0;

        for (int i = 2; i <= n; i++) {
            dp[i] = min(dp[i - 1] + cost[i - 1], dp[i - 2] + cost[i - 2]);
        }

        return dp[n];
    }
};

int main() {
    Solution sol;

    vector<int> cost1 = {10, 15, 20};
    int res1 = sol.minCostClimbingStairs(cost1);

    vector<int> cost2 = {1, 100, 1, 1, 1, 100, 1, 1, 100, 1};
    int res2 = sol.minCostClimbingStairs(cost2);

    cout << "=========================================================" << endl;
    cout << "--- LEETCODE 746: TABULATION DP APPROACH ---" << endl;
    cout << "=========================================================" << endl;

    cout << "Test Case 1: [10, 15, 20] -> Min Cost: " << res1 << endl;
    cout << "Test Case 2: [1, 100, 1, ...] -> Min Cost: " << res2 << endl;

    return 0;
}