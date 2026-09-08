#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

class Solution {
public:
    int maxSumAfterPartitioning(vector<int>& arr, int k) {
        int n = arr.size();
        vector<int> dp(n + 1, 0);

        for (int i = 1; i <= n; i++) {
            int currentMax = 0;
            int maxPossibleSum = 0;
            for (int len = 1; len <= k && (i - len) >= 0; len++) {
                currentMax = max(currentMax, arr[i - len]);

                int currentSum = dp[i - len] + currentMax * len;

                maxPossibleSum = max(maxPossibleSum, currentSum);
            }

            dp[i] = maxPossibleSum;
        }

        return dp[n];
    }
};

int main() {
    Solution sol;

    int n, k;
    cout << "Array size (N) aur max partition length (K) daalein: ";
    if (!(cin >> n >> k) || n <= 0 || k <= 0) {
        cout << "Galat input!" << endl;
        return 0;
    }

    vector<int> arr(n);
    cout << n << " array elements daalein:\n";
    for (int i = 0; i < n; i++) {
        cin >> arr[i];
    }

    cout << "\n=========================================================" << endl;
    cout << "--- LEETCODE 1043: PARTITION ARRAY FOR MAXIMUM SUM ---" << endl;
    cout << "=========================================================" << endl;

    int result = sol.maxSumAfterPartitioning(arr, k);
    cout << "Maximum Sum after partitioning: " << result << endl;

    return 0;
}