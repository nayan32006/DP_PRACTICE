#include <iostream>
#include <vector>
#include <string>

using namespace std;

class Solution {
public:
    int numDistinct(string s, string t) {
        int m = s.length();
        int n = t.length();

        vector<vector<double>> dp(m + 1, vector<double>(n + 1, 0));

        for (int i = 0; i <= m; i++) {
            dp[i][0] = 1;
        }

        for (int i = 1; i <= m; i++) {
            for (int j = 1; j <= n; j++) {
                if (s[i - 1] == t[j - 1]) {
                    dp[i][j] = dp[i - 1][j - 1] + dp[i - 1][j];
                } else {
                    dp[i][j] = dp[i - 1][j];
                }
            }
        }

        return (int)dp[m][n];
    }
};

int main() {
    Solution sol;

    string s1 = "rabbbit", t1 = "rabbit";
    int ans1 = sol.numDistinct(s1, t1);

    string s2 = "babgbag", t2 = "bag";
    int ans2 = sol.numDistinct(s2, t2);


    cout << "Test Case 1 (\"rabbbit\", \"rabbit\") Distinct Subsequences: " << ans1 << endl;
    cout << "Test Case 2 (\"babgbag\", \"bag\") Distinct Subsequences: " << ans2 << endl;

    return 0;
}