class Solution {
public:
    vector<vector<int>> merge(vector<vector<int>>& intervals) {
        sort(intervals.begin(), intervals.end());
        int n = intervals.size();
        vector<vector<int>> ans;

        int i = 0;
        while (i < n) {
            if (i < n - 1 && intervals[i][1] < intervals[i + 1][0]) {
                ans.push_back(intervals[i]);
                i++;
            } else {
                int end = intervals[i][1];
                int j = i + 1; 
                while (j < n && intervals[j][0] <= end) {
                    end = max(end, intervals[j][1]);
                    j++;
                }
                ans.push_back({intervals[i][0], end});
                i = j;
            }
        }

        return ans;
    }
};
