#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

class SegmentTree {
private:
    int n;
    vector<int> tree;

    void update(int node, int start, int end, int idx, int val) {
        if (start == end) {
            tree[node] = max(tree[node], val);
            return;
        }
        int mid = start + (end - start) / 2;
        if (idx <= mid) {
            update(2 * node, start, mid, idx, val);
        } else {
            update(2 * node + 1, mid + 1, end, idx, val);
        }
        tree[node] = max(tree[2 * node], tree[2 * node + 1]);
    }

    int query(int node, int start, int end, int l, int r) {
        if (r < start || end < l) return 0; 
        if (l <= start && end <= r) return tree[node]; 

        int mid = start + (end - start) / 2;
        int leftQuery = query(2 * node, start, mid, l, r);
        int rightQuery = query(2 * node + 1, mid + 1, end, l, r);

        return max(leftQuery, rightQuery);
    }

public:
    SegmentTree(int size) {
        this->n = size;
        tree.assign(4 * size, 0);
    }

    void update(int idx, int val) {
        update(1, 1, n, idx, val);
    }

    int query(int l, int r) {
        if (l > r) return 0;
        return query(1, 1, n, l, r);
    }
};

class Solution {
public:
    int lengthOfLIS(vector<int>& nums, int k) {
        int maxVal = 0;
        for (int num : nums) {
            maxVal = max(maxVal, num);
        }

        SegmentTree segTree(maxVal);
        int overallMaxLIS = 0;

        for (int num : nums) {
            int leftBound = max(1, num - k);
            int rightBound = num - 1;

            int prevMax = segTree.query(leftBound, rightBound);
            int currentLIS = prevMax + 1;

            overallMaxLIS = max(overallMaxLIS, currentLIS);

            segTree.update(num, currentLIS);
        }

        return overallMaxLIS;
    }
};

int main() {
    Solution sol;

    vector<int> nums1 = {4, 2, 1, 4, 3, 4, 5, 8, 15};
    int k1 = 3;

    vector<int> nums2 = {7, 4, 5, 1, 8, 12, 4, 7};
    int k2 = 5;

    vector<int> nums3 = {1, 5};
    int k3 = 1;

  

    cout << "Test Case 1: " << sol.lengthOfLIS(nums1, k1) << endl;
    cout << "Test Case 2: " << sol.lengthOfLIS(nums2, k2) << endl;
    cout << "Test Case 3: " << sol.lengthOfLIS(nums3, k3) << endl;

    return 0;
}