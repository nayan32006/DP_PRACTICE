#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

class Solution {
public:
    int maxCoins(vector<int>& nums) {
        int n = nums.size();
        vector<int> arr(n + 2, 1);
        for (int i = 0; i < n; i++) {
            arr[i + 1] = nums[i];
        }
        vector<vector<int>> dp(n + 2, vector<int>(n + 2, 0));

        for (int len = 1; len <= n; len++) {
            for (int l = 1; l <= n - len + 1; l++) {
                int r = l + len - 1;

                // Step 3: Pick balloon k as the LAST balloon to burst in range [l...r]
                for (int k = l; k <= r; k++) {
                    int coins = arr[l - 1] * arr[k] * arr[r + 1];
                    int total = dp[l][k - 1] + dp[k + 1][r] + coins;
                    
                    dp[l][r] = max(dp[l][r], total);
                }
            }
        }

        return dp[1][n];
    }
};

int main() {
    Solution sol;

    vector<int> nums1 = {3, 1, 5, 8};
    vector<int> nums2 = {1, 5};

    cout << "Test Case 1 ({3, 1, 5, 8}): " << sol.maxCoins(nums1) << " coins" << endl;
    cout << "Test Case 2 ({1, 5}):       " << sol.maxCoins(nums2) << " coins" << endl;

    return 0;
}