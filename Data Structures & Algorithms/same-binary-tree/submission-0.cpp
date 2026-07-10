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
    bool isSameTree(TreeNode* p, TreeNode* q) {

        vector<int> vec1;
        vector<int> vec2;

        queue<TreeNode*> que;

        
        que.push(p);
        TreeNode* node = que.front();

        while(!que.empty()){
            node = que.front();
            que.pop();

            if(node == NULL){
                vec1.push_back(pow(10,4) + 1); 
                continue;
            }

            vec1.push_back(node->val);
            que.push(node->left);
            que.push(node->right);
        }

        
        que.push(q);
        while(!que.empty()){
            node = que.front();
            que.pop();

            if(node == NULL){
                vec2.push_back(pow(10,4) + 1);
                continue;
            }

            vec2.push_back(node->val);
            que.push(node->left);
            que.push(node->right);
        }

        for(int i=0; i<vec2.size(); i++){
            cout<<vec2[i]<<endl;
        }
        return vec1 == vec2;
    }
};
