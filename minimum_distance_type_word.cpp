#include <iostream>
#include <vector>
#include <string>
#include <cmath>
#include <algorithm>

using namespace std;

class Solution {
private:
    int getDistance(int a, int b) {
        if (a == 26 || b == 26) return 0; 
        int r1 = a / 6, c1 = a % 6;
        int r2 = b / 6, c2 = b % 6;
        return abs(r1 - r2) + abs(c1 - c2);
    }

public:
    int minimumDistance(string word) {
        int n = word.length();
        
        vector<vector<int>> dp(n, vector<int>(27, 1e9));

        dp[0][26] = 0;

        for (int i = 1; i < n; i++) {
            int curr = word[i] - 'A';
            int prev = word[i - 1] - 'A';

            for (int other = 0; other <= 26; other++) {
                if (dp[i - 1][other] == 1e9) continue;

                int dist1 = getDistance(prev, curr);
                dp[i][other] = min(dp[i][other], dp[i - 1][other] + dist1);

                int dist2 = getDistance(other, curr);
                dp[i][prev] = min(dp[i][prev], dp[i - 1][other] + dist2);
            }
        }

        int minCost = 1e9;
        for (int other = 0; other <= 26; other++) {
            minCost = min(minCost, dp[n - 1][other]);
        }

        return minCost;
    }
};

int main() {
    Solution sol;

    string word1 = "CAKE";
    string word2 = "HAPPY";


    cout << "Min Distance for \"" << word1 << "\": " << sol.minimumDistance(word1) << endl;
    cout << "Min Distance for \"" << word2 << "\": " << sol.minimumDistance(word2) << endl;

    return 0;
}