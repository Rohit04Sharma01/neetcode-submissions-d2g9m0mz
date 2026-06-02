/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode() : val(0), left(nullptr), right(nullptr) {}
 *     TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
 *     TreeNode(int x, TreeNode *left, TreeNode *right) : val(x), left(left), right(right) {}
 * };
 */
class Solution {
private:
    void sortedOrder(TreeNode* root, vector<int>& order) {
        if (root == NULL) return;
        sortedOrder(root->left, order);
        order.emplace_back(root->val);
        sortedOrder(root->right, order);
    }
public:
    int kthSmallest(TreeNode* root, int k) {
        vector<int> order;
        sortedOrder(root, order);
        return order[k - 1];
    }
};