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
    int best = INT_MIN;

    int maxPathSum(TreeNode* root) {
        helper(root);
        return best;
    }

    int helper(TreeNode* root) {
        if (!root) return 0;

        // get left/right contributions, but drop negatives (since they reduce the path sum)
        int left = max(0, helper(root->left));
        int right = max(0, helper(root->right));

        // update global best with the "through-root" path
        best = max(best, root->val + left + right);

        // return best branch contribution (single path upward)
        return root->val + max(left, right);
    }
};
