class Solution {
public:
    int networkDelayTime(vector<vector<int>>& times, int n, int k) {
        unordered_map<int, vector<pair<int, int>>> edges;
        for (int i = 0; i < times.size(); i++) {
            edges[times[i][0]].emplace_back(times[i][1], times[i][2]);
        }

        priority_queue<pair<int, int>, vector<pair<int, int>>, greater<>> pq;
        pq.push({0, k});

        set<int> visited;
        int t = 0;

        while (!pq.empty()) {
            auto [w1, n1] = pq.top();
            pq.pop();

            if (visited.count(n1)) continue;
            visited.insert(n1);
            t = w1;

            if (edges.count(n1)) {
                for (const auto& [n2, w2] : edges[n1]) {
                    if (!visited.count(n2)) {
                        pq.push({w1 + w2, n2});
                    }
                }
            }
        }

        return visited.size() == n ? t : -1;
    }
};
