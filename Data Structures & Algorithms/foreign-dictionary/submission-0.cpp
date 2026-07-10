class Solution {
private:
    bool dfs(int i, vector<vector<int>>& adj, vector<int>& vis, vector<int>& path, stack<int>& st) {
        vis[i] = 1;
        path[i] = 1;

        for (auto it : adj[i]) {
            if (!vis[it]) {
                if (!dfs(it, adj, vis, path, st)) return false; // cycle below
            } else if (path[it]) {
                return false; // cycle detected
            }
        }

        path[i] = 0;
        st.push(i);
        return true;
    }

public:
    string foreignDictionary(vector<string>& words) {
        int n = words.size();
        vector<vector<int>> adj(26);
        vector<int> used(26, 0);

        // mark used characters
        for (auto &w : words)
            for (char c : w) used[c - 'a'] = 1;

        // build graph
        for (int i = 0; i < n - 1; i++) {
            string s1 = words[i];
            string s2 = words[i + 1];

            int len = min(s1.size(), s2.size());
            int j = 0;
            while (j < len && s1[j] == s2[j]) j++;

            // invalid: "abc" then "ab"
            if (j == len && s1.size() > s2.size()) return "";

            if (j < len) {
                adj[s1[j] - 'a'].push_back(s2[j] - 'a');
            }
        }

        vector<int> vis(26, 0), path(26, 0);
        stack<int> st;

        // DFS for each used char only
        for (int i = 0; i < 26; i++) {
            if (used[i] && !vis[i]) {
                if (!dfs(i, adj, vis, path, st)) return ""; // cycle
            }
        }

        // build answer
        string ans = "";
        while (!st.empty()) {
            int x = st.top(); st.pop();
            if (used[x]) ans.push_back(char(x + 'a'));
        }

        return ans;
    }
};
