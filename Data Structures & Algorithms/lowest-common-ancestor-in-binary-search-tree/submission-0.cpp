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
public:
    TreeNode* lca = nullptr;
    bool found = false;

    TreeNode* checkLca(TreeNode* root, TreeNode* p, TreeNode* q) {
        if (root == NULL) return NULL;

        TreeNode* checkleft = checkLca(root->left, p, q);
        TreeNode* checkright = checkLca(root->right, p, q);

        if (!found && checkleft && checkright) {
            lca = root;
            found = true;
        }

        if (root == p || root == q) {
            if (!found && (checkleft || checkright)) {
                lca = root; 
                found = true;
            }
            return root;
        }

        return (checkleft ? checkleft : checkright);
    }

    TreeNode* lowestCommonAncestor(TreeNode* root, TreeNode* p, TreeNode* q) {
        checkLca(root, p, q);
        return lca;
    }
};
