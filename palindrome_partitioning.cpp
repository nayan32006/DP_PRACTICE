#include <iostream>
#include <vector>
#include <string>

using namespace std;

class Solution {
private:
    vector<vector<string>> result;
    vector<string> currentPartition;
    vector<vector<bool>> isPalindrome;

    void backtrack(const string& s, int start) {
        if (start == s.length()) {
            result.push_back(currentPartition);
            return;
        }

        for (int end = start; end < s.length(); end++) {
            if (isPalindrome[start][end]) {
                currentPartition.push_back(s.substr(start, end - start + 1));
                backtrack(s, end + 1);
                currentPartition.pop_back(); // Backtrack step
            }
        }
    }

public:
    vector<vector<string>> partition(string s) {
        int n = s.length();
        result.clear();
        currentPartition.clear();

        isPalindrome = vector<vector<bool>>(n, vector<bool>(n, false));
        
        for (int len = 1; len <= n; len++) {
            for (int i = 0; i <= n - len; i++) {
                int j = i + len - 1;
                if (s[i] == s[j]) {
                    if (len <= 2 || isPalindrome[i + 1][j - 1]) {
                        isPalindrome[i][j] = true;
                    }
                }
            }
        }
        backtrack(s, 0);
        return result;
    }
};

int main() {
    Solution sol;
    string s = "aab";

    vector<vector<string>> partitions = sol.partition(s);


    for (const auto& part : partitions) {
        cout << "[ ";
        for (const string& str : part) {
            cout << "\"" << str << "\" ";
        }
        cout << "]" << endl;
    }

    return 0;
}