// // #include <iostream>
// // #include <vector>
// // #include <string>
// // #include <algorithm>

// // using namespace std;

// // class Solution {
// // public:
// //     int longestPalindromeSubseq(string s) {
// //         int n = s.size();
// //         if (n == 0) return 0;

// //         vector<vector<int>> dp(n, vector<int>(n, 0));

// //         for (int i = 0; i < n; i++) {
// //             dp[i][i] = 1;
// //         }

// //         for (int length = 2; length <= n; length++) {
// //             for (int i = 0; i <= n - length; i++) {
// //                 int j = i + length - 1;

// //                 if (s[i] == s[j]) {
// //                     dp[i][j] = 2 + dp[i + 1][j - 1];
// //                 } else {
// //                     dp[i][j] = max(dp[i + 1][j], dp[i][j - 1]);
// //                 }
// //             }
// //         }

// //         return dp[0][n - 1];
// //     }
// // };

// // int main() {
// //     Solution solver;
// //     string s = "bbbab";
// //     cout << solver.longestPalindromeSubseq(s) << endl;
// //     return 0;
// // }

// [Running] cd "c:\Users\girin\OneDrive\Desktop\DP\" && g++ LongestPalindromeSubseq.cpp -o LongestPalindromeSubseq && LongestPalindromeSubseq
// 4

#include <iostream>
#include <vector>
#include <string>
#include <algorithm>

using namespace std;

class Solution {
public:
    int longestPalindromeSubseq(string s) {
        int n = s.size();
        if (n == 0) return 0;

        vector<vector<int>> dp(n, vector<int>(n, 0));

        for (int i = 0; i < n; i++) {
            dp[i][i] = 1;
        }

        for (int length = 2; length <= n; length++) {
            for (int i = 0; i <= n - length; i++) {
                int j = i + length - 1;

                if (s[i] == s[j]) {
                    dp[i][j] = 2 + dp[i + 1][j - 1];
                } else {
                    dp[i][j] = max(dp[i + 1][j], dp[i][j - 1]);
                }
            }
        }

        return dp[0][n - 1];
    }
};

int main() {
    Solution solver;
    string s = "bbbab";
    cout << solver.longestPalindromeSubseq(s) << endl;
    return 0;
}

// [Running] cd "c:\Users\girin\OneDrive\Desktop\DP\" && g++ LongestPalindromeSubseq.cpp -o LongestPalindromeSubseq && LongestPalindromeSubseq
// 4
