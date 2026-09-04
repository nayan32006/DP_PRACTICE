#include <iostream>
#include <vector>
#include <algorithm>
#include <climits>

using namespace std;

class Solution {
public:
    int minPathCost(vector<vector<int>>& grid, vector<vector<int>>& moveCost) {
        int m = grid.size();
        int n = grid[0].size();

        vector<int> prev(n);
        for (int j = 0; j < n; j++) {
            prev[j] = grid[0][j];
        }

        for (int i = 1; i < m; i++) {
            vector<int> curr(n, INT_MAX);

            for (int j = 0; j < n; j++) { // Current row's column
                for (int k = 0; k < n; k++) { // Previous row's column
                    int valFromPrevCell = grid[i - 1][k];
                    int costToMove = moveCost[valFromPrevCell][j];
                    
                    int totalCost = prev[k] + costToMove + grid[i][j];
                    curr[j] = min(curr[j], totalCost);
                }
            }
            prev = curr; // Move to next row
        }

        return *min_element(prev.begin(), prev.end());
    }
};

int main() {
    Solution sol;

    int m, n;
    cout << "Enter grid dimensions (rows cols): ";
    if (!(cin >> m >> n)) return 0;

    vector<vector<int>> grid(m, vector<int>(n));
    cout << "Enter grid elements:\n";
    for (int i = 0; i < m; i++) {
        for (int j = 0; j < n; j++) {
            cin >> grid[i][j];
        }
    }

    int totalCells = m * n;
    vector<vector<int>> moveCost(totalCells, vector<int>(n));
    cout << "Enter moveCost matrix (" << totalCells << " rows, " << n << " cols):\n";
    for (int i = 0; i < totalCells; i++) {
        for (int j = 0; j < n; j++) {
            cin >> moveCost[i][j];
        }
    }

    cout << "=========================================================" << endl;
    cout << "--- LEETCODE 2304: MIN PATH COST IN GRID (O(N) SPACE) ---" << endl;
    cout << "=========================================================" << endl;

    int result = sol.minPathCost(grid, moveCost);
    cout << "Minimum Path Cost: " << result << endl;

    return 0;
}