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
    vector<int> rightSideView(TreeNode* root) {
        vector<int> ans;
        if(root == NULL){
            return ans;
        }
        //ans.push_back(root->val);
        queue<TreeNode*> q;
        q.push(root);
        TreeNode* temp = root;
        int x = 0;

        while(!q.empty()){
            
            vector<int> level;
            x = q.size();
            for(int i=0; i<x; i++){
                temp = q.front();
                q.pop();
                if(temp){
                    level.push_back(temp->val);
                    q.push(temp->left);
                    q.push(temp->right);
                }
            }
            // for(int i=0; i<level.size(); i++){
            //     cout<<level[i]<<" ";
            // }
            // cout<<endl;
            if (!level.empty()) {
                int i = level.size() - 1; 
                ans.push_back(level[i]);      
            }
           
        }
        return ans;
    }
};