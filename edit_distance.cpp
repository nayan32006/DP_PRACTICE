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

        for (int i = 0; i <= m; i++) dp[i][0] = i; 
        for (int j = 0; j <= n; j++) dp[0][j] = j;

        for (int i = 1; i <= m; i++) {
            for (int j = 1; j <= n; j++) {
                if (word1[i - 1] == word2[j - 1]) {
                    dp[i][j] = dp[i - 1][j - 1]; 
                } else {
                    int insertOp = dp[i][j - 1];
                    int deleteOp = dp[i - 1][j];
                    int replaceOp = dp[i - 1][j - 1];

                    dp[i][j] = 1 + min({insertOp, deleteOp, replaceOp});
                }
            }
        }

        return dp[m][n];
    }
};

int main() {
    Solution sol;

    string word1_1 = "horse", word2_1 = "ros";
    int res1 = sol.minDistance(word1_1, word2_1);

    string word1_2 = "intention", word2_2 = "execution";
    int res2 = sol.minDistance(word1_2, word2_2);

    cout << "=========================================================" << endl;
    cout << "--- LEETCODE 72: EDIT DISTANCE (2D DP TABULATION) ---" << endl;
    cout << "=========================================================" << endl;

    cout << "Test Case 1 (\"horse\" -> \"ros\"): " << res1 << " operations" << endl;
    cout << "Test Case 2 (\"intention\" -> \"execution\"): " << res2 << " operations" << endl;

    return 0;
}