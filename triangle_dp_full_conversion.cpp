#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

class Solution {
public:
    int minimumTotal(vector<vector<int>>& triangle) {
        int n = triangle.size();

        vector<int> dp = triangle[n - 1];

        for (int i = n - 2; i >= 0; i--) {
            for (int j = 0; j <= i; j++) {
                dp[j] = triangle[i][j] + min(dp[j], dp[j + 1]);
            }
        }
        return dp[0];
    }
};

int main() {
    Solution sol;

    int n;
    cout << "Enter number of rows in Triangle: ";
    if (!(cin >> n)) return 0;

    vector<vector<int>> triangle(n);
    cout << "Enter elements row by row:\n";
    for (int i = 0; i < n; i++) {
        triangle[i].resize(i + 1);
        for (int j = 0; j <= i; j++) {
            cin >> triangle[i][j];
        }
    }

    cout << "=========================================================" << endl;
    cout << "--- LEETCODE 120: TRIANGLE (STEP-BY-STEP DP CONVERSION) ---" << endl;
    cout << "=========================================================" << endl;

    int result = sol.minimumTotal(triangle);
    cout << "Minimum Path Sum: " << result << endl;

    return 0;
}