class Solution {
public:
    void isSubset(int i, int n, vector<int>& subset, vector<int>& candidates, int target, vector<vector<int>>& ans) {
        if(target == 0){
            ans.push_back(subset); // found a valid combination
            return;
        }
        if(target < 0 || i >= n) return;

        for(int j = i; j < n; j++){
            // skip duplicates
            if(j > i && candidates[j] == candidates[j-1]) continue;

            subset.push_back(candidates[j]);
            isSubset(j + 1, n, subset, candidates, target - candidates[j], ans); // move to next index
            subset.pop_back(); // backtrack
        }
    }

    vector<vector<int>> combinationSum2(vector<int>& candidates, int target) {
        vector<vector<int>> ans;
        vector<int> subset;
        sort(candidates.begin(), candidates.end()); // important for skipping duplicates
        isSubset(0, candidates.size(), subset, candidates, target, ans);
        return ans;
    }
};
