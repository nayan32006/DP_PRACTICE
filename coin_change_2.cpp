#include <iostream>
#include <vector>

using namespace std;

class Solution {
public:
    int change(int amount, vector<int>& coins) {
        // dp[i] represents number of combinations to make amount i
        vector<unsigned int> dp(amount + 1, 0);
        
        // Base case: 1 way to make amount 0
        dp[0] = 1;

        // Outer loop for coins ensures unique combinations
        for (int coin : coins) {
            for (int i = coin; i <= amount; ++i) {
                dp[i] += dp[i - coin];
            }
        }

        return dp[amount];
    }
};

int main() {
    int n, amount;
    cout << "सिक्कों की संख्या (Number of coins) दर्ज करें: ";
    if (!(cin >> n) || n <= 0) return 0;

    vector<int> coins(n);
    cout << "सिक्कों के मान (Coin denominations) दर्ज करें: ";
    for (int i = 0; i < n; ++i) {
        cin >> coins[i];
    }

    cout << "Total Amount दर्ज करें: ";
    cin >> amount;

    Solution sol;
    int result = sol.change(amount, coins);

    cout << "\nराशि " << amount << " बनाने के कुल तरीके (Total Combinations): " << result << endl;

    return 0;
}