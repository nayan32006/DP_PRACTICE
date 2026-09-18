#include <iostream>
#include <vector>
#include <algorithm>
#include <cmath>

using namespace std;

class Solution {
public:
    long long minimumTotalDistance(vector<int>& robot, vector<vector<int>>& factory) {
        sort(robot.begin(), robot.end());
        sort(factory.begin(), factory.end());

        vector<int> factorySlots;
        for (const auto& f : factory) {
            int position = f[0];
            int capacity = f[1];
            for (int i = 0; i < capacity; i++) {
                factorySlots.push_back(position);
            }
        }

        int n = robot.size();
        int m = factorySlots.size();

        const long long INF = 1e16;

        vector<vector<long long>> dp(n + 1, vector<long long>(m + 1, INF));

        for (int j = 0; j <= m; j++) {
            dp[n][j] = 0;
        }

        for (int i = n - 1; i >= 0; i--) {
            for (int j = m - 1; j >= 0; j--) {
                long long skip = dp[i][j + 1];

                long long assign = abs((long long)robot[i] - factorySlots[j]) + dp[i + 1][j + 1];

                dp[i][j] = min(skip, assign);
            }
        }

        return dp[0][0];
    }
};

int main() {
    Solution sol;

    vector<int> robot1 = {0, 4, 6};
    vector<vector<int>> factory1 = {{2, 2}, {6, 2}};

    vector<int> robot2 = {1, -1};
    vector<vector<int>> factory2 = {{-2, 1}, {2, 1}};


    cout << "Test Case 1: " << sol.minimumTotalDistance(robot1, factory1) << " units" << endl;
    cout << "Test Case 2: " << sol.minimumTotalDistance(robot2, factory2) << " units" << endl;

    return 0;
}