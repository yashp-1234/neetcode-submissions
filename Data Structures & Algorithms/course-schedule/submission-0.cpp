class Solution {
public:
    bool canFinish(int numCourses, vector<vector<int>>& prerequisites) {

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

        if (ans.size() == numCourses) {
            return true;
        } else {
            return false;
        }
    }
};
