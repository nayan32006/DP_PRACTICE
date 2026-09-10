#include <iostream>
#include <vector>
#include <string>

using namespace std;

class Solution {
public:
    vector<string> getLongestSubsequence(vector<string>& words, vector<int>& groups) {
        vector<string> result;
        int n = words.size();
        if (n == 0) return result;

        result.push_back(words[0]);
        int lastGroup = groups[0];

        for (int i = 1; i < n; i++) {
            if (groups[i] != lastGroup) {
                result.push_back(words[i]);
                lastGroup = groups[i]; 
            }
        }

        return result;
    }
};

int main() {
    Solution sol;

    vector<string> words1 = {"e", "a", "b"};
    vector<int> groups1 = {0, 0, 1};
    vector<string> ans1 = sol.getLongestSubsequence(words1, groups1);

    vector<string> words2 = {"a", "b", "c", "d"};
    vector<int> groups2 = {1, 0, 1, 1};
    vector<string> ans2 = sol.getLongestSubsequence(words2, groups2);

    cout << "Test Case 1 Result: ";
    for (const string& w : ans1) cout << w << " ";
    cout << endl;

    cout << "Test Case 2 Result: ";
    for (const string& w : ans2) cout << w << " ";
    cout << endl;

    return 0;
}