#include <iostream>
#include <vector>
#include <string>

using namespace std;

class Solution {
public:
    int countPalindromicSubsequences(string s) {
        int n = s.length();
        const int MOD = 1e9 + 7;

        vector<vector<long long>> dp(n, vector<long long>(n, 0));

        for (int i = 0; i < n; i++) {
            dp[i][i] = 1;
        }

        for (int len = 2; len <= n; len++) {
            for (int i = 0; i <= n - len; i++) {
                int j = i + len - 1;

                if (s[i] == s[j]) {
                    dp[i][j] = (dp[i + 1][j] + dp[i][j - 1] + 1) % MOD;
                } else {
                    dp[i][j] = (dp[i + 1][j] + dp[i][j - 1] - dp[i + 1][j - 1] + MOD) % MOD;
                }
            }
        }

        return dp[0][n - 1];
    }
};

int main() {
    Solution sol;

    string s1 = "abcd";
    string s2 = "aab";
    string s3 = "bbcb";


    cout << "Test Case 1 (\"abcd\"): " << sol.countPalindromicSubsequences(s1) << endl;
    cout << "Test Case 2 (\"aab\"): " << sol.countPalindromicSubsequences(s2) << endl;
    cout << "Test Case 3 (\"bbcb\"): " << sol.countPalindromicSubsequences(s3) << endl;

    return 0;
}