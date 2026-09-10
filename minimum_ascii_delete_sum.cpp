#include <iostream>
#include <vector>
#include <string>
#include <algorithm>

using namespace std;

class Solution {
public:
    int minimumDeleteSum(string s1, string s2) {
        int m = s1.length();
        int n = s2.length();

        vector<vector<int>> dp(m + 1, vector<int>(n + 1, 0));

        for (int j = 1; j <= n; j++) {
            dp[0][j] = dp[0][j - 1] + s2[j - 1];
        }

        for (int i = 1; i <= m; i++) {
            dp[i][0] = dp[i - 1][0] + s1[i - 1];
        }

        for (int i = 1; i <= m; i++) {
            for (int j = 1; j <= n; j++) {
                if (s1[i - 1] == s2[j - 1]) {
                    dp[i][j] = dp[i - 1][j - 1];
                } else {
                    dp[i][j] = min(
                        dp[i - 1][j] + s1[i - 1], 
                        dp[i][j - 1] + s2[j - 1]  
                    );
                }
            }
        }

        return dp[m][n];
    }
};

int main() {
    Solution sol;

    string s1_case1 = "sea", s2_case1 = "eat";
    int ans1 = sol.minimumDeleteSum(s1_case1, s2_case1);

    string s1_case2 = "delete", s2_case2 = "leet";
    int ans2 = sol.minimumDeleteSum(s1_case2, s2_case2);


    cout << "Test Case 1 (\"sea\", \"eat\") Min ASCII Delete Sum: " << ans1 << endl;
    cout << "Test Case 2 (\"delete\", \"leet\") Min ASCII Delete Sum: " << ans2 << endl;

    return 0;
}