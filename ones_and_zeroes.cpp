#include <iostream>
#include <vector>
#include <string>
#include <algorithm>

using namespace std;

class Solution {
public:
    int findMaxForm(vector<string>& strs, int m, int n) {
        vector<vector<int>> dp(m + 1, vector<int>(n + 1, 0));

        for (const string& s : strs) {
            int zeros = 0, ones = 0;
            for (char c : s) {
                if (c == '0') zeros++;
                else ones++;
            }

            for (int i = m; i >= zeros; i--) {
                for (int j = n; j >= ones; j--) {
                    dp[i][j] = max(dp[i][j], 1 + dp[i - zeros][j - ones]);
                }
            }
        }

        return dp[m][n];
    }
};

int main() {
    Solution sol;

    int len, m, n;
    cout << "Array length (L), max zeros (M), max ones (N) daalein: ";
    if (!(cin >> len >> m >> n) || len <= 0 || m < 0 || n < 0) {
        cout << "Galat input!" << endl;
        return 0;
    }

    vector<string> strs(len);
    cout << len << " binary strings daalein (e.g. 10 0001 111001):\n";
    for (int i = 0; i < len; i++) {
        cin >> strs[i];
    }

    cout << "\n=========================================================" << endl;
    cout << "--- LEETCODE 474: ONES AND ZEROES (2D 0/1 KNAPSACK) ---" << endl;
    cout << "=========================================================" << endl;

    int result = sol.findMaxForm(strs, m, n);
    cout << "Maximum Strings Formed: " << result << endl;

    return 0;
}