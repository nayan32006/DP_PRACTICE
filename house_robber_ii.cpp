#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

class Solution {
private:
    // Standard House Robber I (Linear DP with O(1) Space Optimization)
    int robLinear(const vector<int>& nums, int start, int end) {
        int prev2 = 0; // dp[i-2]
        int prev1 = 0; // dp[i-1]

        for (int i = start; i <= end; i++) {
            // Choice: rob current house + prev2 OR skip current house and take prev1
            int curr = max(nums[i] + prev2, prev1);
            prev2 = prev1;
            prev1 = curr;
        }

        return prev1;
    }

public:
    int rob(vector<int>& nums) {
        int n = nums.size();

        // Edge Cases
        if (n == 0) return 0;
        if (n == 1) return nums[0];

        // CIRCULAR DP CHOICE JUSTIFICATION:
        // Case 1: Rob from index 0 to n - 2 (Exclude last house)
        // Case 2: Rob from index 1 to n - 1 (Exclude first house)
        int case1 = robLinear(nums, 0, n - 2);
        int case2 = robLinear(nums, 1, n - 1);

        return max(case1, case2);
    }
};

int main() {
    Solution sol;

    // Test Case 1: [2, 3, 2] -> Max profit = 3 (Rob house 1)
    vector<int> nums1 = {2, 3, 2};
    int res1 = sol.rob(nums1);

    // Test Case 2: [1, 2, 3, 1] -> Max profit = 4 (Rob house 0 and 2)
    vector<int> nums2 = {1, 2, 3, 1};
    int res2 = sol.rob(nums2);

    // Test Case 3: [1, 2, 3] -> Max profit = 3
    vector<int> nums3 = {1, 2, 3};
    int res3 = sol.rob(nums3);

    cout << "=========================================================" << endl;
    cout << "--- LEETCODE 213: HOUSE ROBBER II (CIRCULAR DP) ---" << endl;
    cout << "=========================================================" << endl;

    cout << "Test Case 1: [2, 3, 2]    -> Max Money: " << res1 << endl;
    cout << "Test Case 2: [1, 2, 3, 1] -> Max Money: " << res2 << endl;
    cout << "Test Case 3: [1, 2, 3]    -> Max Money: " << res3 << endl;

    return 0;
}