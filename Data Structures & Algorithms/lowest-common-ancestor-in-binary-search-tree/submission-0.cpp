/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode(int x) : val(x), left(NULL), right(NULL) {}
 * };
 */

class Solution {
private:
    void utility(TreeNode* root, int target, vector<TreeNode*>& nodePtrList) {
        if (root == nullptr) return;
        nodePtrList.push_back(root);
        if (root->val == target) {
            return;
        }
        else if (root->val > target) {
            return utility(root->left, target, nodePtrList);
        } 
        return utility(root->right, target, nodePtrList);
    }
public:
    TreeNode* lowestCommonAncestor(TreeNode* root, TreeNode* p, TreeNode* q) {
        vector<TreeNode*> nodePtrListP;
        vector<TreeNode*> nodePtrListQ;
        utility(root, p->val, nodePtrListP);
        utility(root, q->val, nodePtrListQ);
        while (nodePtrListP.size() > 0 && nodePtrListQ.size() > 0) {
            if (nodePtrListP.back()->val == nodePtrListQ.back()->val) {
                return nodePtrListP.back();
            } else if (nodePtrListP.size() <= nodePtrListQ.size()) {
                nodePtrListQ.pop_back();
            } else {
                nodePtrListP.pop_back();
            }
        }
        return nullptr;
    }
};