#include <iostream>
#include <vector>

using namespace std;

class Solution {
public:
    vector<vector<int>> generate(int numRows) {
        vector<vector<int>> triangle;

        for (int i = 0; i < numRows; i++) {
            vector<int> row(i + 1, 1);

            for (int j = 1; j < i; j++) {
                row[j] = triangle[i - 1][j - 1] + triangle[i - 1][j];
            }

            triangle.push_back(row);
        }

        return triangle;
    }
};

int main() {
    Solution sol;

    // Test Case 1: numRows = 5
    int numRows1 = 5;
    vector<vector<int>> res1 = sol.generate(numRows1);

    // Test Case 2: numRows = 1
    int numRows2 = 1;
    vector<vector<int>> res2 = sol.generate(numRows2);

    cout << "=========================================================" << endl;
    cout << "--- LEETCODE 118: PASCAL'S TRIANGLE (DP APPROACH) ---" << endl;
    cout << "=========================================================" << endl;

    cout << "Test Case 1 (numRows = 5):" << endl;
    for (const auto& row : res1) {
        cout << "[ ";
        for (int val : row) {
            cout << val << " ";
        }
        cout << "]" << endl;
    }

    cout << "\nTest Case 2 (numRows = 1):" << endl;
    for (const auto& row : res2) {
        cout << "[ ";
        for (int val : row) {
            cout << val << " ";
        }
        cout << "]" << endl;
    }

    return 0;
}