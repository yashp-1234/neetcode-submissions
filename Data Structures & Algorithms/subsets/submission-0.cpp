class Solution {
public:
    vector<int> makeSubsets(int i, int& n, vector<int>&subset, vector<int>& nums, vector<vector<int>>& ans){
        if(i == n){
            ans.push_back(subset);
            return subset;
        }

        //considering nums[i]
        subset.push_back(nums[i]);
        makeSubsets(i+1, n, subset, nums, ans);
        subset.pop_back();

        //not considereing nums[i]
        makeSubsets(i+1, n, subset, nums, ans);

        return subset;
    }
    vector<vector<int>> subsets(vector<int>& nums) {
        vector<int> subset;
        vector<vector<int>> ans;
        int n = nums.size();
        makeSubsets(0, n, subset, nums, ans);
        return ans;
    }
};