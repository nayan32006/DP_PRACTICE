#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

class Solution {
public:
    int longestArithSeqLength(vector<int>& nums) {
        int n = nums.size();
        if (n <= 2) return n;

        vector<vector<int>> dp(n, vector<int>(1001, 1));

        int maxLength = 2; 

        for (int i = 0; i < n; i++) {
            for (int j = 0; j < i; j++) {
                int diff = nums[i] - nums[j] + 500; 

                dp[i][diff] = max(dp[i][diff], dp[j][diff] + 1);

                maxLength = max(maxLength, dp[i][diff]);
            }
        }

        return maxLength;
    }
};

int main() {
    Solution sol;

    vector<int> nums1 = {3, 6, 9, 12};
    int ans1 = sol.longestArithSeqLength(nums1);

    vector<int> nums2 = {9, 4, 7, 2, 10};
    int ans2 = sol.longestArithSeqLength(nums2);

    vector<int> nums3 = {20, 1, 15, 3, 10, 5, 8};
    int ans3 = sol.longestArithSeqLength(nums3);


    cout << "Test Case 1 [3, 6, 9, 12] Max Length: " << ans1 << endl;
    cout << "Test Case 2 [9, 4, 7, 2, 10] Max Length: " << ans2 << endl;
    cout << "Test Case 3 [20, 1, 15, 3, 10, 5, 8] Max Length: " << ans3 << endl;

    return 0;
}