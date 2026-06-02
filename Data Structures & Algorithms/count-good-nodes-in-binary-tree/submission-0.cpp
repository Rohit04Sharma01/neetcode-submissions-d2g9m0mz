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
public:
    int goodNodes(TreeNode* root, int maxValInPath = -1e7) {
        if (root == NULL) {
            return 0;
        }
        bool res = 0;
        if (root->val >= maxValInPath) {
            res = 1;
            maxValInPath = root->val;
        }
        return res + goodNodes(root->left, maxValInPath) + goodNodes(root->right, maxValInPath);
    }
};