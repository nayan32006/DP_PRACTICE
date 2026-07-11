#include <iostream>
#include <vector>
#include <numeric>
#include <cmath>

using namespace std;

class Solution {
public:
    int findTargetSumWays(vector<int>& nums, int target) {
        int totalSum = 0;
        for (int num : nums) {
            totalSum += num;
        }
        
        if (abs(target) > totalSum || (target + totalSum) % 2 != 0) {
            return 0;
        }
        
        int subsetSum = (target + totalSum) / 2;
        vector<int> dp(subsetSum + 1, 0);
        dp[0] = 1;
        
        for (int num : nums) {
            for (int j = subsetSum; j >= num; j--) {
                dp[j] = dp[j] + dp[j - num];
            }
        }
        
        return dp[subsetSum];
    }
};

int main() {
    Solution solver;
    vector<int> nums = {1, 1, 1, 1, 1};
    int target = 3;
    
    cout << solver.findTargetSumWays(nums, target) << endl;
    return 0;
}