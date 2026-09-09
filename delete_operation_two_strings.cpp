#include <iostream>
#include <vector>
#include <string>
#include <algorithm>

using namespace std;

class Solution {
public:
    int minDistance(string word1, string word2) {
        int m = word1.length();
        int n = word2.length();

        vector<vector<int>> dp(m + 1, vector<int>(n + 1, 0));

        for (int i = 1; i <= m; i++) {
            for (int j = 1; j <= n; j++) {
                if (word1[i - 1] == word2[j - 1]) {
                    dp[i][j] = 1 + dp[i - 1][j - 1];
                } else {
                    dp[i][j] = max(dp[i - 1][j], dp[i][j - 1]);
                }
            }
        }

        int lcsLength = dp[m][n];
        return (m - lcsLength) + (n - lcsLength);
    }
};

int main() {
    Solution sol;

    string word1_case1 = "sea";
    string word2_case1 = "eat";
    int ans1 = sol.minDistance(word1_case1, word2_case1);

    string word1_case2 = "leetcode";
    string word2_case2 = "etco";
    int ans2 = sol.minDistance(word1_case2, word2_case2);


    cout << "Test Case 1 (\"sea\", \"eat\") Min Deletions: " << ans1 << endl;
    cout << "Test Case 2 (\"leetcode\", \"etco\") Min Deletions: " << ans2 << endl;

    return 0;
}