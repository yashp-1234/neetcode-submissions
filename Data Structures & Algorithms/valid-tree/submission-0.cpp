#include <vector>
#include <queue>
using namespace std;

class Solution {
private:
    bool detectCycle(int src, vector<vector<int>>& adj, vector<int>& vis) {
        vis[src] = 1;
        queue<pair<int, int>> q;   
        q.push({src, -1});

        while (!q.empty()) {
            int node = q.front().first;
            int parent = q.front().second;
            q.pop();

            for (auto adjNode : adj[node]) {
                if (!vis[adjNode]) {
                    vis[adjNode] = 1;
                    q.push({adjNode, node});
                }
                else if (parent != adjNode) {
                    return true;
                }
            }
        }

        return false;
    }

public:
    bool validTree(int n, vector<vector<int>>& edges) {
        vector<vector<int>> adj(n);   

        for (int i = 0; i < edges.size(); i++) {
            adj[edges[i][0]].push_back(edges[i][1]);
            adj[edges[i][1]].push_back(edges[i][0]);
        }

        vector<int> vis(n, 0);
        if (detectCycle(0, adj, vis)) return false;  
        
        for (int i = 0; i < n; i++) {
            if (!vis[i]) return false;
        }

        return true;
    }
};
