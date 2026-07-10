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
    int calHeight(TreeNode* root) {
        if (root == NULL) {
            return 0;
        }
        int left = calHeight(root->left);
        int right = calHeight(root->right);
        return 1 + max(left, right);
    }

    int diameterOfBinaryTree(TreeNode* root) {
        if (root == NULL) {
            return 0;
        }

        int ans = 0;
        queue<TreeNode*> q;
        q.push(root);

        while (!q.empty()) {
            TreeNode* temp = q.front(); 
            q.pop();

            if (temp == nullptr) continue; 

            q.push(temp->left);
            q.push(temp->right);

            
            int leftHeight = calHeight(temp->left);
            int rightHeight = calHeight(temp->right);
            ans = max(ans, leftHeight + rightHeight);
        }
        return ans;
    }
};
