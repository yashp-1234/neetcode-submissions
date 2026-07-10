class Solution {
public:
    void makeSubset(int i, int& n, vector<int>& subset, vector<int>& nums, vector<vector<int>>& ans){
        if(i == n){
            ans.push_back(subset);
            return;
        }

        //included
        subset.push_back(nums[i]);
        makeSubset(i+1, n, subset, nums, ans);
        subset.pop_back();

        while (i + 1 < n && nums[i] == nums[i + 1]) {
            i++;
        }
        //not included
        makeSubset(i+1, n, subset, nums, ans);

    }
    vector<vector<int>> subsetsWithDup(vector<int>& nums) {
        vector<vector<int>> ans;
        int n = nums.size();
        vector<int> subset;
        sort(nums.begin(), nums.end());
        makeSubset(0, n, subset, nums, ans);
        return ans;
    }
};