#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

class Solution {
public:
    int rob(vector<int>& nums) {
        int n = nums.size();
        
        if (n == 0) return 0;
        
        vector<int> dp(n, -1);
        dp[0] = nums[0];
        
        for(int i = 1; i < n; i++) {
            int notpick = dp[i - 1];
            
            int pick = nums[i];
            if(i > 1)
                pick = nums[i] + dp[i - 2];
            
            dp[i] = max(pick, notpick);
        }
        
        return dp[n - 1];
    }
};

int main() {
    Solution solver;
    vector<int> houses = {2, 7, 9, 3, 1};
    int result = solver.rob(houses);
    cout << result << endl;
    return 0;
}