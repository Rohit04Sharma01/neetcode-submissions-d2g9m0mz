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
    TreeNode* utility(vector<int>& preorder, vector<int>& inorder, int& idx, int start, int end) {
        if (start > end) return nullptr;
        TreeNode* n = new TreeNode(preorder[idx++]);
        int i;
        for (i = start; i <= end; i++) {
            if (n->val == inorder[i]) {
                break;
            }
        }
        n->left = utility(preorder, inorder, idx, start, i - 1);
        n->right = utility(preorder, inorder, idx, i + 1, end);
        return n;
    }
public:
    TreeNode* buildTree(vector<int>& preorder, vector<int>& inorder) {
        int idx = 0;
        return utility(preorder, inorder, idx, 0, inorder.size() - 1);
    }
};