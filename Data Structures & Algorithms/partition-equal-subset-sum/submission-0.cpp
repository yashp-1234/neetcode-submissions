class Solution {
    bool findAns(int i, int currsum, int target, vector<int>& nums, vector<vector<int>>& memo) {
    if (currsum == target) return true;
    if (i == nums.size() || currsum > target) return false;
    if (memo[i][currsum] != -1) return memo[i][currsum];
    
    bool include = findAns(i + 1, currsum + nums[i], target, nums, memo);
    bool exclude = findAns(i + 1, currsum, target, nums, memo);
    
    return memo[i][currsum] = include || exclude;
}

public:
    bool canPartition(vector<int>& nums) {
        int sum = accumulate(nums.begin(), nums.end(), 0);
        if (sum % 2 != 0) return false; 
        
        int target = sum / 2;
        vector<vector<int>> memo(nums.size(), vector<int>(target + 1, -1));
        return findAns(0, 0, target, nums, memo);
    }
};
