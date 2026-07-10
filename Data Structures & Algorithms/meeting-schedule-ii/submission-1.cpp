class Solution {
public:
    int minMeetingRooms(vector<Interval>& intervals) {
        sort(intervals.begin(), intervals.end(), [](auto& a, auto& b){
            return a.start < b.start;
        });
        
        int ans = 0;
        int n = intervals.size();
        priority_queue<int, vector<int>, greater<int>> pq; 

        for(int i=0; i<n; i++){
            if(!pq.empty() && pq.top() <= intervals[i].start){
                pq.pop();
            }
            pq.push(intervals[i].end);
            ans = max(ans, (int)pq.size());
        }

        return ans;
    }
};
