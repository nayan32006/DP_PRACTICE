#include <iostream>
#include <vector>
#include <string>

using namespace std;

class Solution {
public:
    int distinctSubseqII(string s) {
        int n = s.length();
        int MOD = 1e9 + 7;

        vector<long long> dp(n + 1, 0);
        dp[0] = 1; 
        vector<int> last(26, -1);

        for (int i = 1; i <= n; i++) {
            char ch = s[i - 1];
            int charIdx = ch - 'a';

            dp[i] = (2 * dp[i - 1]) % MOD;

            if (last[charIdx] != -1) {
                dp[i] = (dp[i] - dp[last[charIdx] - 1] + MOD) % MOD;
            }

            last[charIdx] = i;
        }

        return (dp[n] - 1 + MOD) % MOD;
    }
};

int main() {
    Solution sol;

    string s1 = "abc";
    string s2 = "aba";
    string s3 = "aaa";

    cout << "Test Case 1 (\"abc\"): " << sol.distinctSubseqII(s1) << endl;
    cout << "Test Case 2 (\"aba\"): " << sol.distinctSubseqII(s2) << endl;
    cout << "Test Case 3 (\"aaa\"): " << sol.distinctSubseqII(s3) << endl;

    return 0;
}