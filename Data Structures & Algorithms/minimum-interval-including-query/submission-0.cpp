class Solution {
public:
    vector<int> minInterval(vector<vector<int>>& intervals, vector<int>& queries) {
        // Step 1: Sort intervals by start point
        sort(intervals.begin(), intervals.end());

        // Step 2: Store queries with their original indices
        vector<pair<int, int>> qWithIndex;
        for (int i = 0; i < queries.size(); i++) {
            qWithIndex.push_back({queries[i], i});
        }
        sort(qWithIndex.begin(), qWithIndex.end()); // sort queries by value

        // Step 3: Result array
        vector<int> ans(queries.size(), -1);

        // Step 4: Min-heap -> stores pairs {interval length, end point}
        priority_queue<pair<int, int>, vector<pair<int, int>>, greater<>> pq;

        int i = 0; // pointer for intervals

        // Step 5: Process queries in increasing order
        for (auto& [q, idx] : qWithIndex) {
            // Add all intervals whose start <= current query
            while (i < intervals.size() && intervals[i][0] <= q) {
                int start = intervals[i][0];
                int end = intervals[i][1];
                int len = end - start + 1;
                pq.push({len, end});
                i++;
            }

            // Remove intervals that don't cover the query (end < q)
            while (!pq.empty() && pq.top().second < q) {
                pq.pop();
            }

            // If heap not empty, smallest interval length at top
            if (!pq.empty()) {
                ans[idx] = pq.top().first;
            }
        }

        return ans;
    }
};

