class Solution {
public:
    int minCostConnectPoints(vector<vector<int>>& points) {
        int n = points.size();
        int ans = 0;
        set<int> vis;
        //pq <distance, index>
        priority_queue<pair<int, int>, vector<pair<int, int>>, greater<pair<int, int>>> pq;

        pq.push({0,0});

        while(vis.size() != n){
            int dis = pq.top().first;
            int idx = pq.top().second;
            pq.pop();

            if(vis.count(idx) != 0){
                continue;
            }

            vis.insert(idx);
            ans += dis;
            int xi = points[idx][0];
            int yi = points[idx][1];

            for(int j=0; j<n; j++){
                if(vis.count(j) != 0){
                    continue;
                }
                int xj = points[j][0];
                int yj = points[j][1];

                int mnhtd = abs(xi - xj) + abs(yi - yj);
                pq.push({mnhtd, j});
            }
        }
    
    return ans;
    }
};
