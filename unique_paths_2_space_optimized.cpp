#include <iostream>
#include <vector>

using namespace std;

class Solution {
public:
    int uniquePathsWithObstacles(vector<vector<int>>& obstacleGrid) {
        int m = obstacleGrid.size();
        int n = obstacleGrid[0].size();

        if (obstacleGrid[0][0] == 1 || obstacleGrid[m - 1][n - 1] == 1) {
            return 0;
        }

        vector<long long> dp(n, 0);
        dp[0] = 1; 

        for (int i = 0; i < m; i++) {
            for (int j = 0; j < n; j++) {

                if (obstacleGrid[i][j] == 1) {
                    dp[j] = 0;
                } else if (j > 0) {
                    
                    dp[j] += dp[j - 1];
                }
            }
        }

        return dp[n - 1];
    }
};

int main() {
    Solution sol;

    int m, n;
    cout << "Enter grid dimensions (m n): ";
    if (!(cin >> m >> n)) return 0;

    vector<vector<int>> grid(m, vector<int>(n));
    cout << "Enter grid elements (0 for free, 1 for obstacle):\n";
    for (int i = 0; i < m; i++) {
        for (int j = 0; j < n; j++) {
            cin >> grid[i][j];
        }
    }

    cout << "=========================================================" << endl;
    cout << "--- LEETCODE 63: UNIQUE PATHS II (O(N) SPACE) ---" << endl;
    cout << "=========================================================" << endl;

    int result = sol.uniquePathsWithObstacles(grid);
    cout << "Total Unique Paths: " << result << endl;

    return 0;
}