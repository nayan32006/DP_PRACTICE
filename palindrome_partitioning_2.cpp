#include <iostream>
#include <vector>
#include <string>
#include <algorithm>

using namespace std;

class Solution {
public:
    int minCut(string s) {
        int n = s.length();
        if (n <= 1) return 0;
        vector<vector<bool>> isPal(n, vector<bool>(n, false));

        for (int i = 0; i < n; i++) {
            for (int j = 0; j <= i; j++) {
                if (s[i] == s[j] && (i - j <= 2 || isPal[j + 1][i - 1])) {
                    isPal[j][i] = true;
                }
            }
        }

        vector<int> dp(n, 0);

        for (int i = 0; i < n; i++) {
            if (isPal[0][i]) {
                dp[i] = 0; 
            } else {
                int minCuts = i; 
                for (int j = 1; j <= i; j++) {
                    if (isPal[j][i]) {
                        minCuts = min(minCuts, dp[j - 1] + 1);
                    }
                }
                dp[i] = minCuts;
            }
        }

        return dp[n - 1];
    }
};

int main() {
    Solution sol;
    string s1 = "aab";
    string s2 = "a";
    string s3 = "ab";

    cout << "Test Case 1 (\"aab\"): " << sol.minCut(s1) << " cut(s)" << endl;
    cout << "Test Case 2 (\"a\"): " << sol.minCut(s2) << " cut(s)" << endl;
    cout << "Test Case 3 (\"ab\"): " << sol.minCut(s3) << " cut(s)" << endl;

    return 0;
}