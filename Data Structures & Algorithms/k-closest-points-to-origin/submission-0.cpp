#include <vector>
#include <queue>
#include <algorithm>
using namespace std;

class Solution {
public:
    vector<vector<int>> kClosest(vector<vector<int>>& points, int k) {
        int n = points.size();
        if (k >= n) return points;

        using P = pair<long long, pair<int,int>>;
        priority_queue<P> pq;

        for (int i = 0; i < n; ++i) {
            long long dx = (long long)points[i][0]; 
            long long dy = (long long)points[i][1];
            long long dist_sq = dx*dx + dy*dy;
            pq.push({dist_sq, {points[i][0], points[i][1]}});
            if ((int)pq.size() > k) pq.pop(); 
        }

        vector<vector<int>> ans;
        ans.reserve(k);
        while (!pq.empty()) {
            auto p = pq.top(); pq.pop();
            ans.push_back({p.second.first, p.second.second});
        }
        reverse(ans.begin(), ans.end()); 
        return ans;
    }
};

