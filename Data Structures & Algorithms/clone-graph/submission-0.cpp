/*
// Definition for a Node.
class Node {
public:
    int val;
    vector<Node*> neighbors;
    Node() {
        val = 0;
        neighbors = vector<Node*>();
    }
    Node(int _val) {
        val = _val;
        neighbors = vector<Node*>();
    }
    Node(int _val, vector<Node*> _neighbors) {
        val = _val;
        neighbors = _neighbors;
    }
};
*/

class Solution {
public:
    Node* cloneGraph(Node* node) {

        if(node == NULL){
            return NULL;
        }

        queue<Node*> q;
        q.push(node);
        map<Node*, Node*> mp;

        set<Node*> vis;

        Node* head = new Node(node->val);
        mp[node] = head;

        while(!q.empty()){
            Node* temp = q.front();
            vis.insert(temp);
            q.pop();

            int n = temp->neighbors.size();
            for(int i=0; i<n; i++){
                if(mp.find(temp->neighbors[i]) == mp.end()){
                    mp[temp->neighbors[i]] = new Node(temp->neighbors[i]->val);
                }
                if(vis.find(temp->neighbors[i]) == vis.end()){
                    q.push(temp->neighbors[i]);
                }
            }

        }

        for(auto& it: mp){
            Node* orig = it.first;
            Node* clone = it.second;
            for(Node* nei : orig->neighbors){
                clone->neighbors.push_back(mp[nei]);
            }
        }

        return head;
    }
};