class Solution {
public:
    vector<int> findOrder(int numCourses, vector<vector<int>>& prerequisites) {
        vector<vector<int>> adj(numCourses);
        int n = prerequisites.size();
        for (int i = 0; i < n; i++) {
            adj[prerequisites[i][0]].push_back(prerequisites[i][1]);
        }

        vector<int> indegrees(numCourses, 0);
        for (int i = 0; i < n; i++) {
            indegrees[prerequisites[i][1]]++;
        }

        queue<int> q;
        for (int i = 0; i < numCourses; i++) {
            if (indegrees[i] == 0) {
                q.push(i);
            }
        }

        vector<int> ans;
        while (!q.empty()) {
            int node = q.front();
            q.pop();

            ans.push_back(node);

            for (auto it : adj[node]) {
                indegrees[it]--;
                if (indegrees[it] == 0) {
                    q.push(it);
                }
            }
        }

        for(int i=0; i<ans.size()/2; i++){
            swap(ans[i], ans[ans.size()-i-1]);
        }

        if(ans.size() != numCourses){
            vector<int> empty;
            return empty;
        }
        return ans;
    }
};
