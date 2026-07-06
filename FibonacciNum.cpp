#include <iostream>

using namespace std;

class Solution {
public:
    int fib(int n) {
        if (n <= 1) return n;
        
        int prev2 = 0; 
        int prev1 = 1; 
        int curr = 0;  
        
        for (int i = 2; i <= n; i++) {
            curr = prev1 + prev2; 
            prev2 = prev1;        
            prev1 = curr;
        }
        
        return curr;
    }
};

int main() {
    Solution solver;
    
    int test1 = 2;
    int test2 = 3;
    int test3 = 4;
    
    cout << "F(" << test1 << ") = " << solver.fib(test1) << endl;
    cout << "F(" << test2 << ") = " << solver.fib(test2) << endl;
    cout << "F(" << test3 << ") = " << solver.fib(test3) << endl;
    
    return 0;
}