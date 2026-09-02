#include <iostream>
#include <vector>
#include <string>

using namespace std;

class Solution {
public:
    int numDecodings(string s) {
        int n = s.length();
        if (n == 0 || s[0] == '0') return 0;

        vector<int> dp(n + 1, 0);

        dp[0] = 1;
        dp[1] = 1;

        for (int i = 2; i <= n; i++) {
            int singleDigit = s[i - 1] - '0';
            int doubleDigit = (s[i - 2] - '0') * 10 + singleDigit;

            if (singleDigit >= 1 && singleDigit <= 9) {
                dp[i] += dp[i - 1]; 
            }

            if (doubleDigit >= 10 && doubleDigit <= 26) {
                dp[i] += dp[i - 2]; 
            }
        }

        return dp[n];
    }
};

int main() {
    Solution sol;

    string s1 = "12";
    int res1 = sol.numDecodings(s1);

    string s2 = "226";
    int res2 = sol.numDecodings(s2);

    string s3 = "06";
    int res3 = sol.numDecodings(s3);

    cout << "=========================================================" << endl;
    cout << "--- LEETCODE 91: DECODE WAYS (EXPLICIT TRANSITIONS) ---" << endl;
    cout << "=========================================================" << endl;

    cout << "Test Case 1 (\"12\"):  " << res1 << endl;
    cout << "Test Case 2 (\"226\"): " << res2 << endl;
    cout << "Test Case 3 (\"06\"):  " << res3 << endl;

    return 0;
}