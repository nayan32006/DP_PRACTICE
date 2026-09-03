#include <iostream>
#include <vector>
#include <algorithm>
#include <climits>

using namespace std;

class Solution {
public:
    int minFallingPathSum(vector<vector<int>>& matrix) {
        int n = matrix.size();

        vector<int> prev = matrix[0];

        for (int i = 1; i < n; i++) {
            vector<int> curr(n, 0);
            for (int j = 0; j < n; j++) {
                int up = prev[j];
                int leftDiag = (j > 0) ? prev[j - 1] : INT_MAX;
                int rightDiag = (j < n - 1) ? prev[j + 1] : INT_MAX;

                curr[j] = matrix[i][j] + min({up, leftDiag, rightDiag});
            }
            prev = curr;
        }

        return *min_element(prev.begin(), prev.end());
    }
};

int main() {
    Solution sol;

    vector<vector<int>> matrix1 = {
        {2, 1, 3},
        {6, 5, 4},
        {7, 8, 9}
    };
    int res1 = sol.minFallingPathSum(matrix1);

    vector<vector<int>> matrix2 = {
        {-19, 57},
        {-40, -5}
    };
    int res2 = sol.minFallingPathSum(matrix2);

    cout << "=========================================================" << endl;
    cout << "--- LEETCODE 931: MIN FALLING PATH SUM (O(N) SPACE) ---" << endl;
    cout << "=========================================================" << endl;

    cout << "Test Case 1: " << res1 << endl;
    cout << "Test Case 2: " << res2 << endl;

    return 0;
}