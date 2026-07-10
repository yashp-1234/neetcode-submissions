/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode(int x) : val(x), left(NULL), right(NULL) {}
 * };
 */
class Codec {
public:

    string s = "";

    // Encodes a tree to a single string.
    string serialize(TreeNode* root) {
        queue<TreeNode*> q;
        q.push(root);
        TreeNode* temp = root;
        
        while(!q.empty()){
            temp = q.front();
            q.pop();

            if(temp == NULL){
                s += "#,";
                continue;
            }
            else{
                s += to_string(temp->val) + ",";
            }

            q.push(temp->left);
            q.push(temp->right);
        }
        return s;
    }

    // Decodes your encoded data to tree.
    TreeNode* deserialize(string s) {
        queue<TreeNode*> q2; 
        queue<TreeNode*> q3;   

        stringstream ss(s);
        string token;

        while(getline(ss, token, ',')){
            TreeNode* newNode = NULL;
            if(token != "#" && token != ""){
                newNode = new TreeNode(stoi(token));
            }
            q2.push(newNode);
        }

        if(q2.empty()) return NULL;

        TreeNode* head = q2.front();
        q2.pop();
        if(head == NULL) return NULL;

        q3.push(head);

        while(!q3.empty()){
            TreeNode* temp = q3.front();
            q3.pop();

            // left child
            if(!q2.empty()){
                temp->left = q2.front();
                q2.pop();
                if(temp->left != NULL){
                    q3.push(temp->left);
                }
            }

            // right child
            if(!q2.empty()){
                temp->right = q2.front();
                q2.pop();
                if(temp->right != NULL){
                    q3.push(temp->right);
                }
            }
        }

        return head;
    }
};
