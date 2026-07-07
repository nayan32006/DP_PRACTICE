#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

class Solution {
public:
    int maxSubArray(vector<int>& nums) {
        int maxi = nums[0];
        int sum = 0;
        
        for (int i = 0; i < nums.size(); i++) {
            sum += nums[i];
            maxi = max(maxi, sum);
            
            if (sum < 0) {
                sum = 0;
            }
        }
        
        return maxi;
    }
};

int main() {
    Solution solver;
    
    vector<int> test1 = {-2, 1, -3, 4, -1, 2, 1, -5, 4};
    vector<int> test2 = {5, 4, -1, 7, 8};
    
    cout << "Max Subarray Sum (Test 1): " << solver.maxSubArray(test1) << endl;
    cout << "Max Subarray Sum (Test 2): " << solver.maxSubArray(test2) << endl;
    
    return 0;
}