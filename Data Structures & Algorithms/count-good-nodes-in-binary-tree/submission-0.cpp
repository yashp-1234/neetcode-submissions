/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode() : val(0), left(nullptr), right(nullptr) {}
 *     TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
 *     TreeNode(int x, TreeNode *left, TreeNode *right) : val(x), left(left),
 * right(right) {}
 * };
 */
class Solution {
public:
    int goodNodes(TreeNode* root) {
        int ans = 0;
        int currmax = root->val;
        if (root == nullptr) {
            return root->val;
        }

        stack<pair<TreeNode*, int>> st;
        st.push({root, currmax});
        TreeNode* current = root;
        while (!st.empty()) {
            current = st.top().first;
            currmax = st.top().second;
            st.pop();

            // Process the current node
            if(current->val >= currmax){
                ans++;
            }
            currmax = max(current->val, currmax);
            
            if (current->right != nullptr) {
                st.push({current->right, currmax});
            }
            if (current->left != nullptr) {
                st.push({current->left, currmax});
            }

            
        }
        return ans;
    }
};