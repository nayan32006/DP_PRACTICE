#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

// Definition for a binary tree node.
struct TreeNode {
    int val;
    TreeNode *left;
    TreeNode *right;
    TreeNode(int x) : val(x), left(NULL), right(NULL) {}
};

class Solution {
public:
    pair<int, int> helper(TreeNode* root) {
        if (root == nullptr) {
            return {0, 0};
        }

        pair<int, int> left = helper(root->left);
        pair<int, int> right = helper(root->right);

        int rob = root->val + left.first + right.first;

        int not_rob = max(left.first, left.second) + max(right.first, right.second);

        return {not_rob, rob};
    }

    int rob(TreeNode* root) {
        pair<int, int> result = helper(root);
        return max(result.first, result.second);
    }
};

int main() {
    Solution sol;

    /*
         Constructing Test Tree:
                 3
                / \
               2   3
                \   \
                 3   1
    */
    TreeNode* root = new TreeNode(3);
    root->left = new TreeNode(2);
    root->right = new TreeNode(3);
    root->left->right = new TreeNode(3);
    root->right->right = new TreeNode(1);

    cout << "=========================================================" << endl;
    cout << "--- LEETCODE 337: HOUSE ROBBER III (TREE DP) ---" << endl;
    cout << "=========================================================" << endl;

    int maxMoney = sol.rob(root);
    cout << "Maximum Money Robbed: " << maxMoney << endl;

    return 0;
}