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
    TreeNode* correct = nullptr;
    void correctPos(TreeNode* root, int val) {
        if (root == nullptr) return;
        correct = root;
        if (root->val > val) {
            return correctPos(root->left, val);
        }
        return correctPos(root->right, val);
    }
public:
    TreeNode* insertIntoBST(TreeNode* root, int val) {
        TreeNode* node = new TreeNode(val);
        if (root == nullptr) return node;
        correctPos(root, val);
        if (correct->val > val) {
            correct->left = node; 
        } else {
            correct->right = node;
        } 
        return root;
    }
};