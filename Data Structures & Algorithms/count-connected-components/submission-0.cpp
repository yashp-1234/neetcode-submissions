class Solution {
private:

    void makeGraph(int src, vector<vector<int>>& adj, vector<int>& vis){
        vis[src] = 1;
        queue<int> q;
        q.push(src);

        while(!q.empty()){
            int node = q.front();
            q.pop();

            for(auto adjNode : adj[node]){
                if(!vis[adjNode]){
                    vis[adjNode] = 1;
                    q.push(adjNode);
                }
            }
        }
    }

public:
    int countComponents(int n, vector<vector<int>>& edges) {
        vector<vector<int>> adj(n);   

        for (int i = 0; i < edges.size(); i++) {
            adj[edges[i][0]].push_back(edges[i][1]);
            adj[edges[i][1]].push_back(edges[i][0]);
        }

        vector<int> vis(n, 0);
        int ans = 0;

        for(int i=0; i<n; i++){
            if(!vis[i]){
                ans++;
                makeGraph(i, adj, vis);
            }
        }

        return ans;
    }
};
