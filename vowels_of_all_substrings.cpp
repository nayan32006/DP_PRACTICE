#include <iostream>
#include <string>
#include <vector>

using namespace std;

class Solution {
private:
    bool isVowel(char ch) {
        return ch == 'a' || ch == 'e' || ch == 'i' || ch == 'o' || ch == 'u';
    }

public:
    long long countVowels(string word) {
        long long totalVowels = 0;
        long long n = word.length();

        for (long long i = 0; i < n; i++) {
            if (isVowel(word[i])) {
                // Formula: (start choices) * (end choices)
                long long contribution = (i + 1) * (n - i);
                totalVowels += contribution;
            }
        }

        return totalVowels;
    }
};

int main() {
    Solution sol;

    string word1 = "aba";
    string word2 = "abc";
    string word3 = "ltcd";

    cout << "Test Case 1 (\"aba\"): " << sol.countVowels(word1) << endl;
    cout << "Test Case 2 (\"abc\"): " << sol.countVowels(word2) << endl;
    cout << "Test Case 3 (\"ltcd\"): " << sol.countVowels(word3) << endl;

    return 0;
}