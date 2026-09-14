#include <iostream>
#include <vector>
#include <string>

using namespace std;

class Solution {
public:
    // Approach 1: 2D Dynamic Programming - O(N^2) Time & O(N^2) Space
    int countSubstringsDP(string s) {
        int n = s.length();
        vector<vector<bool>> dp(n, vector<bool>(n, false));
        int totalCount = 0;

        // Base Case 1: Single character substrings (length = 1)
        for (int i = 0; i < n; i++) {
            dp[i][i] = true;
            totalCount++;
        }

        // Base Case 2: Length = 2 substrings
        for (int i = 0; i < n - 1; i++) {
            if (s[i] == s[i + 1]) {
                dp[i][i + 1] = true;
                totalCount++;
            }
        }

        // General Case: Substrings of length 3 to n
        for (int len = 3; len <= n; len++) {
            for (int i = 0; i <= n - len; i++) {
                int j = i + len - 1; // End index

                if (s[i] == s[j] && dp[i + 1][j - 1]) {
                    dp[i][j] = true;
                    totalCount++;
                }
            }
        }

        return totalCount;
    }

    // Approach 2: Expand Around Center - O(N^2) Time & O(1) Space Optimization
    int countSubstringsSpaceOptimized(string s) {
        int n = s.length();
        int totalCount = 0;

        auto expand = [&](int left, int right) {
            int count = 0;
            while (left >= 0 && right < n && s[left] == s[right]) {
                count++;
                left--;
                right++;
            }
            return count;
        };

        for (int i = 0; i < n; i++) {
            // Odd length palindromes (Center at index i)
            totalCount += expand(i, i);

            // Even length palindromes (Center between index i and i+1)
            totalCount += expand(i, i + 1);
        }

        return totalCount;
    }
};

int main() {
    Solution sol;

    string s1 = "abc";
    string s2 = "aaa";
    string s3 = "leetcode";

  

    cout << "Test Case 1 (\"abc\"): " << endl;
    cout << "  DP Approach Result     : " << sol.countSubstringsDP(s1) << endl;
    cout << "  Optimized O(1) Space   : " << sol.countSubstringsSpaceOptimized(s1) << endl;

    cout << "\nTest Case 2 (\"aaa\"): " << endl;
    cout << "  DP Approach Result     : " << sol.countSubstringsDP(s2) << endl;
    cout << "  Optimized O(1) Space   : " << sol.countSubstringsSpaceOptimized(s2) << endl;

    cout << "\nTest Case 3 (\"leetcode\"): " << endl;
    cout << "  DP Approach Result     : " << sol.countSubstringsDP(s3) << endl;
    cout << "  Optimized O(1) Space   : " << sol.countSubstringsSpaceOptimized(s3) << endl;

    return 0;
}