#include <iostream>
#include <vector>

using namespace std;

class Solution {
public:
    int climbStairs(int n) {
        if(n <= 2)
            return n;
            
        vector<int> dp(n + 1);
        dp[0] = 0;
        dp[1] = 1;
        dp[2] = 2;
        
        for(int i = 3; i <= n; i++)
            dp[i] = dp[i - 1] + dp[i - 2];
        
        return dp[n];
    }
};

int main() {
    Solution solver;
    
    int test1 = 2;
    int test2 = 3;
    int test3 = 4;
    
    cout << "Distinct ways for " << test1 << " stairs: " << solver.climbStairs(test1) << endl;
    cout << "Distinct ways for " << test2 << " stairs: " << solver.climbStairs(test2) << endl;
    cout << "Distinct ways for " << test3 << " stairs: " << solver.climbStairs(test3) << endl;
    
    return 0;
}