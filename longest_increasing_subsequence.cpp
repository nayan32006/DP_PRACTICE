#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

class Solution {
public:
    // O(N log N) Binary Search (Patience Sorting) Approach
    int lengthOfLIS(vector<int>& nums) {
        vector<int> tails;

        for (int x : nums) {
            auto it = lower_bound(tails.begin(), tails.end(), x);
            if (it == tails.end()) {
                tails.push_back(x);
            } else {
                *it = x;
            }
        }
        return tails.size();
    }
};

int main() {
    Solution sol;

    int n;
    cout << "Enter array size: ";
    if (!(cin >> n) || n <= 0) {
        cout << "Invalid input!" << endl;
        return 0;
    }

    vector<int> nums(n);
    cout << "Enter " << n << " array elements (space separated):\n";
    for (int i = 0; i < n; i++) {
        cin >> nums[i];
    }

    cout << "\n=========================================================" << endl;
    cout << "--- LEETCODE 300: LONGEST INCREASING SUBSEQUENCE ---" << endl;
    cout << "=========================================================" << endl;

    int result = sol.lengthOfLIS(nums);
    cout << "Length of Longest Increasing Subsequence: " << result << endl;

    return 0;
}