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
        auto left = utility(root->left);
        auto right = utility(root->right);
        return {1 + max(left.first, right.first), max({left.second, right.second, left.first + right.first})};
    }
public:
    int diameterOfBinaryTree(TreeNode* root) {
        return utility(root).second;
    }
};