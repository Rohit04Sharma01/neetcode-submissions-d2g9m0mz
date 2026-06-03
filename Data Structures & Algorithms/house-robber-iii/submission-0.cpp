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
    pair<int, int> utility(TreeNode* root) {
        if (root == nullptr) return {0, 0};
        auto left = utility(root -> left);
        auto right = utility(root -> right);
        int rob = root -> val + left.second + right.second;
        int notrob = max(left.first, left.second) + max(right.first, right.second);
        return {rob, notrob};
    }
public:
    int rob(TreeNode* root) {
        auto res = utility(root);
        return max(res.first, res.second);
    }
};