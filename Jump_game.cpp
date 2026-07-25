#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

class Solution {
public:
    bool canJump(vector<int>& nums) {
        int maxReachable = 0;
        int n = nums.size();

        for (int i = 0; i < n; i++) {
            if (i > maxReachable) {
                return false;
            }

            maxReachable = max(maxReachable, i + nums[i]);

            if (maxReachable >= n - 1) {
                return true;
            }
        }

        return true;
    }
};

int main() {
    vector<int> nums1 = {2, 3, 1, 1, 4};
    vector<int> nums2 = {3, 2, 1, 0, 4};

    Solution sol;
    cout << (sol.canJump(nums1) ? "true" : "false") << endl;
    cout << (sol.canJump(nums2) ? "true" : "false") << endl;

    return 0;
}