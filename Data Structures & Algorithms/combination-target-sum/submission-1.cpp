class Solution {
public:
    void isSubset(int i, int& n, int& sum, vector<int>& subset, vector<int>& candidates, int target, vector<vector<int>>& ans) {
        if (sum == target) {
            ans.push_back(subset);
            return;
        }

        if (sum > target || i >= n) {
            return;
        }

        // pick candidates[i]
        subset.push_back(candidates[i]);
        sum += candidates[i];
        isSubset(i, n, sum, subset, candidates, target, ans); // allow reuse of same element
        subset.pop_back();
        sum -= candidates[i];

        // move to next element
        isSubset(i+1, n, sum, subset, candidates, target, ans);
    }

    vector<vector<int>> combinationSum(vector<int>& candidates, int target) {
        vector<vector<int>> ans;
        int n = candidates.size();
        int sum = 0;
        vector<int> subset;
        isSubset(0, n, sum, subset, candidates, target, ans); 
        return ans;
    }
};
